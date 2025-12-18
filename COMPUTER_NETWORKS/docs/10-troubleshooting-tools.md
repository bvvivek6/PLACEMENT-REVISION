# Troubleshooting: tools + mental model

Goal: identify where the failure is (DNS, routing, reachability, port, TLS, app).

## Layered troubleshooting

### 1) Link/local

- Are you on the right network?
- Do you have an IP?

### 2) DNS

- Does name resolve to expected IPs?

### 3) L3 reachability

- Can you reach the destination network (routes, VPN, gateway)?

### 4) L4 port

- Is the destination port reachable/open?

### 5) L7 protocol

- HTTP status? TLS errors? App errors?

## Practical tools

### `ping`

- Tests ICMP echo reachability and RTT.
- Failure doesn’t always mean outage (ICMP may be blocked).

### `traceroute` / `tracert`

- Shows hop-by-hop path using TTL expiry.
- Missing hops can be due to ICMP rate-limit.

### `nslookup` / `dig`

- Inspect DNS answers, TTLs, resolver behavior.

### `curl -v`

- Great for seeing where it fails: DNS vs TCP vs TLS vs HTTP.

### Wireshark

- Ground truth for packets.

## Example: debug “can’t open https://example.com”

1. `nslookup example.com` → do you get IPs?
2. `ping <ip>` (optional) → basic reachability
3. `curl -v https://example.com` → inspect error
   - DNS error → resolver issue
   - connect timeout → routing/firewall
   - TLS handshake fail → cert/SNI/time
   - HTTP 5xx → server/app

## Interview questions

1. How would you debug: ping works but HTTPS fails?
2. How does traceroute work and what are its limitations?
3. Why is Wireshark often the fastest path to truth?
