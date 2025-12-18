# Network layer: IP, subnetting, ICMP, NAT

This chapter is about getting packets from one network to another.

## IPv4 addressing and subnets

An IPv4 address is 32 bits. A subnet mask (prefix) splits it into:

- **Network bits** (which network)
- **Host bits** (which host inside that network)

Example: `192.168.1.10/24`

- Network: `192.168.1.0`
- Host part: `.10`
- Broadcast: `192.168.1.255`

### Subnetting worked example

Find the subnet range for `192.168.10.77/26`.

- `/26` means 26 network bits → 6 host bits
- Block size in last octet: $2^6 = 64$
- Subnets: 0–63, 64–127, 128–191, 192–255
- `77` falls in 64–127

So:

- Network: `192.168.10.64`
- Broadcast: `192.168.10.127`
- Usable hosts: `192.168.10.65` to `192.168.10.126`

## Routing (high level)

A router forwards based on the destination IP using:

- a routing table
- **longest prefix match** (most specific route wins)

Typical entries:

- Connected routes (directly attached networks)
- Static routes
- Dynamic routes (OSPF/BGP etc.)
- Default route (`0.0.0.0/0`) for “everything else”

## TTL (Time To Live)

- Each router decrements TTL by 1.
- When TTL hits 0, router drops the packet and usually sends ICMP Time Exceeded.

This is how traceroute works.

## ICMP (Internet Control Message Protocol)

ICMP carries control and error information.
Common types:

- Echo request/reply (ping)
- Time exceeded (traceroute)
- Destination unreachable
- Fragmentation needed (Path MTU Discovery in IPv4)

Important nuance:

- Blocking ICMP can break PMTU discovery → causes “mysterious” stalls.

## NAT (Network Address Translation)

NAT rewrites addresses (and often ports). Two common forms:

### SNAT (outbound)

Home network example:

- Laptop: `192.168.0.10:51514`
- Router public IP: `203.0.113.5`

Outbound TCP flow:

- Before NAT: `192.168.0.10:51514 → 93.184.216.34:443`
- After NAT: `203.0.113.5:40001 → 93.184.216.34:443`

Router keeps a table mapping:

- `(203.0.113.5:40001)` back to `(192.168.0.10:51514)`

### DNAT (inbound / port forward)

If you expose an internal server:

- `203.0.113.5:443` forwarded to `192.168.0.50:443`

## Common pitfalls

- “Ping works but app doesn’t” can be firewall/NAT/port issues.
- NAT breaks protocols that embed IPs inside payloads unless handled (classic FTP).

## Interview questions

1. Explain longest prefix match with an example.
2. Walk through subnetting `192.168.10.77/26`.
3. What’s TTL and why does traceroute use it?
4. How does SNAT enable multiple devices to share one public IP?
