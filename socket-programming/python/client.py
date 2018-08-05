import socket
import sys


class Client:
    def __init__(self, host, port):
        self.host, self.port = host, port

    def send(self, msg):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
            client.connect((self.host, self.port))
            client.sendall(msg.encode('utf-8'))

            resp = client.recv(1024).decode('utf-8')

        return resp


if __name__ == '__main__':
    host, port = sys.argv[1:3]

    client = Client(host, int(port))
    print(client.send(' '.join(sys.argv[3:])))
