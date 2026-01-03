# Message Queues

Message queues facilitate asynchronous communication between services, decoupling the producer from the consumer.

## Why use a Message Queue?

1.  **Decoupling:** Producer doesn't need to know who the consumer is or if they are online.
2.  **Asynchronism:** Fire and forget. The user doesn't wait for the task to finish (e.g., sending an email).
3.  **Load Leveling (Throttling):** If traffic spikes, the queue buffers requests so consumers can process them at their own pace without crashing.
4.  **Reliability:** If a consumer fails, the message stays in the queue to be retried.

## Models

### 1. Point-to-Point

- One message is processed by exactly one consumer.
- **Example:** Task distribution (RabbitMQ, SQS).

```mermaid
graph LR
    P[Producer] --> Q[Queue]
    Q --> C1[Consumer 1]
    Q --> C2[Consumer 2]
    Note right of Q: Message goes to C1 OR C2
```

### 2. Publish-Subscribe (Pub/Sub)

- A message is broadcast to all subscribers of a topic.
- **Example:** Notifications, Streaming data (Kafka, SNS).

```mermaid
graph LR
    P[Producer] --> T[Topic]
    T --> S1[Subscriber 1]
    T --> S2[Subscriber 2]
    Note right of T: Message goes to S1 AND S2
```

## Advanced Concepts

### Dead Letter Queue (DLQ)

A specialized queue where messages are sent if they cannot be processed successfully after a certain number of retries.

- **Purpose:** Prevents "poison messages" from blocking the queue forever. Allows developers to inspect failed messages later.
- **Trigger:** Max retries exceeded, message TTL expired, queue full.

### Delivery Semantics

How many times is a message delivered?

1.  **At-Most-Once:** Message is sent once. If it's lost, it's lost. (Fire and forget).
    - _Use Case:_ Sensor data, Logging.
2.  **At-Least-Once:** Message is guaranteed to be delivered, but might be delivered multiple times (duplicates).
    - _Requirement:_ Consumer must be **Idempotent**.
    - _Use Case:_ Payments, Emails.
3.  **Exactly-Once:** Message is delivered exactly once. Hardest to achieve.
    - _Use Case:_ Financial transactions (Kafka Transactions).

## Technologies

### RabbitMQ

- **Type:** Traditional Message Broker.
- **Push-based:** Pushes messages to consumers.
- **Smart Broker / Dumb Consumer:** Broker tracks state (ack/nack).
- **Best For:** Complex routing, task queues.

#### Code Example: RabbitMQ (Python Pika)

**Producer:**

```python
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()
channel.queue_declare(queue='hello')

channel.basic_publish(exchange='', routing_key='hello', body='Hello World!')
print(" [x] Sent 'Hello World!'")
connection.close()
```

**Consumer:**

```python
def callback(ch, method, properties, body):
    print(f" [x] Received {body}")

channel.basic_consume(queue='hello', on_message_callback=callback, auto_ack=True)
channel.start_consuming()
```

### Apache Kafka

- **Type:** Distributed Event Streaming Platform.
- **Pull-based:** Consumers pull messages (poll).
- **Dumb Broker / Smart Consumer:** Consumers track their own offset (position in the log).
- **Persistence:** Stores messages on disk for a set time (retention).
- **Best For:** High throughput, log aggregation, real-time analytics.

## Comparison

| Feature         | RabbitMQ                                 | Kafka                    |
| :-------------- | :--------------------------------------- | :----------------------- |
| **Model**       | Queue (Smart Broker)                     | Log (Smart Consumer)     |
| **Throughput**  | High (Thousands/sec)                     | Massive (Millions/sec)   |
| **Persistence** | Memory (mostly)                          | Disk (Log)               |
| **Consumption** | Push                                     | Pull                     |
| **Order**       | Not guaranteed (with multiple consumers) | Guaranteed per partition |
