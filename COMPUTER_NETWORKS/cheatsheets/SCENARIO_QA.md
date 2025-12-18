# Scenario Q&A (Interview Style)

Each scenario is written like a real on-call issue. Practice answering with:

- what you’d check first
- what tools/commands you’d use
- what hypotheses you’d test

## 1) “Website works on my phone but not on my laptop”

**Likely buckets**

- DNS difference (cached vs different resolver)
- Proxy/VPN on laptop
- Firewall rules / corporate network
- IPv6 vs IPv4 differences

**Good approach**

1. Compare DNS results from both devices (same network?)
2. Check whether laptop uses VPN/proxy
3. Try `curl -v https://site` and inspect where it fails (DNS? TCP? TLS?)

## 2) “Service to DB times out only under load”

**Possible causes**

- Connection pool exhaustion
- SYN backlog / handshake delays
- Packet loss causing TCP retransmissions
- Server-side saturation leading to delayed ACKs

**Evidence to collect**

- App: pool metrics, timeouts, error rate
- Host: `ss -s` / connection states (TIME_WAIT, SYN-SENT)
- Network: p95 RTT, loss, retransmit counters

## 3) “Ping works but HTTP doesn’t”

**Interpretation**

- ICMP allowed, TCP/80 blocked (firewall)
- HTTP service down, port closed
- Wrong SNI / TLS issues if HTTPS

**Checks**

- Test TCP port: `curl -v http://host:80`
- Validate route/security group rules

## 4) “DNS resolves but connection goes to wrong server”

**Common reasons**

- Multiple A records and client picks a different one
- Anycast address
- Stale DNS cache vs updated records
- Split-horizon DNS (internal vs external view)

## 5) “Traceroute stops halfway”

**Note**
Traceroute relies on ICMP Time Exceeded replies; routers can drop/rate-limit these.

**What to say**

- Not necessarily a real outage
- Confirm with TCP-based traceroute or actual app tests

## 6) “Why does TLS add latency?”

- TLS handshake costs extra round trips (depends on version, resumption)
- Certificate validation and OCSP can add delays
- Mitigate with keep-alives, session resumption, HTTP/2, and caching
