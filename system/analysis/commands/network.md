# Abstract

- This document explores networking commands and their uses

## DNS

1. About
   1. Domain Name Systems (DNS) is the phonebook of the Internet.
   2. It converts a hostname into a computer-friendly IP address.
2. 4 DNS Servers is involved in loading a webpages.
   1. DNS recursor(Recursive Resolver) recursively resolves a hostname to an IP address by being a middle man between a client and DNS servers. It will either respond to queries with cached data or recursively query from root nameserver, then TLD nameserver and then one last request to an authoritative nameserver.
   2. Root nameserver - 13 root nameservers are known to every recursive resolver and are the first stop in a recursive resolver's quest for DNS records. These 13 servers are redundant over the world and uses anycast routing to provide speedy responses. Management of which is by Internet Corporation for Assigned Names and Numbers (ICANN)
   3. TLD nameserver maintains info for all the domain names that share common domain extension such as .com, .net. Management of which is handled by the Internet Assignment Numbers Authority (IANA), which is a branch of ICANN.
   4. Authoritative nameservers - When a recursive resolver receives **a response from a TLD nameserver**, that response will **direct the resolver to an authoritative nameserver** which is usually the resolver's last step to finding an IP address.
      1. **The authoritative nameserver contains information specific to the domain name it serves** and it can provide a recursive resolver with the **IP address of that server found in the DNS A record**, or **if the domain has a CNAME record** it will provide the recursive resolver with **an alias domain**, at which point the recursive resolver will have to **perform a whole new DNS lookup to procure a record from authoritative nameserver** (often an A record containing an IP address).
3. Types of DNS queries
   1. **Recursive query** happens when a DNS client requires that a DNS server respond to the client with either the requested resource record or an error message if the resolver can't find the record
   2. **Iterative query happens when DNS client allows a DNS server to return the best answer it can.** If the queried DNS server does not have a match for the query name, **it will return a referral to a DNS server authoritative for a lower level of the domain namespace**. The client will then make a query to referral address. This process continues with additional DNS servers down the query chain until either an error or timeout occurs.
   3. **Non-recursive query occurs when a DNS resolver client queries a DNS server for a record that it has access to either because it's authoritative for the record or the record exists inside of its cache**.
4. Caching
   1. About
      1. DNS data can be cached in a variety of locations, each of which will store DNS records for a set amount of time determined by a TTL.
   2. Browser DNS caching
      1. Modern web browsers are designed by default to cache DNS records for a set amount of time. Browser cache is first checked for a DNS request.
   3. OS level DNS caching
      1. The OS level DNS resolver is the second and last local stop before DNS query leaves your machine. It first checks its cache to see if it has the record and if not it sends a DNS query (with a recursive flag set) outside the local network to **a DNS recursive resolver inside the ISP**.
   4. Recursive resolver DNS caching
      1. It will perform a cache check. Depending on types of records it has in its cache, it will perform various actions. **If it doesn't have a A records but does have the NS records for the authoritative nameservers, it will query those name servers directly**, bypassing several recursive query.
      2. **If the resolver does not have the NS records, it will send a query to the TLD servers, skipping the root server**.
      3. In the unlikely event that the resolver doesn't have records pointing to the TLD servers, it will then query the root servers. **This event typically occurs after a DNS cache has been purged.**
5. Anycast routing
   1. A network addressing and routing methodology in which a single destination address has multiple routing paths to two or more endpoint destinations. **Routers select the desired path** on the basis of number of hops, distance, lowest cost, latency measurements or based on the least congested route.

## /etc/resolv.conf

1. About
   1. It contains information read by the resolver routines the first time they are invoked by a process.
   2. On a normally configured system this file should not be necessary as the only name to be queried will be the local machine and the domain name can be determined from the host name, and the domain search path is constructed from the domain name.
2. Configuration options
   1. nameserver
      1. IP of a nameserver that the resolver should query. If multiple servers available, the resolver library queries them in the order listed. If no nameserver entries are available, the default is to use the nameserver on the local machine.
   2. domain
      1. Local domain name. **Most queries for names within this domain can use short names relative to the local domain**.
   3. search
      1. Search list for host-name lookup. **The search list is normally determined from the local domain name**. By default, it contains only the local domain name. It can be slow because a resolver has to query using each component of the search path in turn until a match is found.
      2. Domain search list as well as local domain name is used by a resolver to create fully qualified domain name (FQDN) from a relative name.
         1. A FQDN is a domain name that specifies the exact location in the tree hierarchy of the DNS. It specifies all domain levels, including the TLD and root zone.
   4. Extra
      1. domain and search options are mutually exclusive. If more than one instance of these keywords is present, the last instance will override.

## /etc/host

1. An OS file that maps host to IP addresses.
2. It contains lines of text consisting of an IP address in the first text field followed by one or more host names.d

## /etc/nsswitch.conf

1. Name Service Switch (NSS) is a facility in Unix like OS that provides **a variety of sources for common configuration databases and name resolution mechanisms**. Sources include system files such as passwd, group, and hosts, Domain Name System, the Network Information Service (NIS), and LAP.
2. The order of the services listed in this file determines in which order NSS will attempt to use those servies to resolve queries on the specified database.

### dig

1. About
   1. Domain information groper is a Unix-like network administration CLI tool for querying DNS servers. When a specific nameserver is not specified in the command invocation, it will use the OS's default resolver, usually configured via the resolv.conf file. Without any arguments it queries the DNS root zone.
   2. A flexible tool for interrogating DNS nameservers. Most DNS admins use dig to troubleshoot DNS problems because of its flexibility, ease of use and clarity of output.
2. Synopsis
   1. dig [@server][-b address] [-c class][-f filename] [-k filename][-m] [-p port#][-q name] [-t type][-v] [-x addr]-y [hmac:]name:key] [-4][-6] [name][type] [class][queryopt...]
   2. dig [-h]
   3. dig [global-queryopt...][query...]
3. Options
   1. -x addr
      1. Simplified reverse lookups for mapping addresses to names.
      2. dig automatically performs a lookup for a name like 94.2.0.192.in-addr.arpa and sets the query type and class to PTR and IN respectively.

### nslookup

1. About
   1. A program to query Internet domain nameservers. It has interactive and non-interactive mode. Interactive allows the user to query nameservers for information about various hosts and domains or to print a list of hosts in a domain. Non-interactive mode is used to print just the name and requested information for a host or domain.
2. Synopsis
   1. nslookup [-option][name | -] [server]
