import select
import socket
import sys
import time


class Server:
    def __init__(self, port):
        self.port = port
        self.inputs, self.outputs = [], []
        self.proxies, self.messages = {}, {}

    def run(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server.bind(('', self.port))
        server.setblocking(False)
        server.listen(5)

        self.inputs.append(server)
        while True:
            readable, writable, exceptional = select.select(
                self.inputs, self.outputs, self.inputs
            )

            for sock in readable:
                if sock is server:
                    self.accept(sock)
                elif sock in self.proxies:
                    self.read_proxy_msg(sock)
                else:
                    self.read(sock)

            for sock in writable:
                msg = self.messages[sock]
                print('sending: {}'.format(msg))
                sock.send(msg.encode('utf-8'))
                self.clean_socket(sock)

            for sock in exceptional:
                print('Some exception in {}'.format(sock))
                self.clean_socket(sock)

        server.close()

    def accept(self, sock):
        conn, addr = sock.accept()
        conn.setblocking(False)
        print('connected: {}'.format(addr))

        self.inputs.append(conn)

    def read(self, sock):
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

        self.messages[sock] = resp
        if sock not in self.outputs:
            self.outputs.append(sock)

    def send_ping(self, host, port, msg, sock):
        conn = socket.socket(
            socket.AF_INET, socket.SOCK_STREAM
        )
        conn.connect((host, int(port)))
        conn.sendall(msg.encode('utf-8'))

        self.proxies[conn] = sock
        self.inputs.append(conn)

    def read_proxy_msg(self, dest_sock):
        msg = dest_sock.recv(1024).decode('utf-8')
        print('received msg from ping: {}'.format(msg))

        orig_sock = self.proxies[dest_sock]
        self.messages[orig_sock] = msg
        if orig_sock not in self.outputs:
            self.outputs.append(orig_sock)

        del self.proxies[dest_sock]
        self.clean_socket(dest_sock)

    def clean_socket(self, sock):
        if sock in self.outputs:
            self.outputs.remove(sock)
        if sock in self.inputs:
            self.inputs.remove(sock)
        if sock in self.messages:
            del self.messages[sock]
        sock.close()


if __name__ == '__main__':
    Server(int(sys.argv[1])).run()
