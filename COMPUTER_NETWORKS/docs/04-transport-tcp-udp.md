# Transport: TCP vs UDP, reliability, congestion

Transport is about process-to-process communication using ports.

## Ports and sockets

A **socket** is typically identified by:

- local IP, local port
- remote IP, remote port
- protocol (TCP/UDP)

Servers often bind to well-known ports (e.g., 443), clients use ephemeral ports.

## UDP

UDP is simple:

- No handshake
- No reliability or ordering guarantees
- Low overhead

### When UDP is a good choice

- Real-time traffic where late data is useless (voice/video)
- Simple request/response (DNS historically)
- As a substrate for new transports (QUIC)

### What app must do over UDP

If you need reliability, you implement it yourself:

- sequence numbers
- acknowledgements
- retransmits

## TCP

TCP provides a **reliable, ordered byte stream**.

### 3-way handshake

1. Client → Server: SYN (proposes initial sequence number)
2. Server → Client: SYN-ACK
3. Client → Server: ACK

After this, both sides know:

- the other side is reachable
- both sides’ initial sequence numbers

### Reliability mechanics

- **Sequence numbers**: order bytes
- **ACKs**: confirm received bytes
- **Retransmission**: resend on loss

### Flow control (receiver protection)

- Receiver advertises a **receive window** (rwnd).
- Sender must not send more unacknowledged data than receiver can buffer.

### Congestion control (network protection)

Congestion control is about not overwhelming the network.

- Sender maintains a congestion window (cwnd)
- cwnd grows when things look good, shrinks on loss

**Key distinction**

- Flow control: “don’t overwhelm the receiver”
- Congestion control: “don’t overwhelm the network”

## Head-of-line blocking (why TCP can feel slow)

TCP delivers data in order.

- If one segment is lost, later segments are buffered but not delivered to the app.
- This is why HTTP/2 multiplexing over one TCP connection can still be affected by packet loss.

HTTP/3 avoids this by running over QUIC (streams without TCP’s HoL blocking semantics).

## TCP connection states (interview favorite)

- LISTEN, SYN-SENT, SYN-RECEIVED, ESTABLISHED
- FIN-WAIT, CLOSE-WAIT, TIME-WAIT

Why TIME-WAIT exists:

- Ensures delayed packets from an old connection don’t corrupt a new one using same 4‑tuple.

## Interview questions

1. Why does TCP use a 3-way handshake?
2. Flow control vs congestion control?
3. What is TIME-WAIT and why does it matter?
4. Compare UDP and TCP with real examples.
