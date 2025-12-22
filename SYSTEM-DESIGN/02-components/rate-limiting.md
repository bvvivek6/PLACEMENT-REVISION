# Rate Limiting

Controls the rate of traffic sent or received by a network interface controller. Used to prevent DoS attacks and limit web scraping.

## Why Rate Limit?

1.  **Prevent Abuse:** DDoS attacks, Brute force login attempts.
2.  **Cost Control:** Prevent excessive use of paid 3rd party APIs.
3.  **Fairness:** Ensure one heavy user doesn't starve others.

## Algorithms

### 1. Token Bucket

- **Concept:** A bucket holds `N` tokens. Tokens are added at a fixed rate `r`. Each request consumes 1 token. If empty, reject.
- **Pros:** Allows **bursts** of traffic (up to bucket size). Memory efficient.
- **Cons:** Complex to tune.

### 2. Leaky Bucket

- **Concept:** Requests enter a bucket (queue). They leak out (are processed) at a constant rate. If bucket is full, discard.
- **Pros:** Smooths out traffic (constant outflow).
- **Cons:** Bursts are lost/delayed.

### 3. Fixed Window Counter

- **Concept:** Count requests in a fixed time window (e.g., 10:00-10:01). If count > limit, reject.
- **Pros:** Simple.
- **Cons:** **Edge Case:** A burst at the end of one window and start of the next can allow 2x traffic in a short span.

### 4. Sliding Window Log

- **Concept:** Keep a timestamp log of every request. Count logs within the last window (e.g., `now() - 1 min`).
- **Pros:** Very accurate.
- **Cons:** High memory usage (storing all timestamps).

### 5. Sliding Window Counter (Hybrid)

- **Concept:** Weighted average of the previous window's count and current window's count.
- **Formula:** `Requests = (Prev_Window_Count * (1 - %_into_current_window)) + Current_Window_Count`
- **Pros:** Accurate and memory efficient.

## Distributed Rate Limiting

In a distributed system, you need a centralized store (Redis) to count requests across all server instances.

### Race Conditions

- **Problem:** Two servers read `count=10`, both increment to `11`. Actual count should be `12`.
- **Solution:** Use **Redis Lua Scripts** or `INCR` operations to make the "Read-Increment-Write" atomic.

```lua
-- Redis Lua Script for Token Bucket
local tokens = redis.call("get", KEYS[1])
if tokens and tonumber(tokens) > 0 then
    redis.call("decr", KEYS[1])
    return 1 -- Allowed
else
    return 0 -- Rejected
end
```
