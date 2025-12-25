# Components

## What are Functional Components?

A functional component is a JavaScript function that returns JSX.

```jsx
function Greeting({ name }) {
  return <h1>Hello, {name}</h1>;
}
```

Modern React uses functional components + hooks for state, lifecycle, and refs.

---

## What are Class Components?

A class component is an ES6 class that extends `React.Component`.

```jsx
class Counter extends React.Component {
  state = { count: 0 };

  render() {
    return (
      <button onClick={() => this.setState({ count: this.state.count + 1 })}>
        Count: {this.state.count}
      </button>
    );
  }
}
```

Class components are still supported but are asked mostly for lifecycle questions.

---

## What are Stateless Components?

Stateless usually means the component:

- does not manage its own state (`useState`/`this.state`)
- is driven entirely by props

```jsx
function PriceTag({ amount }) {
  return <span>₹{amount}</span>;
}
```

Note: with hooks, any functional component _can_ be stateful.

---

## What are Pure Components? (IMP)

**Pure** means: “Render the same output for the same inputs.”

In React, purity matters because React can optimize rendering when components are pure.

### Class `PureComponent`

`React.PureComponent` automatically implements a shallow comparison for props/state.

```jsx
class UserRow extends React.PureComponent {
  render() {
    return <div>{this.props.user.name}</div>;
  }
}
```

### Functional equivalent: `React.memo`

```jsx
const UserRow = React.memo(function UserRow({ user }) {
  return <div>{user.name}</div>;
});
```

**Gotcha:** shallow compare means if you mutate objects/arrays in-place, React may not re-render.

---

## Composable Components

Composition means building complex UIs by combining simpler components.

```jsx
function Card({ title, children }) {
  return (
    <section>
      <h2>{title}</h2>
      <div>{children}</div>
    </section>
  );
}

function Profile() {
  return (
    <Card title="User">
      <p>Name: Vivek</p>
    </Card>
  );
}
```

---

## Render Props

A “render prop” is a prop whose value is a function that returns UI.

```jsx
function Mouse({ render }) {
  const [pos, setPos] = React.useState({ x: 0, y: 0 });

  return (
    <div
      style={{ height: 200, border: "1px solid #ccc" }}
      onMouseMove={(e) => setPos({ x: e.clientX, y: e.clientY })}
    >
      {render(pos)}
    </div>
  );
}

function App() {
  return (
    <Mouse
      render={({ x, y }) => (
        <p>
          {x}, {y}
        </p>
      )}
    />
  );
}
```

Why asked: it’s an older but important reuse pattern (before hooks).

---

## `children` prop

`children` is whatever is nested inside a component.

```jsx
function Layout({ children }) {
  return (
    <main>
      <header>Header</header>
      {children}
      <footer>Footer</footer>
    </main>
  );
}

// Usage
<Layout>
  <h1>Home</h1>
</Layout>;
```

---

## Fragments

Fragments let you return multiple elements without adding an extra DOM node.

```jsx
return (
  <>
    <li>A</li>
    <li>B</li>
  </>
);
```

---

## Keys in lists

Keys help React identify list items between renders.

```jsx
{
  users.map((u) => <UserRow key={u.id} user={u} />);
}
```

Rules:

- Use a stable, unique key (usually an id)
- Avoid using array index as key (see traps in [Common Interview Traps](./14-common-interview-traps.md))
