# Events & Forms

## What is `preventDefault()`?

`event.preventDefault()` stops the browser’s default behavior.

Example: prevent a form from refreshing the page.

```jsx
function Login() {
  function onSubmit(e) {
    e.preventDefault();
    // handle login with fetch
  }

  return (
    <form onSubmit={onSubmit}>
      <button type="submit">Login</button>
    </form>
  );
}
```

---

## Controlled Components (IMP)

A controlled input is when React state is the **single source of truth**.

```jsx
function NameForm() {
  const [name, setName] = React.useState("");

  return (
    <input
      value={name}
      onChange={(e) => setName(e.target.value)}
      placeholder="Enter name"
    />
  );
}
```

Pros:

- Easy validation
- Easy conditional UI
- Value always in sync with state

---

## Uncontrolled Components

An uncontrolled input stores its value in the DOM. You read it using a ref.

```jsx
function NameForm() {
  const inputRef = React.useRef(null);

  function onSubmit(e) {
    e.preventDefault();
    alert(inputRef.current.value);
  }

  return (
    <form onSubmit={onSubmit}>
      <input ref={inputRef} defaultValue="" />
      <button type="submit">Submit</button>
    </form>
  );
}
```

Pros:

- Less re-rendering while typing
- Simpler for quick forms

Cons:

- Harder validation and dynamic UI

---

## Refs vs controlled inputs

Use **controlled** when:

- You need validation, formatting, conditional disable/enable, live preview

Use **refs/uncontrolled** when:

- You need a quick input read on submit
- You integrate with non-React code or libraries

Rule of thumb (interview):

- Prefer controlled for business forms
- Uncontrolled is fine for small/simple cases
