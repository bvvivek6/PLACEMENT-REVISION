# Common Interview Traps (VVIMP)

## Why keys should not be index

Using array index as a key breaks identity when items are inserted/removed/reordered.

Problem example:

- you render inputs in a list
- you insert an item at the top
- React reuses DOM nodes due to index keys
- the typed value appears in the wrong row

Better: use stable ids.

```jsx
{
  items.map((item) => <Row key={item.id} item={item} />);
}
```

---

## Why `useEffect` runs twice in Strict Mode

In React 18 dev + StrictMode, React intentionally re-runs effects to detect unsafe side effects.

This helps catch bugs like:

- subscriptions without cleanup
- code that assumes effect runs only once

Fix pattern:

- write idempotent effects
- always cleanup subscriptions

---

## Props mutation anti-pattern

Props are read-only. Mutating props causes unpredictable UI.

Bad:

```jsx
function Child({ user }) {
  user.name = "X"; // ❌
  return null;
}
```

Good: create a new object in state/parent.

---

## State mutation issues

Mutating state in-place breaks re-renders and memoization.

Bad:

```jsx
state.items.push(x); // ❌
setState(state);
```

Good:

```jsx
setState((prev) => ({ ...prev, items: [...prev.items, x] }));
```

---

## Context re-render problem

If your Context Provider value changes every render (new object reference), all consumers re-render.

Fix:

- memoize provider value

```jsx
const value = React.useMemo(() => ({ user, setUser }), [user]);
<AuthContext.Provider value={value}>{children}</AuthContext.Provider>;
```

---

## SEO challenges in React

Pure CSR can be hard for SEO because initial HTML may be mostly empty.

Solutions:

- SSR/SSG (Next.js)
- correct meta tags (including Open Graph)
- dynamic rendering where needed
