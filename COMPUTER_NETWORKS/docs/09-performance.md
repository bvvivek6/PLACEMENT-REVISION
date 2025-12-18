# Performance: latency, throughput, buffering, QoS

Performance issues are often about tradeoffs: delay vs utilization vs loss.

## Latency vs throughput

- **Latency**: time for a message to travel (often measured as RTT)
- **Throughput**: rate of successful data delivery (Mbps/Gbps)

A link can have high throughput but bad latency (e.g., deep buffers).

## Bandwidth-delay product (BDP)

BDP estimates how much data can be “in flight” on a path:

$$\text{BDP} = \text{bandwidth} \times \text{RTT}$$

Example:

- 100 Mbps link, RTT 100 ms
- BDP = 100,000,000 bits/s × 0.1 s = 10,000,000 bits ≈ 1.25 MB

Meaning: to fully utilize the link, TCP may need ~1.25 MB in-flight (window size).

## Bufferbloat (why big buffers hurt)

Large queues reduce packet loss but can dramatically increase latency.
Symptoms:

- latency spikes during downloads/uploads
- “lag” in games/voice while someone is uploading

## Packet loss and TCP

Loss triggers retransmissions and reduces congestion window.
Even small loss rates can significantly reduce throughput on long-fat networks.

## QoS (very high level)

QoS prioritizes traffic (e.g., voice) to reduce latency/jitter.

## Interview questions

1. Explain bandwidth-delay product with numbers.
2. Why can bigger buffers make latency worse?
3. Why does TCP throughput drop with packet loss?
