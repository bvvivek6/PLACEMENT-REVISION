# Observability & Monitoring

You cannot scale what you cannot measure. Observability is about understanding the internal state of a system based on its external outputs.

## The Three Pillars of Observability

### 1. Metrics (What is happening?)

Aggregatable numerical data measured over time. Cheap to store and query.

- **Types:**
  - **Counter:** Always goes up (e.g., `http_requests_total`).
  - **Gauge:** Goes up and down (e.g., `memory_usage_bytes`, `active_connections`).
  - **Histogram:** Distribution of values (e.g., `request_duration_seconds` -> p50, p90, p99).
- **Tools:** Prometheus, Datadog, CloudWatch.
- **Use Case:** Dashboards, Alerting ("High CPU", "High Error Rate").

### 2. Logging (Why is it happening?)

Discrete records of events. Expensive to store and search.

- **Structure:** Structured logging (JSON) is mandatory for machine parsing.
  ```json
  {
    "level": "error",
    "user_id": "123",
    "msg": "Payment failed",
    "trace_id": "abc-xyz"
  }
  ```
- **Tools:** ELK Stack (Elasticsearch, Logstash, Kibana), Splunk, Loki.
- **Use Case:** Debugging specific errors, Auditing.

### 3. Tracing (Where is it happening?)

Follows a request's journey through multiple microservices.

- **Concept:**
  - **Trace ID:** Unique ID for the entire request chain.
  - **Span ID:** ID for a specific operation within a service.
- **Visualization:** Waterfall chart showing time spent in each service/DB.
- **Tools:** Jaeger, Zipkin, OpenTelemetry.
- **Use Case:** Finding latency bottlenecks ("Why did this request take 5 seconds?").

## Alerting Philosophy

- **Symptom-based Alerting:** Alert on what the _user_ experiences.
  - Good: "High Latency", "High Error Rate".
  - Bad: "CPU High" (If latency is fine, who cares?).
- **Golden Signals (Google SRE):**
  1.  **Latency:** Time it takes to serve a request.
  2.  **Traffic:** Demand on the system (req/sec).
  3.  **Errors:** Rate of requests failing.
  4.  **Saturation:** How "full" the service is (Memory/CPU/Disk).
