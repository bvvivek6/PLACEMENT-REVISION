# Hooks (Frequently asked)

Hooks let functional components use state, lifecycle-like effects, and other React features.

## `useState`

```jsx
const [count, setCount] = React.useState(0);
setCount((c) => c + 1); // functional update to avoid stale state
```

---

## `useEffect`

Runs after render.

Common uses:

- data fetching
- subscriptions
- interacting with DOM APIs

```jsx
function User({ id }) {
  const [user, setUser] = React.useState(null);

  React.useEffect(() => {
    let cancelled = false;

    async function load() {
      const res = await fetch(`/api/users/${id}`);
      const data = await res.json();
      if (!cancelled) setUser(data);
    }

    load();
    return () => {
      cancelled = true;
    };
  }, [id]);

  return <pre>{JSON.stringify(user, null, 2)}</pre>;
}
```

---

## `useEffect` cleanup

The function returned from `useEffect` runs:

- before the effect runs again (on dependency change)
- when component unmounts

Example: event listener cleanup

```jsx
React.useEffect(() => {
  function onResize() {
    console.log(window.innerWidth);
  }

  window.addEventListener("resize", onResize);
  return () => window.removeEventListener("resize", onResize);
}, []);
```

---

## Dependency array

- `[]` => run once after mount (and cleanup on unmount)
- `[x]` => rerun when `x` changes
- no array => runs after every render (usually avoid)

**Interview gotcha:** If you use variables from component scope inside effect, they should usually be in deps.

---

## `useRef`

`useRef` stores a mutable value that persists across renders and does not trigger re-render.

1. DOM ref:

```jsx
const inputRef = React.useRef(null);
<input ref={inputRef} />;
```

2. Store previous value:

```jsx
function Example({ value }) {
  const prev = React.useRef(value);

  React.useEffect(() => {
    prev.current = value;
  }, [value]);

  return (
    <p>
      Prev: {prev.current}, Now: {value}
    </p>
  );
}
```

---

## `useMemo`

Memoizes a computed value.

```jsx
const filtered = React.useMemo(() => {
  return items.filter((x) => x.includes(query));
}, [items, query]);
```

Use it when:

- computation is expensive
- you must keep stable references for child memoization

---

## `useCallback`

Memoizes a function reference.

```jsx
const onSelect = React.useCallback((id) => {
  setSelectedId(id);
}, []);
```

Main purpose: prevent passing a “new function” each render to memoized children.

---

## `useContext`

Reads values from React Context (avoids prop drilling).

```jsx
const ThemeContext = React.createContext("light");

function Button() {
  const theme = React.useContext(ThemeContext);
  return <button className={theme}>OK</button>;
}
```

---

## Custom Hooks + Rules of Hooks

A custom hook is a function that starts with `use` and can call other hooks.

```jsx
function useOnlineStatus() {
  const [online, setOnline] = React.useState(navigator.onLine);

  React.useEffect(() => {
    const on = () => setOnline(true);
    const off = () => setOnline(false);
    window.addEventListener("online", on);
    window.addEventListener("offline", off);
    return () => {
      window.removeEventListener("online", on);
      window.removeEventListener("offline", off);
    };
  }, []);

  return online;
}
```

### Rules of hooks

- Call hooks at the top level (not inside loops/conditions)
- Call hooks only from React function components or custom hooks

Reason: React relies on hook call order to map state correctly.

---

## When NOT to use `useMemo` / `useCallback`

Avoid “memoization everywhere” because it has costs:

- extra memory
- extra comparisons
- more complexity

Use them only when you have:

- expensive computation
- large lists / heavy children + stable props needed
- measured re-render performance issue

Interview one-liner: “Use memoization as a performance tool, not as a default.”
