import select
import socket
import sys
import time


class Server:
    def __init__(self, port):
        self.port = port
        self.connections, self.messages, self.proxies = {}, {}, {}

        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        self.epoll = select.epoll()
        self.epoll.register(self.server.fileno(), select.EPOLLIN)

    def run(self):
        self.server.bind(('', self.port))
        self.server.setblocking(False)
        self.server.listen(5)

        while True:
            for fd, event in self.epoll.poll(1):
                if fd == self.server.fileno():
                    self.accept()
                elif event & select.EPOLLIN:
                    if fd in self.proxies:
                        self.read_proxy_msg(fd)
                    else:
                        self.read(fd)
                elif event & select.EPOLLOUT:
                    self.send(fd)

        self.epoll.unregister(self.server.fileno())
        self.epoll.close()
        self.server.close()

    def accept(self):
        conn, addr = self.server.accept()
        conn.setblocking(False)
        print('connected: {}'.format(addr))

        self.epoll.register(conn.fileno(), select.EPOLLIN)
        self.connections[conn.fileno()] = conn

    def read(self, fd):
        sock = self.connections[fd]
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

        self.messages[fd] = resp
        self.epoll.modify(fd, select.EPOLLOUT)

    def send_ping(self, host, port, msg, sock):
        conn = socket.socket(
            socket.AF_INET, socket.SOCK_STREAM
        )
        conn.connect((host, int(port)))
        conn.sendall(msg.encode('utf-8'))

        self.proxies[conn.fileno()] = (sock, conn)
        self.epoll.register(conn.fileno(), select.EPOLLIN)

    def read_proxy_msg(self, fd):
        orig_sock, dest_sock = self.proxies[fd]
        msg = dest_sock.recv(1024).decode('utf-8')
        print('received msg from ping: {}'.format(msg))

        self.messages[orig_sock.fileno()] = msg
        self.epoll.modify(orig_sock.fileno(), select.EPOLLOUT)

        del self.proxies[fd]
        dest_sock.close()

    def send(self, fd):
        msg = self.messages[fd]
        sock = self.connections[fd]
        print('sending: {}'.format(msg))
        sock.send(msg.encode('utf-8'))
        self.clean_socket(fd)

    def clean_socket(self, fd):
        if fd in self.connections:
            self.epoll.unregister(fd)
            self.connections[fd].close()
            del self.connections[fd]
        if fd in self.messages:
            del self.messages[fd]


if __name__ == '__main__':
    Server(int(sys.argv[1])).run()
