# Abstract

- This document explores different types of IAM provided by GitHub

## SAML SSO for GitHub organization

1. You can access an organization that uses SAML single sign-on

## How GitHub authorizes OAuth Apps

### OAuth GitHub Web App Flow

1. High level
   1. Users are redirected to request their GitHub identity
   2. Users are directed back to your site by GitHub
   3. Your app accesses the API with the user's access token
2. Steps
   1. Users are redirected to request their GitHub identity
      1. GET https://github.com/login/oauth/authorize
      2. Params
         1. client_id(required)
            1. the id you receive from GitHub when you first register.
         2. redirect_uri
            1. the URL in your app where users will be sent after authorization.
         3. scope
            1. A space-delimited list of scopes. If not specified defaults to empty list for users that have not authorized any scopes for the app.
            2. If the scope is not provided and user has already authorized token with scopes, then a token with existing scope will be returned
         4. state
            1. An unguessable random string used to protect against cross-site request forgery attacks
         5. allow_signup
            1. Whether or not unauthenticated users will be offerred an option to sign up for GitHub during the OAuth flow. Defaults to true.
   2. Users are directed back to your site by GitHub
      1. If the user accepts your request, GitHub redirects back to your site with a temporary **code** in a code parameter as well as a state you provided in the previous step in a **state** parameter.
      2. If the states don't match, the request was created by a third party and the process should be aborted.
      3. Exchange this **code** for an access token
      4. POST https://github.com/login/oauth/access_token
         1. client_id (required)
            1. The client ID you received from GitHub for your GitHub App
         2. client_secret (required)
            1. The client secret you received from the GitHub for your GitHub App.
         3. Code (required)
            1. The code received from GitHub response above.
         4. redirect_uri
            1. The URL in your app where users are sent after authorization.
         5. state
            1. The unguessable random string you provided in Step 1
      5. Response
         1. access_token=e72e16.....
      6. If Accept: application/json
         1. {"access_token": "e72...", "scope": "repo,gist", "token_type": "bearer"}
      7. If Accept: application/xml
         1. `<OAuth>... token_type, scope, access_token ... </OAuth>`
   3. Use the access token to access the API
      1. This access token allows you to make requests to the API on behalf of a user
         1. GET https://api.github.com/user?access_token=...
      2. You can pass the token in the query params or header
         1. Authorization: token OAUTH-TOKEN

## Authenticating to a GitHub org with SAML SSO

1. About authentication
   1. You can access an org that uses SAML by authenticating through an IdP.
   2. To use the API or Git on the CLI with an org that enforces SAML SSO, you will need to use an authorized SSH key or an authroized personal access token over HTTPS.
2. Use
   1. If you have an active SAML session in your browser, you are automatically authorized when you access a GitHub organization that uses SAML SSO
   2. If you don't have an active SAML session in your browser, you must enter the credentials for your SAML identity provider before you can access the org.
   3. You must periodically log into your SAML provider to authenticate and gain access to the org's resources on GitHub. The duration of this login period is specified by your IdP and is generally 24 hours.
      1. After this period, you have to re-identify yourself to continue.
      2. OAuth App access tokens are authorized by default.

## Managing member identity and access in your organization with SAML SSO

1. Benefits
   1. SAML web browser SSO allows administrators to use an identity provider to manage the identities of their users and the applications they use. Organization members can authenticate with an identity provider that grants access to your GitHub organization.
2. Features
   1. Organization admins can invite members to connect their existing GitHub user accounts to supported IdP. SAML SSO gives organizations **a centralized and secure way of controlling access to their resources** on GitHub and helps organization members maintain control of their identity and contributions.
   2. Org members sign in through the org's IdP, and their existing GitHub account is linked to an external identity that belongs to the organization. The external identity is separate from, but related to, their GitHub account and is used to control access to organization's resources like **repositories, issues, and pull requests**.
3. Supports
   1. Limited support for all identity providers that implement the SAML 2.0 standard
   2. Identity providers that have been internally tested and officially supported are:
      1. Active Directory Federation Services (AD FS)
      2. Azure Active Directory (Azure AD)
      3. Okta
      4. OneLogin
      5. PingOne
      6. Shibboleth
   3. SCIM IdP members are automatically invited to join GitHub org when access is provisioned in your IdP and will be automatically removed from the GitHub org when their access is removed from your IdP
   4. GitHub does not support SAML Single Logout. To terminate an active SAML session, users should log out directly on your SAML server.
4. What is SCIM
   1. Definition
      1. System for Cross-domain Identity Management( SCIM) allows admin to automate the exchange of user identity information between systems.
   2. Feature
      1. An admin can deprovision an org member using SCIM and automatically remove the member from the org.
      2. Without implementing SCIM, the access won't be remove even after the session expire. To remove
         1. An admin have to manually remove the authorized token from the org or automate its removal with SCIM.
