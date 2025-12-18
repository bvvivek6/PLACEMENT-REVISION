# Application: DNS, HTTP, TLS

This chapter connects the “plumbing” to what most developers see daily.

## DNS (Domain Name System)

DNS translates names into records.

### Common record types

- **A**: name → IPv4
- **AAAA**: name → IPv6
- **CNAME**: alias to another name
- **MX**: mail exchanger
- **TXT**: metadata (SPF/DKIM/verification)
- **NS**: authoritative name servers

### Resolution flow (typical)

1. Client asks a **recursive resolver** (often ISP/corporate/public resolver)
2. Resolver queries:
   - Root servers
   - TLD servers (e.g., `.com`)
   - Authoritative servers for the domain
3. Resolver caches result per TTL

### Example: CNAME chain

`app.example.com` → CNAME → `lb.cloudprovider.net` → A → `203.0.113.20`

If the final A record has TTL=60, resolvers may change addresses quickly.

## HTTP basics

HTTP is a request/response protocol.

### HTTP/1.1

- Text-based headers
- Persistent connections (keep-alive) reduce handshake costs
- One request at a time per connection (pipelining exists but is uncommon)

### HTTP/2

- Binary framing
- Multiplexed streams over one TCP connection
- Header compression (HPACK)

### HTTP/3

- Runs over QUIC (UDP-based)
- Multiplexing without TCP head-of-line blocking

## TLS (Transport Layer Security)

TLS provides:

- **Confidentiality** (encryption)
- **Integrity** (tamper detection)
- **Authentication** (server identity via certificates)

### Certificates in one picture

- Server presents a certificate for `example.com`
- Client verifies:
  - hostname matches
  - cert is signed by an intermediate/root it trusts
  - validity time window
  - revocation status (sometimes)

### Why TLS can fail

- Wrong system time (cert “not yet valid” / “expired”)
- Hostname mismatch (SNI/Host mismatch)
- Missing intermediate certificate
- TLS version/cipher mismatch

## Putting it together: open a HTTPS page

1. DNS resolves name to IP
2. TCP handshake to port 443
3. TLS handshake (negotiate keys, verify cert)
4. HTTP request/response over encrypted channel

## Interview questions

1. Explain how DNS caching works and why TTL matters.
2. What is the difference between HTTP/1.1 and HTTP/2?
3. What does TLS authenticate and how?
4. What happens when you visit an HTTPS URL from scratch?
