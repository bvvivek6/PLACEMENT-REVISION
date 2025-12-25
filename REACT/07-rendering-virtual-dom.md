# Rendering & Virtual DOM

## Virtual DOM

The Virtual DOM is an in-memory representation of the UI (a tree of React elements).

React does NOT directly mutate the real DOM for every change. Instead:

1. Create a new virtual tree
2. Compare with previous tree (diff)
3. Apply minimal changes to real DOM

---

## What is Diffing algorithm?

Diffing is the process of comparing old vs new Virtual DOM trees to determine updates.

Heuristics React uses (simplified):

- Different element type => replace subtree
- Same type => update attributes + recurse into children
- Lists use `key` to match items across renders

---

## Reconciliation

Reconciliation is the full process of:

- rendering new React elements
- diffing with previous elements
- committing changes to the DOM

---

## Why Virtual DOM is faster (interview-safe answer)

Not “because virtual DOM is always faster”, but because:

- Direct DOM operations are relatively expensive
- React batches work and applies minimal DOM changes
- It reduces unnecessary updates by diffing and memoization

---

## Performance considerations of Virtual DOM

Virtual DOM still has costs:

- rendering component functions (CPU)
- diffing large trees

Optimizations:

- stable keys
- memoization (`React.memo`, `useMemo`, `useCallback`)
- virtualization for big lists

---

## Batch updates (VIMP)

Batching groups multiple state updates into a single re-render.

Example:

```jsx
function Demo() {
  const [a, setA] = React.useState(0);
  const [b, setB] = React.useState(0);

  function onClick() {
    setA((x) => x + 1);
    setB((x) => x + 1);
    // React batches => usually 1 render
  }

  return (
    <button onClick={onClick}>
      a={a}, b={b}
    </button>
  );
}
```

React 18 does more batching automatically (see [React 18](./12-react-18-modern.md)).
