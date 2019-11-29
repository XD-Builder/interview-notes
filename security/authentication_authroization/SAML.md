# Abstract
* This document introduces SAML

## SAML
1. Definition
    1. Security Assertion Markup Language (SAML) is an open standard for exchanging authentication and authorization data between parties, in particular between an identity provider and service provider.
    2. SAML is an XML-based markup language for security assertions
        1. Statements that service providers use to make access-control decisions
    3. SAML is
        1. A set of XML-based protocol messages
        2. A set of protocol message bindings
        3. A set of profiles (utilizing all of above)
    4. SAML Web Browser SSO profile was specified and standardized to promote interoperability.
        1. OpenID Connect protocol is an alternative approach to web browser SSO.
    5. OASIS (Organization for the Advancement of Structured Information Standards)
        1. A global nonprofit consortium that works on the development, convergence, and adoption of open standards for security, Internet of Things, energy, content technologies, emergency management, and other areas.
2. Use case
    1. Web browser single sign-on (SSO).
3. History
    1. SAML 1.0 was adopted as an OASIS standard in 11/2002
    2. SAML 1.1 was ratified as an OASIS standard in 9/2003
    3. SAML 2.0 became an OASIS standard in 3/2005
4. Basic Principles
    1. SAML specification defines three roles
        1. The principle (typically a human user)
        2. identity provider (idP)
        3. service provider (SP)
    2. Steps
        1. A principal requests a service from the service provider. 
        2. The service provider requests and obtains an authentication assertion from the identity provider. 
        3. On the basis of this assertion, the service provider can make an access control decision, that is, it can decide whether to perform the service for the connected principal.
            1. Before delivering the subject-based assertion to the SP, the IdP may request some information from the principal such as username password to authenticate the principal.
    3. Constraints
        1. SAML specifies the content of the assertion that is passed from the IdP to the SP.
        2. One identity provider may provide SAML assertions to many service providers. Similarly, one SP may rely on and trust assertions from many independent IdPs.
        3. SAML does not specify the method of authentication at the identity provider.
            1. IdP may use a username and password, or some other form of authentication, including multi-factor authentication.
            2. A directory service such as RADIUS, or Active Directory that allows users to log in with a username and password is a typical source of authentication tokens at an identity provider. The popular Internet social networking services also provide identity services that in theory could be used to support SAML exchanges.
5. Design
    1. Built upon a number of existing standards
        1. XML => must SAML exchanges are expressed in standard dialect of XML
        2. XML Schema => SAML assertions and protocols are specified (in part) using XML Schema.
        3. XML Signature => Both SAML 1.1 and 2.0 use digital signature for authentication and message integrity
        4. XML Encryption => SAML 2.0 provides elements for encrypted name identifiers, encrypted attributes, and encrypted assertions.
        5. HTTP protocol => SAML relies heavily on HTTP as its communications protocol
        6. SOAP => SAML specifies the use of SOAP.
    2. Assertions
        1. Loosely speaking, a relying party interprets an assertion as
            1. Assertion A was issued at time t by issuer R regarding subject S provided conditions C are valid.
        2. Three types os statements
            1. Authentication statements
                1. Assert to the service provider that the principal did indeed authenticate with the identity provider at a particular time using a particular method of authentication.
            2. Attribute statement
                1. Asserts that a principal is associated with certain attributes, name value pairs. Relying parties use attributes to make access-control decisions
            3. Authorization decision statement
                1. Asserts that a principal is permitted to perform action A on resource R given evidence E.
6. Binding
    1. A SAML binding is a mapping of a SAML protocol message onto standard messaging formats and/or communications protocols.
        1. SAML SOAP binding specifies how a SAML message is encapsulated in a SOAP envelope, which itself is bound to an HTTP message.
7. Profiles
    1. A SAML profile describes in detail how SAML assertions, protocols, and bindings combine to support a defined use case. 
        1. The most important being the Web Browser SSO profile
    2. SAML 1.1 specifies two forms of Web Browser SSO, the Browser/Artifact Profile and the Browser/POST Profile.
8. Security
    1. SAML specification recommend and in some cases mandate a variety of security mechanisms
        1. TLS 1.0+ for transport-level security
        2. XML Signature and XML Encryption for message-level security
    2. Requirements are often phrased in terms of (mutual) authentication, integrity, and confidentiality, leaving the choice of security mechanism to implementers and deployers.
9. Use
    1.  Protocol Flow
        1.  User Agent requests target resource, (discover IdP), redirect to SSO Service by first visiting SP.
        2.  User Agent then requests SSO Service, (identifies user), gets XHTML form by visiting IdP
        3.  User Agent requests Assertion Consumer Service, redirects to target resource, requests target resource, gets the requested resource by visiting SP.
    2.  Flow by example
        1.  GET https://sp.example.com/myresource
        2.  REDIRECT https://idp.example.org/SAML2/SSO/Redirect?SAMLRequest=request
            1. The value of SAMLRequest=request is a Base64 encoding of a deflated <samlp:AuthRequest> element
        3. The SSO service processes SAMLRequest, AuthnRequest and performs a security check. If the user does not have a valid security context, the identity provider identifies the user.
        4. The SSO service validates the requests and responds with a document containing HTML form
            1. It details method to post to SP, the SAMLResponse from IdP base64 encoded.
        5. The user agent issues a post request to the assertion consumer service at the service provider. The SAMLResponse parameter returned from SSO.
        6. Redirect to target resource
            1. The assertion consumer service processes the response, creates a security context at the service provider and redirects the user agent to the target resource.
        7. Request the target resource at the SP again
            1. The user agent requests the target resource at the service provider again like at step 1
                1. GET https://sp.example.com/myresource
        8. SP Respond with requested resource
            1. Since a security context exists, the service provider returns the resource to the user agent.
    3. "Flow by example" is of front-channel exchanges where an HTTP user agent communicates with a SAML entity at each step.
        1. Back-channel exchanges means direct communications between the service provider and the identity provider.
    4.  SAML Flow Web Browser
        1.  The end user clicks on the Login at sp.com
        2.  To authenticate the user, sp.com constructs a SAML Authentication Request, sign and optionally encrypts and sends it directl to IdP
        3.  The SP redirects the Client's browser to the IdP for authentication
        4.  The IdP verifies the received SAML Authentication Request and if valid, presents a login form for the end user to enter his username and password
        5.  Once the Client has successfully logged in, the IdP generates a SAML Assertion known as SAML Token which includes user identity and sends it directly to the SP
        6.  The IdP redirects the Client back to the SP
        7.  The SP verifies the SAML Assertion, extracts the user identity from it, assigns correct permissions for the Client and then logs him in to the service.