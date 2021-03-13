# Linux基础指令

## Linux命令行结构
>$ command [[-]*option(s)*] [*option argument(s)*] [*command argument(s)*]
## 基本指令
1.Linux三大查询命令man,info,--help
>man ls
>man passwd
>info pwd
>who --help
>
man page:manual page
2.uname(short for unix name)
parameter:
-n(-nodename)
-p(-processor)
3.*cal* command is a calendar command in Linux which is used to see the calendar of a specific month or a whole year.
4.
|Command|Interpretation|
|-|-|
|pwd|print working directory|
|mkdir|make directory|
|cd|change directory|
|rmdir|remove(empty)directory|

## Linux网络分析工具
### Ping
> ping, ping6 - send ICMP ECHO_REQUEST to network hosts
```Shell
ping [-LRUbdfnqrvVaAB] [-c count] [-i interval] [-s packetsize] [-t ttl] [hop ...] destination
```
#### 参数解释
|参数|解释|
|-|-|
|[ -c count]|Stop after sending *count* ECHO_REQUEST packets. |
|[ -i interval]|Wait *interval* seconds between sending each packet.**default:1**|
|[ -s packetsize]|Specifies the number of data bytes to be sent. **default:56 (64 ICMP data bytes=8 bytes of ICMP header data+56)**| 
|[ -t ttl]|Set the IP Time to Live.|
### Traceroute
> traceroute,traceroute6(*or* traceroute -6)print the route packets trace to network host
```Shell
traceroute [...] host [packet_len]
```
#### 参数解释
|参数|解释|
|-|-|
|-4,-6|Explicitly force IPv4 or IPv6 traceouting. If resolving a host name returns both IPv4 and IPv6 addresses, traceroute will use IPv4. |
|-n|Do not try to map IP addresses to host names when displaying them.|
|-p port|For UDP tracing, specifies the destination port base traceroute will use (the destination port number will be incremented by each probe).For ICMP tracing, specifies the initial icmp sequence value (incremented by each probe too).For TCP specifies just the (constant) destination port to connect.| 
|-T|Use TCP SYN for probes|
|-I|Use ICMP ECHO for probes|
|-U|Use UDP to particular destination port for tracerouting (instead of increasing the port per each probe). **default port:53**|
#### Example
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200903113838628.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200903113912107.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)
### Nslookup
>nslookup - query Internet domain name servers
```shell
nslookup [-option] [name | -] [server]
```
#### 参数解释
-option:
-query=hinfo
|hinfo|解释|
|-|-|
|A|ipv4
|AAAA |ipv6|
|CNAME|别名记录|
|MX |邮件服务器记录|