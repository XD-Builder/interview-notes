# Abstract
1. This document explores general IAM technologies in high level

## IAM technologies
1. Definition
    1. Identity management, known as IAM is, in computer security, the security and business discipline that "enable the right individuals to access the right resources at the right times and for the right reasons".
    2. It addresses the need to ensure appropriate access to resources across increasingly heterogeneous technology environments and to meet increasingly rigorous compliance requirements.
2. Identity-management systems
    1. IdM covers issues such as how users gain an identity, the protection of that identity and the technologies supporting that protection (network protocols, digital certificates, passwords, etc..)
    2. Definition
        1. It has the task of controlling information about users on computers. Such information includes information that authenticates the identity of a user, and infromation that describes informations and actions they are authorized to access and/or perform.
        2. It also includes the management of descriptive information about the user and how and by whom that information can be accessed and modified.
        3. Digital identity is an entity's online presence, encompassing personal identifying information (PII) and ancillary information.
3. Function
    1. Identity management can involve four basic functions
        1. The pure identity function - creation, management and deletion of identities without regard to access or entitlements.
        2. The user access (log-on) function
        3. The service function - A system that delivers personalized, role-based, online, on-demand, multimedia (content), presence-based services to users and their devices.
        4. Identity Federation - A system that relies on federated identity to authenticate a user without knowing his or her password.

## LDAP
1. Definition
    1. Lightweight Directory Access Protocol is a software protocol for enabling anyone to locate orgs, individuals, and other resources such as files and devices in a network, whether on the public Internet or on a corporate intranet.
2. Purpose
    1. LDAP is a directory service protocol that runs on a layer above the TCP/IP stack and provides a mechanism used to connect to, search, and modify Internet directories.
    2. It's based on a client server model and enables access to an existing directory.
    3. The data model of LDAP is similar to that of the X.500 OSI directory service, but with lower resource requirements.

## Kerberos
1. Definition
    1. A network authentication protocol designed to provide strong authentication for client/server applications by using secret-key cryptography. A free implementation of this protocol is available from the MIT. It is available in many commercial products at well.

## OAuth2
1. Definition
    1. An authorization framework that enables applications to obtain limited access to user accounts on HTTP service, such as Facebook, GitHub, and Digital Ocean.
2. 

## SAML
1. Definition
    1. Security Assertion Markup Language is an XML-based, open-standard data format for exchanging authentication and authorization data between parties, in particular, between an IdP and SP. SAML is a product of the OASIS Security Services Technical Committee

## RADIUS
1. Definition
    1. Remote Authentication Dial-In User Service (RADIUS) is a networking protocol that provides centralized Authentication, Authorization, and Accounting (AAA or Triple A) management for users who connect and use a network service.


## SAML vs OAuth
1. Difference
    1. SAML is An umbrella standard that covers federation, identity management and SSO.
        1. Used for
            1. Access to applications from a portal
            2. Centralized identity source
            3. Enterprise SSO
    2. OAuth is a standard for authorization of resources.
        1. Used for
            1. Mobile use cases (Bearer Tokens)
            2. Permanent or temporary access to resources such as accounts, files
    3. Difference
        1. SAML deals with authentication and authorization whereas OAuth deals with authorization.
        2. SAML -> Client , Client <- OAuth
            1. Web browser that an end user uses to access web app
        3. SAML -> IdP, Authorization Server <- OAuth
            1. Server that owns the user identities and credentials
        4. SAML -> SP, Resource Server <- OAuth
            1. The protected apps

