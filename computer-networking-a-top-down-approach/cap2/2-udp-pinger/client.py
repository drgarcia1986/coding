import socket, sys, time


class UDPPinger:

    def ping(self, host, port):
        transmited, received, loss = 0, 0, 0

        cli = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        cli.settimeout(1)

        times = []
        print('PING {}:{}'.format(host, port))
        for i in range(1, 11):
            start = time.process_time()
            cli.sendto(b'ping', (host, port))
            transmited += 1

            try:
                resp = cli.recv(1024)
            except socket.timeout:
                loss += 1
                print('Request timeout for seq {}'.format(i))
            else:
                received += 1
                done = time.process_time()
                print('{} bytes received from {}, time={} ms'.format(
                    len(resp), host, done
                ))
                times.append(done)

        print('{} transmitted, {} received, {} loss'.format(
            transmited, received, loss
        ))

        if len(times) > 0:
            print('round-trip min/avg/max = {}/{}/{}'.format(
                min(times), max(times), sum(times) / len(times)
            ))
        cli.close()


if __name__ == '__main__':
    UDPPinger().ping(sys.argv[1], int(sys.argv[2]))
