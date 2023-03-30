# 1 Abstraction
## Basic

Internet protocol stack
- Application: supporting network applications
- Transport: process-process data transfer
- Network: routing of datagrams from source to destination
- Data Link: data transfer between neighboring network elements
- Physical: bits to/from signals “on the wire”

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