# Ti.Sentry

<img width="60" src="https://seeklogo.com/images/S/sentry-logo-32188C6881-seeklogo.com.png" > 

It is the Axway Titanium module for [sentry](https://github.com/joshdholtz/Sentry-Android).

Open-source error tracking that helps developers monitor and fix crashes in real time. Iterate continuously. Boost efficiency. Improve user experience. 

## How to use

### Initializing

First you have to add an entry in your tiapp.xml to reference your creds:

```xml
<property name="SENTRY_DSN_PRODUCTION" type="String">MY_SENTRY_DSN</property>
<property name="SENTRY_DSN_DEVELOPMENT" type="String">MY_SENTRY_DSN</property>
```

In app.js you can add a reference to module:

```javascript
var Sentry = require("ti.sentry");
```
Alternativly or additional you can add the creds with this method:

```javascript
Sentry.setDSN('MY_DSN_FROM_SENTRY_PORTAL');
```
### Starting automaticly crash reporting

```javascript
Sentry.startCrashReporting();
```

The method `Sentry.stopCrashReporting();` is also exposed. 

### Capture a message
```javascript
Sentry.captureMessage("Something significant may have happened");
```

### Capture custom event

```javascript
Sentry.captureEvent({
	message : "Being awesome"
	culprit : "Jon Doe"
});
```

## More methods:

Record that a user sent a HTTP POST to example.com and it was successful.

-  Sentry.addHttpBreadcrumb("http://example.com", "POST", 200);

Record the fact that user clicked a button to go from the main menu to the settings menu.

- Sentry.addNavigationBreadcrumb("user.click", "main menu", "settings");

Record a general,  application specific event

- Sentry.addBreadcrumb("user.state_change", "logged in");