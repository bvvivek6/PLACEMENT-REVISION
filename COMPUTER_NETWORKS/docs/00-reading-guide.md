# Reading guide

This repo is written to be read in a straight line, but you can also jump around.

## Recommended order

1. OSI/TCP-IP mental model
2. Ethernet + ARP (how you reach the _first hop_)
3. IP + subnetting + ICMP + NAT (how you reach the _destination network_)
4. TCP/UDP (how apps get reliable/unreliable delivery)
5. DNS/HTTP/TLS (how most web apps actually talk)
6. Routing/switching (how networks scale)
7. Security + performance + troubleshooting

## How to study for interviews

- After each doc, answer the interview questions at the end **out loud**.
- Practice drawing flows:
  - “User opens `https://google.com`”
  - “Container connects to database across VPC”
  - “VPN user can’t access internal site”

## Symbols and conventions

- **Client**: the machine initiating a connection
- **Server**: the machine receiving a connection
- **5‑tuple**: (src IP, src port, dst IP, dst port, protocol)
- **RTT**: round-trip time
- **MTU/MSS**: max transmission unit / max segment size
