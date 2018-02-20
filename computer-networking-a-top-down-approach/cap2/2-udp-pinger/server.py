import random
import socket


server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('', 12000))

print('Server is UP and Running!')
while True:
    try:
        _, cli_addr = server.recvfrom(2048)
        if random.randint(0, 10) >= 4:
            server.sendto(b'pong', cli_addr)
    except KeyboardInterrupt:
        break

server.close()
print('Bye!')
