# State Management

## Context API

Context shares values across the component tree without prop drilling.

```jsx
const AuthContext = React.createContext(null);

function AuthProvider({ children }) {
  const [user, setUser] = React.useState(null);
  return (
    <AuthContext.Provider value={{ user, setUser }}>
      {children}
    </AuthContext.Provider>
  );
}

function Profile() {
  const { user } = React.useContext(AuthContext);
  return <div>{user?.name}</div>;
}
```

**Context re-render note:** when provider value changes, all consumers may re-render.

---

## Redux basics

Redux is a predictable global state container.

Core ideas:

- single store
- state updates via actions
- reducers produce next state immutably

Flow diagram:

```mermaid
flowchart LR
UI[UI dispatch(action)] --> MW[Middleware]
MW --> Store[Store]
Store --> Reducer[Reducer]
Reducer --> Store
Store --> UI
```

---

## Redux Toolkit

Redux Toolkit (RTK) is the modern recommended way to write Redux:

- `configureStore`
- `createSlice`
- less boilerplate

---

## `useSelector` / `useDispatch`

- `useDispatch()` sends actions
- `useSelector()` reads state

```jsx
import { useDispatch, useSelector } from "react-redux";

function Counter() {
  const count = useSelector((s) => s.counter.value);
  const dispatch = useDispatch();

  return (
    <button onClick={() => dispatch({ type: "counter/increment" })}>
      {count}
    </button>
  );
}
```

---

## Middleware

Middleware intercepts actions for:

- logging
- async (thunks)
- analytics

---

## Zustand (optional)

Zustand is a lightweight state management library.

Skip in interviews if you already know Redux well.

---

## When NOT to use Redux

Don’t add Redux if:

- state is local to a small part of UI
- Context + local state is enough
- you only need server state (prefer React Query/SWR patterns)

Interview one-liner: “Use Redux for complex shared state, not by default.”
