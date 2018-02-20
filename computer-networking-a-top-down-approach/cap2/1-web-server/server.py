import os, socket, sys


class Server:

    def __init__(self, port):
        self.port = port
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind(('', port))
        self.server.listen(1)

    def run(self):
        print('Server is UP and Running on port {}!'.format(self.port))
        while True:
            connection, addr = self.server.accept()
            print('connected with {}'.format(addr))

            msg = connection.recv(1024).decode('utf-8')
            msg = msg.split('\r\n')
            if len(msg) < 1:
                self._send_bad_request(connection, 'Invalid Message Format')
                continue

            method, path, _ = msg[0].split()
            if method != 'GET':
                self._send_method_not_allowed(connection, 'Only supports GET')
                continue

            try:
                content = self._get_file(path)
            except IOError:
                self._send_not_found(connection, 'Not Found')
            else:
                self._send_ok(connection, content)

    def stop(self):
        self.server.close()

    def _send_response_and_close(self, conn, code, reason, msg):
        conn.send('HTTP/1.1 {} {}\r\n'.format(code, reason).encode('utf-8'))
        conn.send('Connection: close\r\n'.encode('utf-8'))
        conn.send('Server: drgarcia1986/coding\r\n'.encode('utf-8'))
        conn.send('Content-Length: {}\r\n'.format(len(msg)+1).encode('utf-8'))
        conn.send('Content-Type: text/plain\r\n'.encode('utf-8'))
        conn.send('\n\r'.encode('utf-8'))
        conn.send(msg.encode('utf-8'))
        conn.close()

    def _send_bad_request(self, conn, msg):
        self._send_response_and_close(conn, 400, 'Bad Request', msg)

    def _send_http_version_not_supported(self, conn, msg):
        self._send_response_and_close(
            conn, 505, 'HTTP Version Not Suported', msg
        )

    def _send_method_not_allowed(self, conn, msg):
        self._send_response_and_close(conn, 405, 'Method Not Allowed', msg)

    def _send_not_found(self, conn, msg):
        self._send_response_and_close(conn, 404, 'Not Found', msg)

    def _send_ok(self, conn, msg):
        self._send_response_and_close(conn, 200, 'Ok', msg)

    def _get_file(self, path):
        filepath = '{}{}'.format(os.getcwd(), path)
        with open(filepath, 'r') as f:
            return f.read()


if __name__ == '__main__':
    server = Server(int(sys.argv[1]))
    try:
        server.run()
    except KeyboardInterrupt:
        server.stop()
    print('Bye!')
