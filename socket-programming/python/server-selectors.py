import selectors
import socket
import sys
import time
from collections import namedtuple


Event = namedtuple('Event', 'callback data')


class Server:
    def __init__(self, port):
        self.port = port

        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        self.selector = selectors.DefaultSelector()

    def run(self):
        self.server.bind(('', self.port))
        self.server.setblocking(False)
        self.server.listen(5)

        accept = Event(self.accept, None)
        self.selector.register(self.server, selectors.EVENT_READ, accept)

        try:
            while True:
                events = self.selector.select()
                for key, mask in events:
                    callback = key.data.callback
                    callback(key.fileobj, key.data.data)
        except Exception as e:
            print('Exception running loop: {}'.format(e))

        self.selector.unregister(self.server)
        self.server.close()
        self.selector.close()

    def accept(self, server, data=None):
        conn, addr = server.accept()
        conn.setblocking(False)
        print('connected: {}'.format(addr))

        read = Event(self.read, None)
        self.selector.register(conn, selectors.EVENT_READ, read)

    def read(self, sock, data=None):
        raw_msg = sock.recv(1024).decode('utf-8')
        print('received: {}'.format(raw_msg))

        command, *msg = raw_msg.split(':')
        msg = ':'.join(msg)

        if command.upper() == 'PING':
            host, port, msg = msg.split('-')
            self.send_ping(host, port, msg, sock)
            return

        resp = 'Unknow Protocol'
        if command.upper() == 'ECHO':
            resp = msg
        elif command.upper() == 'SLEEP':
            time.sleep(float(msg))
            resp = 'slept'

        send = Event(self.send, resp)
        self.selector.modify(sock, selectors.EVENT_WRITE, send)

    def send_ping(self, host, port, msg, sock):
        conn = socket.socket(
            socket.AF_INET, socket.SOCK_STREAM
        )
        conn.connect((host, int(port)))
        conn.sendall(msg.encode('utf-8'))

        read = Event(self.read_proxy_msg, sock)
        self.selector.register(conn, selectors.EVENT_READ, read)

    def read_proxy_msg(self, sock, sock_orig):
        msg = sock.recv(1024).decode('utf-8')
        print('received msg from ping: {}'.format(msg))
        self.selector.unregister(sock)
        sock.close()

        send = Event(self.send, msg)
        self.selector.modify(sock_orig, selectors.EVENT_WRITE, send)

    def send(self, sock, msg):
        print('sending: {}'.format(msg))
        sock.send(msg.encode('utf-8'))
        self.selector.unregister(sock)
        sock.close()


if __name__ == '__main__':
    Server(int(sys.argv[1])).run()
