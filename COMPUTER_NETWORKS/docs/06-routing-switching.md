# Routing & switching basics

This chapter explains how networks scale beyond a single LAN.

## Switching (L2) vs routing (L3)

- **Switch**: forwards by MAC within a VLAN/broadcast domain.
- **Router**: forwards by IP between networks; separates broadcast domains.

## Routing protocols overview

### Distance vector (example: RIP)

- Routers share “distance” to networks with neighbors.
- Simple but slower convergence; limited scale.

### Link state (example: OSPF)

- Routers flood link-state info.
- Each router computes shortest paths (Dijkstra) to build routing table.
- Faster convergence; common within enterprises.

### Path vector (BGP)

- Used between autonomous systems (the Internet).
- Policy-based routing (“prefer this provider/peer”).

## Default gateway

Hosts usually have:

- a route for their local subnet (direct)
- a default route to the gateway for everything else

## Spanning Tree (STP) (quick intuition)

Ethernet doesn’t tolerate loops well (broadcast storms).
STP prevents L2 loops by blocking some ports to create a loop-free tree.

## Load balancing (conceptual)

- L4 load balancers route based on IP/port.
- L7 load balancers route based on HTTP headers/paths.

## Interview questions

1. Why are L2 loops dangerous?
2. Compare RIP vs OSPF vs BGP at a high level.
3. What is a default gateway and how does a host use it?
