# Observability for Frontend

"If you can't measure it, you can't improve it."

## 1. Monitoring Web Vitals (RUM)

**RUM (Real User Monitoring):** Tracking performance data from actual users, not just your local machine.

### Tools

- Google Analytics 4 (Basic)
- Vercel Analytics
- New Relic / Datadog

### What to track?

- **Core Web Vitals:** LCP, INP, CLS.
- **Custom Metrics:** "Time to First Tweet", "Checkout Success Rate".

```javascript
import { onLCP, onINP, onCLS } from "web-vitals";

function sendToAnalytics(metric) {
  const body = JSON.stringify(metric);
  // Use `navigator.sendBeacon` to ensure data is sent even if the user closes the tab
  navigator.sendBeacon("/analytics", body);
}

onLCP(sendToAnalytics);
onINP(sendToAnalytics);
onCLS(sendToAnalytics);
```

---

## 2. Error Tracking

When a user's app crashes, you need to know _why_.

### Tools

- **Sentry** (Industry Standard)
- LogRocket

### Source Maps

Production code is minified (`function a(){}`). Source maps map this back to your original code (`function calculateTotal(){}`).

- **Security:** Don't expose source maps to the public if you want to hide your code structure. Upload them privately to Sentry.

### Error Boundaries (React)

Catch errors in a component tree so the whole app doesn't crash.

```javascript
class ErrorBoundary extends React.Component {
  state = { hasError: false };

  static getDerivedStateFromError(error) {
    return { hasError: true };
  }

  componentDidCatch(error, errorInfo) {
    logErrorToSentry(error, errorInfo);
  }

  render() {
    if (this.state.hasError) {
      return <h1>Something went wrong.</h1>;
    }
    return this.props.children;
  }
}
```

---

## 3. Session Replay

Tools like **LogRocket** or **FullStory** record a video-like replay of the user's session.

- **Use Case:** A user reports "The checkout button doesn't work." You watch the replay and see they were clicking the wrong area or a popup was blocking it.
- **Privacy:** Ensure you mask sensitive inputs (passwords, credit cards) so they aren't recorded.
