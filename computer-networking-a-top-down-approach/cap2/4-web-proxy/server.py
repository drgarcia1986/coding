import sys, socket, threading
from collections import namedtuple


Request = namedtuple(
    'Request',
    ['method', 'path', 'protocol', 'headers', 'body']
)


class ProxyServer:

    def __init__(self, port):
        self.cache = {}
        self.cache_lock = threading.Lock()
        self.port = port
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def stop(self):
        self.server.close()

    def run(self):
        self.server.bind(('', self.port))
        self.server.listen(5)
        print('Server is UP and Running on port {}!'.format(self.port))

        while True:
            connection, _ = self.server.accept()
            threading.Thread(
                target=self._read_client, args=(connection,)
            ).start()

    def _read_client(self, connection):
            req = self._read_request(connection)
            cache_key = '{}/{}'.format(req.path, req.headers['Host'])
            with self.cache_lock:
                content = self.cache.get(cache_key)

            if content:
                connection.send(content.encode('utf-8'))
                connection.close()
                return

            response = self._perform_request(req)
            with self.cache_lock:
                self.cache[cache_key] = response

            connection.send(response.encode('utf-8'))
            connection.close()

    def _read_request(self, conn):
        msg = conn.recv(1024).decode('utf-8')
        msg = msg.split('\r\n')

        method, path, protocol = msg[0].split()
        headers = {}
        for header in msg[1:]:
            if not header:
                break
            key, value = header.split(':')
            headers[key.strip()] = value.strip()

        body = msg[-1]

        if 'Proxy-Connection' in headers:
            del headers['Proxy-Connection']

        return Request(
            method=method,
            path=path,
            protocol=protocol,
            headers=headers,
            body=body
        )

    def _perform_request(self, req):
        conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        conn.connect((req.headers['Host'], 80))
        conn.send(
            '{r.method} {r.path} {r.protocol}\r\n'.format(r=req).encode('utf-8')
        )
        for header, value in req.headers.items():
            conn.send('{}: {}\r\n'.format(header, value).encode('utf-8'))

        conn.send('\r\n'.encode('utf-8'))
        conn.send(req.body.encode('utf-8'))
        conn.send('\r\n'.encode('utf-8'))

        resp = ''
        conn.settimeout(3)
        try:
            buf = conn.recv(4096)
            while len(buf) > 0:
                resp += '{}'.format(buf)
                buf = conn.recv(4096)
        except socket.timeout:
            pass

        conn.close()
        return resp


if __name__ == '__main__':
    proxy = ProxyServer(int(sys.argv[1]))
    try:
        proxy.run()
    except KeyboardInterrupt:
        proxy.stop()
    print('Bye!')
