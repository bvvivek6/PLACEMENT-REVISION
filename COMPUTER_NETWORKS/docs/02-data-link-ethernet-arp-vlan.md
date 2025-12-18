# Data link: Ethernet, MAC, ARP, VLANs

This chapter explains how devices communicate on the _local network_ (same broadcast domain).

## Ethernet frames (L2)

An Ethernet frame contains:

- Destination MAC
- Source MAC
- EtherType (what payload is: IPv4, IPv6, ARP)
- Payload (e.g., an IP packet)
- FCS (error detection)

### Why switches need MAC addresses

A switch forwards frames based on destination MAC.

- It learns which MAC lives on which port by observing source MACs.
- It builds a MAC table (CAM table).

If the destination MAC is unknown, the switch floods the frame out all ports in that VLAN.

## Broadcast domain

A **broadcast** frame is delivered to all devices in a broadcast domain.

- ARP requests are broadcasts.
- Too much broadcast traffic can become a problem at scale.

## ARP (Address Resolution Protocol)

ARP maps **IPv4 → MAC** on a local network.

### Key rule

ARP does not cross routers.

### Example: local destination (same subnet)

Client `10.0.0.10/24` wants to talk to `10.0.0.20/24`.

1. Client checks ARP cache; no entry.
2. Client broadcasts: “Who has 10.0.0.20? Tell 10.0.0.10.”
3. Server replies with its MAC.
4. Client sends Ethernet frames to server MAC.

### Example: remote destination (different subnet)

Client `10.0.0.10/24` wants to talk to `203.0.113.20`.

- Destination is not in `10.0.0.0/24`, so client sends traffic to **default gateway** (e.g., `10.0.0.1`).
- Client ARPs for **10.0.0.1** (gateway MAC), not for the remote server.

## VLANs (Virtual LANs)

A VLAN logically splits a switch into multiple isolated L2 networks.

- Devices in VLAN 10 don’t see broadcasts from VLAN 20.
- VLAN tagging (802.1Q) adds a VLAN ID to frames across trunk links.

### Access vs trunk ports

- **Access port:** belongs to one VLAN; frames are untagged.
- **Trunk port:** carries multiple VLANs; frames are tagged.

## MAC vs IP: what changes hop-by-hop

- **MAC addresses change at every hop** (new frame each link)
- **IP addresses stay the same end-to-end** (except NAT)

This is a common interview point.

## Interview questions

1. Why do we ARP for the gateway when the destination is remote?
2. What is a broadcast domain? How do VLANs affect it?
3. When a switch doesn’t know a MAC, what does it do?
