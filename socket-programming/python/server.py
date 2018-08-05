import socket
import sys
import time


class Server:
    def __init__(self, port):
        self.port = port

    def run(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server.bind(('', self.port))
        server.listen(1)

        while True:
            connection, addr = server.accept()
            print('connected: {}'.format(addr))

            with connection as conn:
                raw_msg = conn.recv(1024).decode('utf-8')
                print('received: {}'.format(raw_msg))

                command, msg = raw_msg.split(':')
                resp = 'Unknow Protocol'
                if command.upper() == 'ECHO':
                    resp = msg
                elif command.upper() == 'SLEEP':
                    time.sleep(float(msg))
                    resp = 'slept'

                print('sending: {}'.format(resp))
                conn.send(resp.encode('utf-8'))


if __name__ == '__main__':
    Server(int(sys.argv[1])).run()
