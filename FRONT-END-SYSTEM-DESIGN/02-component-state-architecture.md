# Component & State Architecture

A scalable frontend requires a clear separation of concerns in both UI components and data management.

## 1. Component Design Patterns

### Container vs. Presentational Components

Separating logic (how things work) from UI (how things look).

- **Presentational (Dumb) Components:**
  - Concerned with _how things look_.
  - Receive data and callbacks via props.
  - Have no dependency on the rest of the app (e.g., Redux stores).
  - Example: `Button`, `List`, `Card`.
- **Container (Smart) Components:**
  - Concerned with _how things work_.
  - Provide data and behavior to presentational or other container components.
  - Call APIs, manage state.
  - Example: `UserListContainer`, `DashboardPage`.

**Code Example:**

```javascript
// Presentational
const UserList = ({ users, onSelect }) => (
  <ul>
    {users.map((user) => (
      <li key={user.id} onClick={() => onSelect(user.id)}>
        {user.name}
      </li>
    ))}
  </ul>
);

// Container
const UserListContainer = () => {
  const [users, setUsers] = useState([]);

  useEffect(() => {
    fetch("/api/users")
      .then((res) => res.json())
      .then(setUsers);
  }, []);

  const handleSelect = (id) => console.log("Selected:", id);

  return <UserList users={users} onSelect={handleSelect} />;
};
```

### Controlled vs. Uncontrolled Components

- **Controlled:** Form data is handled by a React component. The source of truth is the React state.
- **Uncontrolled:** Form data is handled by the DOM itself. Accessed via refs.

---

## 2. State Management Architecture

Deciding where state lives is the hardest part of frontend design.

### Types of State

1.  **Local State (UI State):**

    - Lives in a single component.
    - Examples: Form input values, modal open/close, active tab.
    - _Tools:_ `useState`, `useReducer`.

2.  **Global State (Client State):**

    - Shared across many components.
    - Examples: User theme preference, sidebar toggle, authentication status.
    - _Tools:_ Context API, Redux, Zustand, Recoil.

3.  **Server State (Remote State):**
    - Data that comes from an API.
    - Needs caching, deduplication, background updates.
    - _Tools:_ React Query (TanStack Query), SWR, Apollo Client.

### Key Concept: Server State ≠ UI State

Don't put API data in Redux unless you manually handle loading, error, and caching states. Use a dedicated tool like React Query.

**Architecture Diagram:**

```mermaid
graph TD
    API[Backend API]

    subgraph Frontend
        RQ["Server State Manager<br/>(React Query)"]
        Global["Global Store<br/>(Zustand/Context)"]

    API <--> RQ
    RQ --> CompA
    RQ --> CompB

    Global --> CompB
    Global --> CompC

    CompA -- Local State --> CompA
```

### When to use what?

| Scenario                                       | Solution                                 |
| :--------------------------------------------- | :--------------------------------------- |
| Is the data used only here?                    | **Local State** (`useState`)             |
| Is the data used in many places (e.g., Theme)? | **Global State** (`Context` / `Zustand`) |
| Is the data from an API?                       | **Server State** (`React Query`)         |
| Is it complex form state?                      | **Form Library** (`React Hook Form`)     |

---

## 3. Reusable UI Components (Design Systems)

When designing a system, think about the "Atomic Design" principle:

1.  **Atoms:** Buttons, Inputs, Labels.
2.  **Molecules:** Search Bar (Input + Button).
3.  **Organisms:** Header (Logo + Nav + Search Bar).
4.  **Templates:** Page Layouts.

**Interview Tip:**
"I build components to be 'open for extension but closed for modification'. I use props for configuration and composition (children) to avoid prop drilling."
