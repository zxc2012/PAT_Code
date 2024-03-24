# 1 Abstraction
## Basic

Internet protocol stack
- Application: supporting network applications
- Transport: process-process data transfer
- Network: routing of datagrams from source to destination
- Data Link: data transfer between neighboring network elements
- Physical: bits to/from signals “on the wire”
## Application Layer
### HTTP

*hypertext transfer protocol*

HTTP uses TCP:

1. Resolve the server to IP address (DNS)
2. Set up TCP connection to the server
3. Send HTTP request for the page
4. Await HTTP response for the page
5. Execute and fetch embedded resources, render
6. Clean up any idle TCP connections

HTTP is "stateless": server maintains no information about past client requests

#### HTTP connections: two types

- Non-persistent HTTP: at most one object sent over TCP connection, downloading multiple objects required multiple connections
- Persistent HTTP: multiple objects can be sent over single TCP connection between client, and that server

RTT: Round Travel Time

![20230331210236](https://raw.githubusercontent.com/zxc2012/image/main/20230331210236.png)

Non-persistent HTTP response time =  2RTT+ file transmission  time

Non-persistent HTTP issues:
- requires 2 RTTs per object
- OS overhead for each TCP connection
- browsers often open multiple parallel TCP connections to fetch referenced objects in parallel

Persistent HTTP(HTTP1.1):
- server leaves connection open after sending response
- subsequent HTTP messages  between same client/server sent over open connection
- client sends requests as soon as it encounters a referenced object
- as little as one RTT for all the referenced objects (cutting response time significantly)

#### HTTP 2 and 3

HTTP1.1: introduced multiple, pipelined GETs over single TCP connection
- server responds in-order (FCFS) to GET requests
- with FCFS, small object may have to wait for transmission  (head-of-line (HOL) blocking) behind large object(s)
- loss recovery (retransmitting lost TCP segments) stalls object transmission

HTTP/2: decrease delay in multi-object HTTP requests
- methods, status codes, most header fields unchanged from HTTP 1.1
- transmission order of requested objects based on client-specified object priority (not necessarily FCFS)
- push unrequested objects to client
- divide objects into frames, schedule frames to mitigate HOL blocking

HTTP/2 over single TCP connection means:
- recovery from packet loss still stalls all object transmissions
- no security over vanilla TCP connection

HTTP/3: adds security, per object error- and congestion-control (more pipelining) over UDP

#### Primary Methods

- GET gets data
- POST creates data
- PUT modifies data
- DELETE deletes data

Status Code

|Code|Meaning|Examples|
|-|-|-|
|1xx| Information |100 = server agrees to handle client's request|
|2xx |Success |200 = request succeeded; 204 = no content present|
|3xx| Redirection| 301 = page moved; 304 = cached page still valid|
|4xx| Client error| 403 = forbidden page; 404 = page not found|
|5xx| Server error| 500 = internal server error; 503 = try again later error|

URL

*uniform resource locator*

```html
<protocol>://<hostname>/<path>？<query>#<fragment_id>
```
*fragment_id* points to the HTML element with the given ID

## Transport Layer

- TCP: Transmission Control Protocol
    - reliable, in-order delivery
    - flow control: sender won’t overwhelm receiver 
    - congestion control: throttle sender when network overloaded 
    - connection-oriented: handshaking initializes sender, receiver state before data exchange
- UDP: User Datagram Protocol
    - unreliable, unordered delivery
    - connectionless: no handshaking between UDP sender, receiver
- services not available:  delay guarantees, bandwidth guarantees

### Multiplexing and demultiplexing

Multiplexing, demultiplexing: based on segment, datagram header field values
- TCP: demultiplexing using 4-tuple: source and destination IP addresses, and port numbers
- UDP: demultiplexing using destination port number (only)

### TCP

Sequence numbers: byte stream "number" of first byte in segment’s data

Acknowledgements: seq # of next byte expected from other side or cumulative ACK

#### Establishing and Closing Connection

Problems with 2-way handshake: 

1. half open connection(no client)

    ![20230330221212](https://raw.githubusercontent.com/zxc2012/image/main/20230330221212.png)

2. duplicate data accepted

    ![20230330221421](https://raw.githubusercontent.com/zxc2012/image/main/20230330221421.png)

3-way handshake

Client sends a SYN to Server
Server returns a SYN acknowledgment (SYN ACK)
Client sends an ACK to acknowledge the SYN ACK

![20230330223312](https://raw.githubusercontent.com/zxc2012/image/main/20230330223312.png)

4-way handshake

- client, server each close their side of connection
    - send TCP segment with FIN bit = 1
- respond to received FIN with ACK
    - on receiving FIN, ACK can be combined with own FIN
- simultaneous FIN exchanges can be handled

![20230330223828](https://raw.githubusercontent.com/zxc2012/image/main/20230330223828.png)

![20230330225014](https://raw.githubusercontent.com/zxc2012/image/main/20230330225014.png)