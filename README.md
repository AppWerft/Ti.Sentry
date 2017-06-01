# Ti.Sentry

It is the axway android module for [sentry](https://github.com/joshdholtz/Sentry-Android).

## How to use

First you have to add an entry in your tiapp.xml:

```xml
<property name="SENTRY_DSN" type="String">MY_SENTRY_DSN</property>
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

