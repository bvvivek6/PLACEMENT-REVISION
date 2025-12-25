# Code Splitting & Lazy Loading

## Code Splitting

Split JS bundle into smaller chunks so users download only what they need.

Benefits:

- faster initial load
- better caching

---

## `React.lazy`

Dynamically import a component.

```jsx
const SettingsPage = React.lazy(() => import("./SettingsPage"));
```

---

## `Suspense`

Shows a fallback while the lazy component is loading.

```jsx
function App() {
  return (
    <React.Suspense fallback={<div>Loading…</div>}>
      <SettingsPage />
    </React.Suspense>
  );
}
```

---

## Route-level lazy loading

Lazy load entire routes so only visited pages are downloaded.

```jsx
const Home = React.lazy(() => import("./routes/Home"));
const Profile = React.lazy(() => import("./routes/Profile"));
```

---

## Component-level lazy loading

Lazy load heavy components (charts/editors) inside a page.

---

## Image lazy loading

Use native `loading="lazy"` when possible:

```html
<img src="/big.jpg" loading="lazy" alt="banner" />
```

For advanced cases, use IntersectionObserver.
