# Security: common attacks + defenses

Networking security is about reducing attack surface and limiting blast radius.

## Common threats

### Spoofing and MITM

- **ARP spoofing**: attacker poisons ARP caches to intercept traffic on a LAN.
- Defense: static ARP (rare), DHCP snooping + dynamic ARP inspection (managed networks), encryption (TLS).

### DNS attacks

- Cache poisoning (harder today with randomization + DNSSEC adoption)
- Phishing via lookalike domains
- Defense: DNSSEC (where used), monitoring, user education

### DDoS

- Volume (bandwidth flood)
- Protocol (SYN floods)
- Application (expensive HTTP requests)

### Port scanning

- Recon using TCP SYN scans, UDP scans
- Defense: firewalls, segmentation, least privilege, IDS/IPS

## Security controls

- **Firewalls**: allow/deny traffic by rules
- **Stateful vs stateless**: stateful tracks connections, stateless evaluates each packet
- **Segmentation**: isolate networks (VLANs/subnets) to limit lateral movement
- **TLS everywhere**: prevent sniffing and many MITM attacks

## Interview questions

1. How does ARP spoofing work and how does TLS help?
2. What’s the difference between stateful and stateless firewalls?
3. Explain SYN flood at a high level.
