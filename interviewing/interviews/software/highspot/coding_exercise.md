Highspot Coding Exercise
Welcome to the Highspot interview process! For this exercise, you will be creating a webhook payload viewer. Webhooks are a common way to trigger automation, but they're sometimes poorly-documented and opaque. Your app will collect and display a webhook's payload as a first step to understanding its API. This exercise should take less than two hours to complete.

Overview
In the programming language of your choice, create a web application to capture and display the body of any HTTP POST request made to the app.

Background
Why a take-home exercise?
In our experience take-home exercises, compared to technical phone screens, are more objective, and they facilitate a more equitable interview process.

Furthermore, in the normal course of software development, you have the freedom to mine your previous assignments, search Stack Exchange and Google, solicit advice from friends and relatives, and engage in quiet contemplation in order to solve problems. We do that too, and we'd like to see you exhibit a real-world-style work product.

How much time should I invest?
Highspot devs have completed this exercise ourselves, and we think that an hour or two of development time is reasonable for an experienced engineer. Spend more or less time on this, it's up to you, but please don't let perfect be the enemy of good — we'd rather see something that illustrates your talents than miss out on a chance to work with you.

We respect your time and we will accept and review any solution you submit, full or partial. If you can't invest the time to show us your best work, we're open to discussing alternatives.

Considerations
Logistics
Assume that other people have to run, read, and support your code, that we're going to run tests against it, and that future assignments will build upon it.
Use any language, tools, or solutions you see fit.
OK, let's go!
Project Requirements
The app must:

Support multiple unique endpoints to enable simultaneous testing of several webhooks at once.
Be a stateless service with a backing datastore for persistence.
Have a functional health check.
Execute within a Docker container.

Example Flow
User navigates to app root (http://svc/).
App generates unique URI endpoint and responds with a unique endpoint location (e.g., Location: http://svc/<guid>).
User configures the webhook to POST to the generated URI, then triggers a test event.
User issues a GET request to the URI and sees the most recent POST body.

Project Delivery
Send your working code and your README, which should also include instructions for how to run your project, including instructions about any dependencies.

What happens next?
After you submit your code, we will evaluate it, and contact you about next steps, which may involve further elaboration on your code submission.

You can use this dropbox account to upload the finished exercise: https://www.dropbox.com/sh/3xvsah3vlmafw65/AABesxn_6ZDnBYtfiGyIwkSUa?dl=0 

Thanks again for your time and we look forward to receiving your reply.

The Highspot Engineering Team

Got it, thanks!Thanks, I'll take a look.Done.
