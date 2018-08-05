# Socket Programming
Some fun with sockets.

## Client
A regular client that send a TCP/IPv4 message to a server.
Usage example:
```
$ python3 client.py 192.168.0.20 8080 ECHO:foo
foo
```
### Implementation
* [Python](./python/client.py)

## Server
A regular server that listen to TCP/IPv4 connection and process
received messages based on a simple protocol

### Protocol
| Message | Args | Example | Response |
| --- | --- | --- | --- |
| ECHO | any string | ECHO:foo | foo |
| SLEEP | any float | SLEEP:1 | slept |

> The `SLEEP` message causes a blocking delay in the server.

### Implementation
* [Python](./python/server.py)

## Non Blocking Single Thread Server
A socket server that listen to TCP/IPv4 connection and process
received messages based on a simple protocol without blocking
server to receive and process new messages.

### Protocol
| Message | Args | Example | Response |
| --- | --- | --- | --- |
| ECHO | any string | ECHO:foo | foo |
| SLEEP | any float | SLEEP:1 | slept |
| PING | host, port and message to send to another server | PING:192.168.0.22-8080-ECHO:foo | foo |

> The `SLEEP` message causes a blocking delay in the server, but `PING` message not.

These server use Unix I/O multiplexing primitives to
monitoring file descriptiors ready for inputs and outputs.

### Implementation
* **[select](http://man7.org/linux/man-pages/man2/select.2.html)**
    - [Python](./python/server-select.py)
* **[epoll](http://man7.org/linux/man-pages/man7/epoll.7.html)**
    - [Python](./python/server-epoll.py)
* **[selectors](https://docs.python.org/3/library/selectors.html)** (python high-level I/O multiplexing interface)
    - [Python](./python/server-selectors.py)
