# Routing

## Client-side routing

Client-side routing updates the URL without full page reload, and renders the matching component.

```text
URL changes -> router matches route -> React renders view
```

---

## React Router (concept)

React Router maps URLs to components.

Example (React Router v6 style):

```jsx
import { BrowserRouter, Routes, Route } from "react-router-dom";

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/profile" element={<Profile />} />
      </Routes>
    </BrowserRouter>
  );
}
```

---

## Nested routes

Nested routes render child routes inside a parent layout.

```jsx
<Route path="/dashboard" element={<DashboardLayout />}>
  <Route index element={<Overview />} />
  <Route path="settings" element={<Settings />} />
</Route>
```

---

## Route-based code splitting

Combine routing with `React.lazy` + `Suspense` to load route chunks only when visited.

See [Code Splitting](./09-code-splitting-lazy-loading.md).
