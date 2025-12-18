# Networking overview + OSI vs TCP/IP

This chapter gives you a mental model that makes the rest of networking feel predictable.

## Why layers exist

Networking problems are hard because many things happen at once: signals, frames, routing, reliability, security, and application semantics.

Layering helps by defining _contracts_:

- Each layer offers a service to the layer above.
- Each layer hides details of how it accomplishes that service.

## OSI model (7 layers)

1. **Physical (L1):** bits on wire/air (electrical/optical/radio)
2. **Data Link (L2):** frames on a local network (Ethernet/Wi‑Fi), MAC addresses, switching
3. **Network (L3):** packets across networks (IP), routing
4. **Transport (L4):** end-to-end communication between processes (TCP/UDP), ports
5. **Session (L5):** sessions (often folded into apps today)
6. **Presentation (L6):** encoding, compression, encryption (e.g., TLS is often considered here conceptually)
7. **Application (L7):** HTTP, DNS, SMTP, SSH, etc.

In practice, engineers often use OSI as a vocabulary rather than a strict implementation guide.

## OSI layers (detailed, with what runs there)

Use OSI as a **debugging checklist**: when something breaks, ask “Which layer is failing, and what evidence do I have?”

### L1 — Physical

**What it does**

- Moves **bits** as signals over copper, fiber, or radio.
- Defines signaling, modulation, voltages/light levels, frequencies, connectors, and physical data rates.

**PDU**: bits

**Common tech / standards**

- Ethernet PHYs (e.g., 1000BASE‑T), fiber variants (e.g., 10GBASE‑SR)
- Wi‑Fi radio (802.11 PHY)
- DSL, DOCSIS, LTE/5G PHY layers

**Typical devices**

- Cables, optics (SFP/SFP+), repeaters, hubs (legacy)

**Common symptoms**

- Link down / no carrier, flapping links, high physical error rates

**Example**

- A bad cable causes intermittent packet loss. The OS (higher layers) might show TCP retransmissions, but the root cause is L1.

### L2 — Data Link

**What it does**

- Transfers **frames** on a single local link / broadcast domain.
- Defines framing, **MAC addressing**, and local delivery (unicast/multicast/broadcast).
- Error detection on the link (e.g., Ethernet FCS/CRC); sometimes retransmission at L2 (common in Wi‑Fi).
- Segmentation of a physical network into multiple broadcast domains via **VLANs**.

**PDU**: frame

**Addressing**: MAC addresses (local scope)

**What runs here**

- Ethernet (802.3), Wi‑Fi MAC (802.11)
- ARP (maps IPv4 address → MAC on a LAN)
- VLAN tagging (802.1Q)
- STP/RSTP (loop prevention in switched L2 networks)

**Typical devices**

- Switches/bridges, NICs, wireless access points

**Example**

- Your laptop wants to send an IP packet to the default gateway `10.0.0.1`.
  - It uses **ARP** to find the gateway’s MAC.
  - Then it encapsulates the IP packet into an **Ethernet frame** addressed to that MAC.

### L3 — Network

**What it does**

- Moves **packets** between networks (across multiple links).
- Provides **logical addressing** (IP) and routing decisions (next hop).
- Defines TTL/hop limit, fragmentation rules, and basic reachability semantics.

**PDU**: packet (IP datagram)

**Addressing**: IP addresses (end-to-end across networks)

**What runs here**

- IPv4/IPv6
- ICMP/ICMPv6 (errors + diagnostics like ping, Path MTU Discovery)
- NAT (often implemented at the L3 boundary, though it interacts with L4 too)
- Routing protocols control-plane (OSPF, BGP) — they exist “to build routes” for L3 forwarding

**Typical devices**

- Routers, L3 switches, firewalls (often route + filter)

**Example**

- Your laptop sends to `203.0.113.20`. Your router looks up the destination prefix in its routing table and forwards the packet to the ISP next hop. Each hop decrements TTL.

### L4 — Transport

**What it does**

- Provides end-to-end delivery between **processes** using **ports**.
- Multiplexes/demultiplexes many conversations on one host.
- Optional reliability, ordering, congestion control depending on protocol.

**PDU**

- TCP: segment
- UDP: datagram

**Addressing**: ports (per-host)

**What runs here**

- TCP (reliable, ordered byte stream; congestion control)
- UDP (best-effort message delivery)
- QUIC is often described as “over UDP” in the data plane but implements many transport-like features in user space

**Typical devices / components**

- Host kernel networking stack; L4 load balancers; stateful firewalls track L4 flows

**Example**

- HTTPS to `:443`:
  - Client picks an ephemeral source port (e.g., `51514`).
  - TCP establishes a connection (3‑way handshake), then carries application bytes.

### L5 — Session

**What it does**

- Manages **session state**: establishing, maintaining, and tearing down logical dialogs.
- Historically included checkpoints, reconnection, and dialog control.

**Where it exists today**

- Often implemented inside applications and libraries rather than a standalone “session protocol layer”.

**Examples**

- An application-level login session (cookie/token) is “session-like” even though it rides on HTTP.
- Long-lived connections (e.g., a database connection pool) maintain conversational state beyond “send one packet”.

### L6 — Presentation

**What it does**

- Defines how data is **represented**: serialization formats, encoding, compression, and (conceptually) encryption.

**What runs here (common examples)**

- Serialization: JSON, Protobuf, ASN.1
- Encoding: UTF‑8
- Compression: gzip, Brotli
- Encryption: TLS is frequently placed here conceptually (in practice it sits between application data and transport)

**Example**

- A web client sends a JSON payload encoded as UTF‑8 and compressed with gzip before encryption under TLS.

### L7 — Application

**What it does**

- Defines application semantics: “fetch this URL”, “resolve this domain”, “send this email”.

**What runs here**

- HTTP/HTTPS, DNS, SMTP, SSH, NTP, DHCP (the protocol logic)

**Example**

- DNS resolution (L7) returns an IP address; then HTTP uses that address to open a connection and fetch content.

### Quick mapping: OSI → TCP/IP (how people talk day-to-day)

- OSI L1–L2 → **Link**
- OSI L3 → **Internet**
- OSI L4 → **Transport**
- OSI L5–L7 → **Application**

This is why “TLS is L6” is a useful mental model, but in real stacks you’ll often see it described as “between HTTP and TCP”.

## TCP/IP model (practical)

- **Link:** Ethernet/Wi‑Fi, ARP
- **Internet:** IP, ICMP, routing
- **Transport:** TCP/UDP
- **Application:** DNS/HTTP/TLS/SSH…

## Encapsulation (envelopes inside envelopes)

Data is wrapped as it goes down the stack:

- HTTP message becomes TCP **segment** payload
- TCP segment becomes IP **packet** payload
- IP packet becomes Ethernet/Wi‑Fi **frame** payload

Why this matters:

- A firewall might filter by **IP + port** (L3/L4)
- A switch forwards by **MAC address** (L2)
- A router forwards by **IP address** (L3)

### Example: “Send an HTTP request”

Suppose a client `C` talks to server `S`:

- Client IP: `10.0.0.10`
- Server IP: `203.0.113.20`
- Client chooses source port: `51514`
- Server listens on destination port: `443`

The connection is identified by the 5‑tuple:

- (10.0.0.10, 51514, 203.0.113.20, 443, TCP)

This 5‑tuple (or a NAT-modified version of it) is what many middleboxes track.

## Addresses at different layers

- **MAC address (L2):** identifies a NIC _on the local link_; used by switches.
- **IP address (L3):** identifies a host (or interface) _across networks_; used by routers.
- **Port (L4):** identifies an application endpoint (process) on a host.

A classic confusion:

- IP gets you to the right **machine**.
- Port gets you to the right **program**.

## MTU and fragmentation (preview)

- **MTU**: max payload size of a link-layer frame (e.g., Ethernet often 1500 bytes payload).
- If an IP packet is too big for a link MTU:
  - IPv4 routers _can_ fragment (but it’s usually undesirable)
  - IPv6 routers do **not** fragment (sender must use Path MTU Discovery)

You’ll revisit this in performance and troubleshooting.

## Interview questions

1. What’s the difference between a switch and a router?
2. What does “encapsulation” mean? Walk through HTTP → TCP → IP → Ethernet.
3. Why do we need ports if we already have IP addresses?
