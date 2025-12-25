# React 18 / Modern React

## Concurrent Rendering

Concurrent rendering lets React prepare renders in the background and keep the app responsive.

Conceptually:

- React can interrupt rendering work
- prioritize urgent updates (typing) over non-urgent work

---

## Automatic batching

React 18 batches more updates automatically (including inside timeouts/promises in many cases).

Why it matters:

- fewer renders
- better performance

---

## Streaming SSR

Streaming SSR sends HTML in chunks so the browser can start showing content sooner.

Idea:

- server streams parts of the page as they become ready
- improves time-to-first-byte and perceived performance

---

## React Server Components (RSC)

Server Components run on the server and can:

- access server-only resources (DB, filesystem)
- avoid sending certain code to the client

Key idea (interview):

- not everything must be hydrated on client
- you can mix server + client components (framework-dependent, e.g., Next.js)

---

## React 19 (Recently introduced)

React 19 is a stable release that adds **Actions**, new APIs/hooks, and better support for modern rendering (SSR/Streaming/RSC).

## Actions (big interview topic)

Actions are a pattern for handling async mutations (like form submissions) with built-in support for:

- pending state
- errors (works well with Error Boundaries)
- optimistic UI

### 1) Async transitions as Actions

```jsx
function UpdateName({ updateName }) {
  const [name, setName] = React.useState("");
  const [error, setError] = React.useState(null);
  const [isPending, startTransition] = React.useTransition();

  function onSubmit() {
    startTransition(async () => {
      const err = await updateName(name);
      if (err) setError(err);
    });
  }

  return (
    <>
      <input value={name} onChange={(e) => setName(e.target.value)} />
      <button onClick={onSubmit} disabled={isPending}>
        Update
      </button>
      {error && <p>{error}</p>}
    </>
  );
}
```

### 2) `<form>` Actions + `useActionState`

React DOM supports passing a function to the `action`/`formAction` props.

```jsx
function ChangeName({ updateName }) {
  const [error, submitAction, isPending] = useActionState(
    async (prevError, formData) => {
      const newName = formData.get("name");
      const err = await updateName(newName);
      return err ?? null;
    },
    null
  );

  return (
    <form action={submitAction}>
      <input name="name" />
      <button type="submit" disabled={isPending}>
        Update
      </button>
      {error && <p>{error}</p>}
    </form>
  );
}
```

Note: `useActionState` is imported from React:

```js
import { useActionState } from "react";
```

### 3) `useFormStatus` (from `react-dom`)

Useful for reusable design-system buttons that need to know if the nearest form is pending.

```jsx
import { useFormStatus } from "react-dom";

function SubmitButton() {
  const { pending } = useFormStatus();
  return (
    <button type="submit" disabled={pending}>
      {pending ? "Saving…" : "Save"}
    </button>
  );
}
```

### 4) `useOptimistic`

Shows optimistic UI while the request is in-flight.

```jsx
function NameEditor({ currentName, save }) {
  const [optimisticName, setOptimisticName] = React.useOptimistic(currentName);

  async function action(formData) {
    const next = formData.get("name");
    setOptimisticName(next);
    await save(next);
  }

  return (
    <form action={action}>
      <p>Preview: {optimisticName}</p>
      <input name="name" defaultValue={currentName} />
      <SubmitButton />
    </form>
  );
}
```

---

## New API: `use`

`use` lets you read resources in render (commonly used with Suspense-enabled frameworks/libraries).

```jsx
import { use, Suspense } from "react";

function Comments({ commentsPromise }) {
  const comments = use(commentsPromise);
  return comments.map((c) => <p key={c.id}>{c.text}</p>);
}

function Page({ commentsPromise }) {
  return (
    <Suspense fallback={<div>Loading…</div>}>
      <Comments commentsPromise={commentsPromise} />
    </Suspense>
  );
}
```

Important note: `use` does not support “uncached promises created in render” in Client Components (framework/library should provide caching).

---

## Quality-of-life improvements

### `ref` as a prop (reduces need for `forwardRef`)

```jsx
function MyInput({ placeholder, ref }) {
  return <input placeholder={placeholder} ref={ref} />;
}
```

### `<Context>` as a provider (instead of `<Context.Provider>`)

```jsx
const ThemeContext = React.createContext("light");

function App({ children }) {
  return <ThemeContext value="dark">{children}</ThemeContext>;
}
```

### Cleanup function for callback refs

```jsx
<input
  ref={(node) => {
    // setup
    return () => {
      // cleanup when removed
    };
  }}
/>
```

---

## Better SSR/Streaming + asset handling (high level)

React 19 adds improvements like:

- better hydration mismatch diffs and error reporting
- support for rendering metadata tags (`<title>`, `<meta>`, `<link>`) inside components (React hoists them to `<head>`)
- improved support for stylesheets ordering via `precedence`
- resource preloading APIs via `react-dom` (e.g., `preload`, `preconnect`)
- new static generation APIs in `react-dom/static` (e.g., `prerender`)
- improved compatibility with custom elements (Web Components)
