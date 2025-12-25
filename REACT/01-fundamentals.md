# Fundamentals

## What is React?

React is a JavaScript library for building user interfaces using **components**.

Key ideas:

- UI is described as a function of state: $UI = f(state)$
- Components re-render when their state/props change
- Uses a Virtual DOM and reconciliation to update the real DOM efficiently

**One-liner (interview):** React lets you build UI as reusable components and keeps the UI in sync with state.

---

## What is a Single Page Application (SPA)?

An SPA is a web app where:

- The browser loads **one main HTML page** (plus JS/CSS)
- Navigation happens by updating the URL + rendering different views **without a full page reload**

### SPA vs Multi-Page App (MPA)

```text
MPA:   /home -> (full reload) -> /about -> (full reload) -> /contact
SPA:   /home -> (JS renders)  -> /about -> (JS renders)  -> /contact
```

---

## Advantages of SPA (VIMP)

- **Fast navigations after first load** (no full reload)
- **Better UX**: transitions feel app-like
- **Efficient API usage**: fetch JSON, update parts of the UI
- **Separation of concerns**: UI in frontend, data via APIs

Trade-offs (important):

- **Initial load can be heavy** (big JS bundle)
- **SEO can be harder** with pure CSR (needs SSR/SSG or correct metadata handling)

---

## Client-Side Rendering (CSR)

CSR means the server returns a minimal HTML shell, and the browser:

1. Downloads JS
2. Runs React
3. Renders UI in the browser

### CSR flow

```mermaid
flowchart LR
A[Request /page] --> B[Server returns HTML shell]
B --> C[Browser downloads JS bundle]
C --> D[React renders UI]
D --> E[Fetch data (often)]
E --> F[Update UI]
```

Pros:

- Great for highly interactive apps
- Reduced server rendering work

Cons:

- Slower first meaningful paint on slow devices/networks
- SEO challenges unless pre-rendered/SSR

---

## Server-Side Rendering (SSR)

SSR means the server generates HTML for the page on each request.

Typical React SSR today is **SSR + Hydration**:

- Server sends HTML (content visible quickly)
- Client JS “hydrates” to attach event listeners and make it interactive

### SSR + Hydration flow

```mermaid
flowchart LR
A[Request /page] --> B[Server renders HTML]
B --> C[Browser shows HTML quickly]
C --> D[Browser downloads JS]
D --> E[Hydration: attach events]
E --> F[Interactive page]
```

Pros:

- Better initial paint
- Better SEO (HTML contains content)

Cons:

- More server work
- Hydration cost on client
- Must handle server/client differences (e.g., window not available on server)

---

## CSR vs SSR (quick comparison)

| Topic         | CSR                | SSR                 |
| ------------- | ------------------ | ------------------- |
| First load    | Slower (JS needed) | Faster (HTML ready) |
| SEO           | Harder             | Easier              |
| Server cost   | Lower              | Higher              |
| Interactivity | After JS loads     | After hydration     |
