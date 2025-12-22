# Asset Optimization & Delivery

Assets (Images, Fonts, JS, CSS) usually make up the bulk of a page's weight.

## 1. Image Optimization

Images are often the biggest cause of slow LCP.

### A. Modern Formats

Use **WebP** or **AVIF** instead of JPEG/PNG. They offer better compression with same quality.

### B. Responsive Images (`srcset`)

Don't serve a 4K image to a mobile phone. Use `srcset` to let the browser choose the right size.

```html
<img
  src="small.jpg"
  srcset="small.jpg 500w, medium.jpg 1000w, large.jpg 2000w"
  sizes="(max-width: 600px) 100vw, 50vw"
  alt="Hero Image"
/>
```

### C. Lazy Loading

Only load images when they scroll into view.

- **Native:** `<img loading="lazy" ... />`
- **Next.js:** `<Image />` component handles this automatically.

---

## 2. Font Optimization

Fonts block rendering (FOIT - Flash of Invisible Text) or cause layout shifts (FOUT - Flash of Unstyled Text).

### Strategies

1.  **`font-display: swap`:** Show a fallback system font immediately, then swap in the custom font when loaded.
2.  **Preloading:** Tell the browser to fetch critical fonts early. `<link rel="preload" href="font.woff2" as="font" />`
3.  **Subsetting:** Only include the characters you need (e.g., only English characters).

---

## 3. Content Delivery Network (CDN)

A CDN is a network of servers distributed globally.

### How it works

1.  User in **London** requests `logo.png`.
2.  Request goes to the nearest CDN node (Edge Server) in **London**.
3.  If cached, return immediately (10ms).
4.  If not, fetch from Origin Server (e.g., **New York**), cache it, and return (100ms).

```mermaid
graph TD
    User[User in India]
    Origin[Origin Server (USA)]
    Edge[CDN Edge (Mumbai)]

    User -- 1. Request --> Edge
    Edge -- 2. Cache Miss --> Origin
    Origin -- 3. Return File --> Edge
    Edge -- 4. Cache & Return --> User

    User2[User 2 in India]
    User2 -- 5. Request --> Edge
    Edge -- 6. Cache Hit (Fast!) --> User2
```

---

## 4. Bundling Strategies (Webpack / Vite)

### Bundle Size Budgets

Set limits on your bundle size. If a PR increases the bundle size beyond the limit, the build fails.

- **Tool:** `bundlesize`, `webpack-bundle-analyzer`.

### Minification & Compression

- **Minification:** Removing whitespace, comments, and renaming variables to shorter names (e.g., `function calculateTotal()` -> `function a()`).
- **Compression:** Gzip or Brotli compression on the server. Brotli is generally better than Gzip.
