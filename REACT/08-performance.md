# Performance Optimization

## `React.memo`

Prevents re-render if props are shallow-equal.

```jsx
const Item = React.memo(function Item({ value }) {
  return <li>{value}</li>;
});
```

Use when:

- child is expensive
- props are stable (or can be made stable)

---

## Memoization

Memoization means caching results to avoid repeating expensive work.

Tools:

- `useMemo` (value)
- `useCallback` (function)
- `React.memo` (component output)

---

## Throttling / Debouncing

Used for frequent events like typing/scrolling.

- Debounce: run after the event stops for N ms
- Throttle: run at most once every N ms

Simple debounce example:

```jsx
function useDebouncedValue(value, delayMs) {
  const [debounced, setDebounced] = React.useState(value);

  React.useEffect(() => {
    const id = setTimeout(() => setDebounced(value), delayMs);
    return () => clearTimeout(id);
  }, [value, delayMs]);

  return debounced;
}
```

---

## Virtualization (react-window / react-virtualized)

Render only visible rows for large lists.

Concept:

```text
10000 items total
Only 20 visible in viewport
Render 20 (not 10000)
```

---

## Lazy rendering

Delay rendering heavy parts until needed:

- conditional rendering
- `React.lazy` + `Suspense`
- intersection observer for “render when visible”
