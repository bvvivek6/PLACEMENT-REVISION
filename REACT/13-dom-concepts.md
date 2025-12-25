# DOM Concepts

## Shadow DOM

Shadow DOM is a browser feature for encapsulating DOM + styles (used by Web Components).

Why it matters:

- prevents CSS leaking in/out
- isolates component internals

React itself does not require Shadow DOM, but React can render inside shadow roots if needed.

---

## Event delegation

Event delegation attaches a single handler to a parent and uses event bubbling.

React uses event delegation internally (Synthetic Events) to reduce the number of listeners.

---

## Synthetic vs native events

- Native events: browser `Event` objects
- Synthetic events: React wrapper around native events for consistency across browsers

In React:

```jsx
<button
  onClick={(e) => {
    // e is a SyntheticEvent (wraps native event)
  }}
>
  Click
</button>
```

You can access the native event via `e.nativeEvent`.
