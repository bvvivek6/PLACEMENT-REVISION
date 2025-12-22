# Common Frontend System Design Questions

Practice these scenarios. For each, define the **Requirements**, **Architecture**, **Data Model**, and **Optimization**.

## 1. Design a News Feed (Facebook/Twitter)

- **Core Challenges:** Infinite scrolling, heavy media, virtualization.
- **Key Concepts:**
  - **Virtualization:** Only render visible posts (`react-window`).
  - **Pagination:** Cursor-based pagination (not offset).
  - **Caching:** React Query with `staleTime`.
  - **Optimistic UI:** Like/Retweet updates instantly.

## 2. Design a Real-Time Chat (WhatsApp/Slack)

- **Core Challenges:** Low latency, message ordering, offline support.
- **Key Concepts:**
  - **Protocol:** WebSockets for bi-directional comms.
  - **State:** Optimistic updates for sending messages.
  - **Storage:** IndexedDB for offline history.
  - **UX:** Typing indicators, read receipts.

## 3. Design a Dashboard with Live Updates (Stock/Crypto)

- **Core Challenges:** High frequency updates, rendering performance.
- **Key Concepts:**
  - **Protocol:** Server-Sent Events (SSE) or WebSockets.
  - **Throttling:** Don't re-render on _every_ price tick (e.g., limit to 60fps).
  - **Canvas vs DOM:** If thousands of data points, use `<canvas>` instead of `<div>`.

## 4. Design a Large Data Table (1M Rows)

- **Core Challenges:** Performance, sorting, filtering.
- **Key Concepts:**
  - **Virtualization:** Mandatory.
  - **Server-Side Operations:** Sort and filter on the server, not the client.
  - **Debouncing:** Wait for user to stop typing before filtering.

## 5. Design Search Autocomplete (Google)

- **Core Challenges:** Latency, API load, UX.
- **Key Concepts:**
  - **Debouncing:** Wait 300ms after typing stops.
  - **Caching:** Cache results for "react" so typing "react" again doesn't hit API.
  - **Race Conditions:** Ensure the response for "react" doesn't overwrite "reactjs" if it arrives late.

## 6. Design an Image Carousel / Gallery

- **Core Challenges:** Image loading, touch gestures, accessibility.
- **Key Concepts:**
  - **Lazy Loading:** Only load next/prev images.
  - **Preloading:** Preload the _next_ image for instant navigation.
  - **A11y:** Keyboard navigation (Arrow keys), ARIA roles.
