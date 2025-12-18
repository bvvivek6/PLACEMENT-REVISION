# Networking Interview Cheat Sheet

Use this for quick revision.

## 1) OSI vs TCP/IP (what goes where)

- **OSI**: Physical → Data Link → Network → Transport → Session → Presentation → Application
- **TCP/IP (practical)**: Link → Internet → Transport → Application

Useful mapping:

- Link: Ethernet, Wi‑Fi, ARP, VLANs
- Internet: IP, ICMP, routing
- Transport: TCP, UDP
- Application: DNS, HTTP, TLS, SMTP, SSH

## 2) Packet journey (web request)

When you open `https://example.com`:

1. **DNS** resolves `example.com` → IP (often multiple IPs)
2. Client chooses a **route** (default gateway for non-local IPs)
3. Client uses **ARP** to learn the gateway’s MAC (first hop)
4. Client sends IP packets to destination IP (frame dest MAC = gateway)
5. **TCP 3-way handshake** with server (SYN, SYN-ACK, ACK)
6. **TLS handshake** (cert verification, key agreement)
7. **HTTP request/response** over the encrypted TCP connection

## 3) ARP in one line

- ARP maps **IPv4 → MAC** on the local L2 network.
- ARP does **not** cross routers.

Example: if destination IP is not in your subnet, you ARP for the **default gateway**, not for the remote host.

## 4) Subnetting quick rules

- `/24` → 256 IPs, 254 usable (typical)
- `/25` → 128 IPs, 126 usable
- `/26` → 64 IPs, 62 usable
- `/27` → 32 IPs, 30 usable
- `/28` → 16 IPs, 14 usable
- `/29` → 8 IPs, 6 usable
- `/30` → 4 IPs, 2 usable (p2p)

Host count formula: $2^{(32-\text{prefix})} - 2$ (IPv4, traditional)

## 5) TCP vs UDP

**UDP**

- Message-oriented, no handshake, no reliability
- Useful for: DNS (classic), VoIP, gaming, telemetry, QUIC transport (UDP-based)

**TCP**

- Reliable byte stream
- In-order delivery, retransmissions, flow control (receiver window)
- Congestion control (sender adapts to network)

## 6) TCP handshake & teardown

- Handshake: SYN → SYN-ACK → ACK
- Teardown: FIN/ACK exchanges (or RST for abrupt)

Why it matters:

- SYN flood targets handshake state
- Latency-sensitive apps pay at least 1 RTT before sending app data (more with TLS)

## 7) NAT (what it does)

- **SNAT** (source NAT): changes source IP/port for outbound traffic (home router)
- **DNAT** (destination NAT): changes destination to forward inbound traffic (port forwarding)

Key point: NAT devices track flows using the **5‑tuple**.

## 8) DNS basics

- Records: A/AAAA, CNAME, MX, TXT, NS
- Resolution: stub resolver → recursive resolver → root → TLD → authoritative
- Caching is controlled by TTL.

Common issues:

- Wrong CNAME chain, stale cache, split-horizon DNS

## 9) HTTP basics

- Methods: GET, POST, PUT, PATCH, DELETE
- Status codes: 2xx success, 3xx redirect, 4xx client error, 5xx server error
- HTTP/1.1 uses TCP; HTTP/2 multiplexes streams over one TCP; HTTP/3 runs over QUIC (UDP).

## 10) TLS basics

- Server proves identity with a certificate (chain to a trusted CA)
- Handshake negotiates ciphers and keys
- After handshake: symmetric encryption for data

Common failures:

- Time skew, wrong hostname (SNI), missing intermediate cert

## 11) ICMP (ping/traceroute)

- Used for errors and diagnostics: echo request/reply, time exceeded, fragmentation needed
- Many networks rate-limit or block some ICMP types.

## 12) Troubleshooting checklist

1. Is it **DNS**? (`nslookup`, `dig`)
2. Is it **routing**? (wrong gateway/VPN route)
3. Is it **reachability**? (`ping`, `tracert`/`traceroute`)
4. Is it **port/app**? (`curl`, `telnet`/`nc`)
5. Is it **TLS**? (`curl -v`, cert details)
6. Is it **firewall/NACL/SG**? (rules + stateful vs stateless)

## Mini interview prompts

- Why does TCP need 3-way handshake?
- Difference between congestion control and flow control?
- What happens when you type a URL and press Enter?
- Why does traceroute show multiple hops?
- What’s the difference between a hub, switch, and router?
