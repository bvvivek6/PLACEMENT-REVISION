# Accessibility (A11y) & Resilience

Building for everyone, and building for failure.

## 1. Accessibility (A11y)

Accessibility isn't just for disabled users; it improves UX for everyone (e.g., keyboard power users, people in bright sunlight).

### A. Semantic HTML

Use the right tag for the job.

- ✅ `<button onClick={...}>`
- ❌ `<div onClick={...}>` (Not focusable, no keyboard support)
- ✅ `<nav>`, `<main>`, `<article>`, `<aside>` (Helps screen readers navigate).

### B. Keyboard Navigation

- **Focus Management:** Users should be able to tab through all interactive elements.
- **Skip Links:** "Skip to content" link at the top to bypass navigation.
- **Focus Traps:** In a modal, focus should stay inside the modal until closed.

### C. ARIA (Accessible Rich Internet Applications)

Attributes to help screen readers when HTML isn't enough.

- `aria-label="Close"`: For an icon-only button.
- `aria-expanded="true"`: For a dropdown menu.
- `role="alert"`: For error messages.

### D. Color Contrast

Ensure text is readable against the background.

- **Tool:** Chrome DevTools "CSS Overview" or Lighthouse.
- **Ratio:** At least 4.5:1 for normal text.

---

## 2. Resilience & UX Patterns

How does your app handle failure?

### A. Optimistic UI

Update the UI _immediately_ when the user performs an action, assuming the server will succeed. If it fails, roll back.

- **Example:** "Like" button turns red instantly.
- **Benefit:** App feels instant.

```javascript
const handleLike = () => {
  // 1. Optimistic Update
  setLikes((l) => l + 1);

  // 2. API Call
  api.likePost(id).catch(() => {
    // 3. Rollback on error
    setLikes((l) => l - 1);
    showToast("Failed to like post");
  });
};
```

### B. Offline Mode

- **Detection:** `navigator.onLine`.
- **UX:** Show a banner "You are offline. Changes will be saved when you reconnect."
- **Storage:** Save actions to `IndexedDB` or `localStorage` and sync later.

### C. Graceful Degradation vs. Progressive Enhancement

- **Graceful Degradation:** Build the full modern app, then make sure it doesn't crash on old browsers (e.g., polyfills).
- **Progressive Enhancement:** Build a core experience that works with just HTML/CSS, then add JS for interactivity. (Better for resilience).
