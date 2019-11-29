# Abstract
1. OAuth provides third party apps access to resources that identifies you on popular social networking sites. This document tries to understand and document the details of this popular access delegation protocol.

## OAuth
1. Definition
    1. An open standard for access delegation, commonly used as a way for Internet users to grant websites or applications access to their information on other websites but without giving them the passwords.
        1. This mechanism is used by companies such as Amazon, Google, Facebook, Microsoft and Twitter to permit the users to share information about their accounts with third party apps and websites
2. History
    1. OAuth discussion group was created in April 2007 and OAuth Core 1.0 drafted and released in December 4 2007
    2. OAuth 1.0 protocol was published as RFC 5849, an informational Request for Comments in April 2010.
    3. Since August 31, 2010, all third party Twitter apps have been required to use OAuth.
    4. The OAuth 2.0 framework was published as RFC 6749, and the Bearer Token Usage as RFC 6750, both standards track Request for Comments in October 2012
3. About OAuth 2.0
    1. OAuth 2.0 is not backwards compatible with OAuth 1.0 and it provides specific authorization flows for web and desktop apps, mobile, and smart devices.
    2. Facebook's Graph API only supports OAuth 2.0. Google supports OAuth 2.0 as the recommended authorization mechanism for all of its APIs. Microsoft also supports OAuth 2.0 for various APIs and its Azure Active Directory service, which is used to secure many Microsoft and third party APIs.
4. Workflow
    1. OAuth doesn't assume the Client is a web browser
    2. Steps
        1. An end user clicks on the "Login" button at Resource Server, and the end user is the client.
        2. The resource server presents the client with an Authorization grant, and redirects the client to the Authorization server
        3. The Client requests an Access Token from the Authorization Server using the Authorization Grant Code
        4. Th Client logs into the Authorization server, and if the code is valid, the Client gets and Access Token that can be used request a protected resource from the Resource Server
        5. After receiving a request for a protected resource with an accompanying Access Token, the Resource Server verifies the validity of the token directly with the Authorization Server
        6. If the token was valid, the Authorization Server sends information about the Client to the Resource Server

## RFC 6749
### Terminology
1. Roles
    1. Resource owner
        1. An entity capable of granting access to a protected resource. When the resource owner is a person, it is referred to as an end-user
    2. Resource server
        1. The server hosting the protected resources, capable of accepting and responding to protected resource requests using access token.
    3. Client
        1. An app making protected requests on behalf of the resource owner and with its authorization. The term does not imply any particular implementation characteristics
    4. Authorization server
        1. The server issuing access tokens to the client after successfully authenticating the resource owner and obtaining authorization.
2. Protocol Flow
    1. The client requests authorization from the resource owner. The authorization request can be made directly to the resource owner, or preferably indirectly via the authorization server as an intermediary.
    2. The client receives an authorization grant, which is a credential representing the resource owner's authorization, expressed using one of four grant types. The authorization grant type depends on the method used by the client to request authorization and the types supported by the authorization server.
    3. The client requests an access token by authenticating with the authorization server and presenting the authorization grant.
    4. The authorization server authenticates the client and validates the authorization grant, and if valid, issues an access token.
    5. Client requests the protected resource from the resource server and authenticates by presenting the access token.
    6. The resource server validates the access token, and if valid, serves the request.
        1. The preferred method for client to obtain an authorization grant from the resource owner is to use the authorization server as an intermediary.
3. Authorization Grant
    1. Definition
        1. A credential representing the resource owner's authorization used by the client to obtain an access token. 
    2. Four grant types
        1. Authorization code
            1. The client directs the resource owner to an authorization server, which in turn directs the resource owner back to the client **with the authorization code**.
            2. Before directing the resource owner back to the client with the authorization code, the authorization server authenticates the resource owner and obtains authorization. Because the resource owner only authenticates with the authorization server, the resource owner's credentials are never shared with the client.
            3. Benefits are the ability to authenticate the client, as well as the transmission of the access token directly to the client without passing it through the resource owner's user-agent and potentially exposing it to others, including the resource owner.
        2. Implicit
            1. Instead of issuing the client an authorization code, the client is issued an access token directly. The grant type is implicit as **no intermediate credentials (authorization code) are issued**.
            2. The client identity can be verified via redirection URI used to deliver the access token to the client. The access token may be exposed to the resource owner or other apps with access to the resource owner's user-agent.
        3. resource owner password credentials
            1. Used directly as an authorization grant to obtain an access token. The credentials should only be used when there is a high degree of trust between the resource owner and the client (only if client is part of the device OS or highly privileged app), and when other auth grant types are not available.
            2. The resource owner credentials are used for a single request and are exchanged for an access token. It eliminates the need for the client to store the resource owner credentials for future user, by exchanging the credentials with a long-lived access token or refresh token.
        4. client credentials
            1. Can be used as an authorization grant when the authorization scope is limited to the protected resources under the control of the client, or to protected resources previously arranged with the authorization server.
            2. Used as an authorization grant typically when the client is acting on its own behalf or is requesting access to protected resources based on an authorization previously arranged with the authorization server
4. Access Token
    1. Credentials used to access protected resources.
    2. A string representing an authorization issued to the client.
    3. Tokens represent specific scopes and durations of access, granted by the resource owner, and enforced by the resource server and authorization server.
    4. Tokens can have different formats, structures, and methods of utilization based on the resource server security requirements.
5. Refresh Token
    1. Credentials used to obtain access tokens.
    2. Issued to the client by the authorization server and are used to obtain a new access token when the current access token expires. It is included with access token issuance by authorization server
6. TLS Version
    1. TLSv1.2 is used but will vary over time based on the widespread deployment and known security vulnerabilities.
7. HTTP Redirections
    1. HTTP 302 Status code is used.
    2. Other redirection method is allowed and considered as implementation details
8. Interoperability
    1. OAuth 2.0 provides a rich authorization framework with well-defined security properties.
    2. However, because its richness, it may produce a wide range of non-interoperable implementations.
    3. It leaves a few required components partially or fully undefined.

### Protocol Endpoints
1. The authorization process utilizes two authorization server endpoints and one client endpoint
    1. Authorization endpoint - used by the client to obtain authorization from the resource owner via user-agent redirection.
    2. Redirection endpoint - used by the authorization server to return response containing authorization credentials to the client via the resource owner user-agent.
    3. Token endpoint - used by the client to exchange an authorization grant for an access token, typically with client authentication.


## Security
1. Client Impersonation
    1. A malicious client can impersonate another client and obtain access to protected resources if the impersonated client fails to or is unable to, keep its client credentials confidential.
2. Access Tokens
    1. Access token credentials **must be kept confidential** in transit and storage, and only shared among the authorization server, the resource servers the access token is valid for, and the client to whom the access token is issued.
    2. The authorization server must ensure that access tokens cannot be generated, modified, or guessed to produce valid access tokens by unauthorized parties.
3. Refresh Tokens
    1. It **must be kept confidential** in transit and storage, and shared only among authorization server and the client to whom the refresh tokens were issued.
4. Authorization Code
    1. The transmission of authorization codes should be made over a secure channel, and the client should require the use of TLS with its redirection URI if the URI identifies a network resource.
    2. It should be a single use and revoke all access tokens already granted based on the compromised authorization code.
5. Authorization Code Redirection URI Manipulation
    1. An attacker may trick user-agent to modify the authorization server redirect uri to its own and thus gain authorization code.
    2. To prevent such an attack, the authorization server must ensure that the redirection URI used to obtain the authoriation code is identical to the redirection URI provided when exchanging the authorization code for an access token.
6. Resource Owner Password Credentials
    1. Often used for legacy or migration reasons
    2. It reduces the overall risk of storing usernames and passwords by the client but does not eliminate the need to expose highly privileged credentials to the client.
7. Request Confidentiality
    1. Access token, refresh tokens, resource owner passwords, and client credentials **must not be transmitted in the clear**. Authorization Code **should not be transmitted in the clear**.
8. Ensuring Endpoint Authenticity
    1. The authorization server must require the use of TLS with server authentication to prevent MITM attacks.
9. Credential-Guessing Attacks
    1. The authorization server must prevent attackers from guessing access tokens, authorization codes, refresh tokens, resource owner passwords, and client credentials.
10. Phishing Attacks
    1. If end-users are not careful to verify the authenticity of websites being redirected before entering their credentials, it will be possible for attackers to exploit this practice to steal resource owners' passwords.
11. Cross-Site Request Forgery
    1. An exploit in which an attacker causes the user-agent of a victim end-user to follow a malicious URI to a trusting server which allows an attacker to inject its own authorization code or access token, which can result in the client using an access token associated with the attacker's protected resources rather than the victim's.
    2. The client must implement CSRF protection for its redirection URI. It's typically accomplished by requiring any request sent to the redirection URI endpoint to include a value that binds the request to the user-agent's authenticated state (e.g., a hash of the session cookie used to authenticate the user-agent). The client should utilize the 'state' request param to deliver this value to the authorization server when making an authorization request.