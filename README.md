# Ti.Sentry

It is the axway android module for [sentry](https://github.com/joshdholtz/Sentry-Android).

## How to use

First you have to add an entry in your tiapp.xml:

```xml
<property name="SENTRY_DSN_PRODUCTION" type="String">MY_SENTRY_DSN</property>
<property name="SENTRY_DSN_DEVELOPMENT" type="String">MY_SENTRY_DSN</property>
```

In app.js:
```javascript
Ti.App.Sentry = require("ti.sentry");
```

### Capture a message
```javascript
Ti.App.Sentry.captureMessage("Something significant may have happened");
```

### Capture custom event

```javascript
Ti.App.Sentry.captureEvent({
	message : "Being awesome"
	culprit : "Jon Doe"
});
```

## More methods:

// Record that a user sent a HTTP POST to example.com and it was successful.
- [x] Ti.App.Sentry.addHttpBreadcrumb("http://example.com", "POST", 200);

// Record the fact that user clicked a button to go from the main menu to the
// settings menu.
- [x] Ti.App.Sentry.addNavigationBreadcrumb("user.click", "main menu", "settings");

// Record a general,  application specific event
- [x] Ti.App.Sentry.addBreadcrumb("user.state_change", "logged in");