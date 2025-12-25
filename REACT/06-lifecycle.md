# Lifecycle (VVIMP)

Lifecycle = what happens to a component from creation to removal.

## Component lifecycle phases

1. Mounting (created + inserted into DOM)
2. Updating (re-render due to props/state)
3. Unmounting (removed from DOM)
4. Error handling (runtime errors in render lifecycle)

---

## Mounting phase

### Class lifecycle methods

- `constructor()`
- `static getDerivedStateFromProps()`
- `render()`
- `componentDidMount()`

**Order (mounting):**

```text
constructor -> getDerivedStateFromProps -> render -> componentDidMount
```

---

## Updating phase

Triggered by:

- state updates
- prop changes
- parent re-render

### Class lifecycle methods (update)

- `static getDerivedStateFromProps()`
- `shouldComponentUpdate()`
- `render()`
- `getSnapshotBeforeUpdate()`
- `componentDidUpdate()`

**Order (update):**

```text
getDerivedStateFromProps -> shouldComponentUpdate -> render -> getSnapshotBeforeUpdate -> componentDidUpdate
```

Functional components approximate lifecycle via `useEffect`:

- mount: `useEffect(..., [])`
- update: `useEffect(..., [dep])`
- unmount: cleanup function

---

## Unmounting phase

Class:

- `componentWillUnmount()`

Functional:

- cleanup from `useEffect`

---

## Error Boundaries

Error boundaries catch errors in:

- rendering
- lifecycle methods
- constructors of children

They do NOT catch:

- event handlers (use try/catch there)
- async code (promise rejections)

Only class components can be error boundaries.

```jsx
class ErrorBoundary extends React.Component {
  state = { hasError: false };

  static getDerivedStateFromError() {
    return { hasError: true };
  }

  componentDidCatch(error, info) {
    // log to monitoring
  }

  render() {
    if (this.state.hasError) return <h1>Something went wrong.</h1>;
    return this.props.children;
  }
}

// Usage
<ErrorBoundary>
  <App />
</ErrorBoundary>;
```

---

## Strict Mode

`<React.StrictMode>` enables extra checks in development.

Important behaviors (interview):

- intentionally double-invokes certain lifecycles/effects in dev to surface unsafe side effects
- helps detect deprecated APIs and side-effect bugs

Example:

```jsx
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);
```
