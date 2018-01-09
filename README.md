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
Ti.App.addEventListener("uncaughtException",function(e){
	Ti.App.Sentry.captureEvent({
		line: e.line,
		message: e.message,
		title: e.title,
		sourceName : e.sourceName,
		lineSource : e.lineSource
	});
})
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

Record that a user sent a HTTP POST to example.com and it was successful.

-  Ti.App.Sentry.addHttpBreadcrumb("http://example.com", "POST", 200);

Record the fact that user clicked a button to go from the main menu to the settings menu.

- Ti.App.Sentry.addNavigationBreadcrumb("user.click", "main menu", "settings");

Record a general,  application specific event

- Ti.App.Sentry.addBreadcrumb("user.state_change", "logged in");