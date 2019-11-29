# BitTorrent
### Definitions of P2P
* The elements in a system need to be both service requesters and service providers for the system to be considered P2P.
* SIP
    * A rendezvous protocol that allows a user to locate a remote user and establish a communication session with that remote user.
    * For locating prospective session participants, and for other functions, SIP enables the creation of an infrastructure of network hosts (called proxy servers) to which user agents can send registrations, invitations to sessions, and other requests. 
    * SIP is an agile, general-purpose tool for creating, modifying, and terminating sessions that works independently of underlying transport protocols and without dependency on the type of session that is being established.
* BitTorrent
    * A P2P system because endpoints request services from other endpoints and provide services to other endpoints.

### P2P System functions
* Independent service functions
    * Enrollment functions - nodes joining a P2P system need to obtain a valid credentials to join the system. The enrollment function handles node authentication and authorization.
    * Peer discovery function - in order to join a P2P, a node needs to establish a connection with one or more peers that are already part of the system.
* Dependent service function
    * Data indexing function - deals with indexing the data stored in the system.
    * Data storage function - deals with storing and retrieving data from the system.
    * Computation function - deal with the computing performed by the system.
    * Message transport function - deals with message exchanges between peers.
        * Can be through a central server, directly between themselves or through peers that provide overlay routing.

### P2P Applications
* Content distribution
    * the content may be encrypted so that peers without the decryption key are content distributors but not content consumers
* Distributed computing
    * Each task is divided into independent subtasks that can be completed in parallel and delivered to a peer. The peer completes the subtask using its resources and returns the result. All results are combined to obtain the result of the original task.
* Collaboration
    * P2PSIP - referred as infrastructureless SIP to distinguish it from traditional SIP, which relies on a rendezvous server infrastructure.
    * Communications, VoIP Instant Messaging (IM) applications.
    * P2P rendezvous systems are especially useful in situations where there is no infrastructure.
* Platforms
    * Used to build applications that's P2P
    * Preferred environment for app developer to take advantage of the good scalability properties.

# The BitTorrent Protocol Specification
## Quick Definition
* BitTorrent is a protocol for distributing files. It identifies content by URL and is designed to integrate seamlessly with the web. Its advantage over plain HTTP is that when multiple downloads of the same file happen concurrently, the downloaders upload to each other, making it possible for the file source to support very large numbers of downloaders with only a modest increase in its load.

## Entities for file distribution consists
* A ordinary web server, a static "metainfo" file, a BitTorrent tracker, a "original" downloader, the end user web browsers, the end user downloaders.

## Start serving, host setup steps
1. Start running tracker (For keeping track of torrents' seeders info)
2. Start running an ordinary web server (For sharing torrent files generated)
3. Associate the extension .torrent with mimetype application/x-bittorrent on the web server. (For responding to client http requests for torrent file)
4. Generate a metainfo(.torrent) file using the complete file to be served and the URL of the tracker (For specifying the location of the file on current machine as well as the tracker location for updating swarm info)
5. Put the metainfo on the web server (For sharing this torrent files with HTTP clients)
6. Link to metainfo file from other web page
7. Start a downloader which already has the complete file (the "origin")

## Start downloading, user setup steps
1. Install BiTorrent
2. Surf the web and open .torrent file link
3. Select where to save and wait for download complete.
4. Continue downloader if you want to become a seeders for uploading the file.

## bencoding
* Stands for bittorrent encoding
    * String encoding
        * length prefixed base ten followed by a colon and a string
        * 4:spam, 5:hello
    * Integer encoding
        * 'i' followed by the number in base 10 followed by an 'e'
        * i5e, i0e
    * Lists encoding
        * 'l' followed by their elements (also bencoded) followed by an 'e'
        * l4:spam4:eggse => ['spam', 'eggs']
    * Dictionaries encoding
        * 'd' followed by a list of alternating keys and their corresponding values followed by an 'e'.
        * d3:cow3:moo4:spam4:eggse => {'cow': 'moo', 'spam': 'eggs'}

## Metainfo files
* Metainfo files (also known as .torrent files) are bencoded dictionaries with the following keys
    * announce
        * The URL of the tracker
    * info
        * This maps to a dictionary, with keys described below.
        * name
            * maps to a UTF-8 encoded string - suggested name to save the file
        * piece length
            * maps to the number of bytes in each piece the file is split into
        * pieces
            * maps to a string whose length is a multiple of 20.
                * It is subdivided into strings of length 20, each of which is the SHA1 hash of the piece at the corresponding index.
        * length
            * maps to the length of the file in bytes (should not exist if files key present)
            * indicates only a single file present in this torrent
        * files
            * a list of files that his torrent is mapped to.
            * files are dictionaries
                * length
                    * The length of the file in bytes
                * path
                    * A list of UTF-8 encoded strings corresponding to subdirectory names, the last of which is the actual file name

## Trackers
### Request Parameters 
* HTTP GET Request
    * info_hash - urlencoded 20-byte SHA1 hash of the value of the info key from the MetaInfo file. (authenticates the torrent files)
    * peer_id - a unique ID for the client, generated by the client at startup
    * port - The port number that the client is listening on. Ports reserved for BitTorrent are typically 6881-6889. 
    * uploaded - The total amount uploaded (since the client sent the 'started' event to the tracker) in base ten ASCII
    * downloaded - The total amount downloaded (since the client sent the 'started' event to the tracker) in base ten ASCII
    * left - The number of bytes this client still has to download in base ten ASCII
    * compact - Setting this to 1 indicates that the client accepts a compact response
    * no_peer_id - Indicates that the tracker can omit peer id field in peers dictionary.
    * event -  If specified, must be one of started, completed, stopped
    * ip - optional because this can be determined from the HTTP request
    * numwant - Number of peers that the client would like to receive from the tracker.
    * key - An additional identification that is not shared with any other peers. It is intended to allow a client to prove their identity should their IP address change
    * trackerid - If a previous announce contained a tracker id, it should be set here

### Tracker response
* The tracker responds with "text/plain" document consisting of a bencoded dictionary with the following keys:
    * failure reason - If present, then no other keys may be present. The value is a human-readable error message as to why the request failed (string).
    * warning message - Similar to failure reason, but the response still gets processed normally. The warning message is shown just like an error.
    * interval - Interval in seconds that the client should wait between sending regular requests to the tracker
    * min interval, tracker id
    * complete - number of peers with the entire file, i.e. seeders (integer)
    * incomplete - number of non-seeder peers, aka "leechers" (integer)
    * peers - The value is a list of dictionaries, each with the following keys:
        * peer id - peer's self-selected ID, as described above for the tracker request (string)
        * ip - peer's IP address either IPv6 (hexed) or IPv4 (dotted quad) or DNS name (string)
        * port - peer's port number (integer)
    * peers: (binary model) - Instead of using the dictionary model described above, the peers value may be a string consisting of multiples of 6 bytes. First 4 bytes are the IP address and last 2 bytes are the port number. All in network (big endian) notation

### Tracker 'scrape' Convention
* Most trackers support another form of request, which queries the state of a given torrent that the tracker is managing.
    * This is referred to as the "scrape page" because it automates the otherwise tedious process of "screen scraping" the tracker's stats page.
    * It will return a files dictionary with stats about each file such as
        * complete - number of peers with the entire file, seeders
        * downloaded - total number of times the tracker has registered a completion
        * incomplete - number of non-seeder peers.
        * name - the torrent's internal name in the info section

### Peer Wire protocol (TCP)
* Facilitates the exchange of pieces described in the metainfo file.
* A client must maintain state information for each connection that it has with a remote peer.
    * choked - whether or not the remote peer has choked this client. When a peer chokes the client, it is a notification that no requests will be answered until the client is unchoked. The client should not attempt to send requests for blocks, and it should consider all pending (unanswered) requests to be discarded by the remote peer.
    * interested -  Whether or not the remote peer is interested in something this client has to offer. This is a notification that the remote peer will begin requesting blocks when the client unchokes them.
* A block is downloaded by the client when the client is interested in a peer, and that peer is not choking the client. A block is uploaded by a client when the client is not choking a peer, and that peer is interested in the client.
* Data Type
    * Unless specified otherwise, all integers in the peer wire protocol are encoded as four byte big-endian values. This includes the length prefix on all messages that come after the handshake.
* Handshake
    * First message required and transmitted by the client (49 + len(pstr)) bytes long
        * handshake <ptsrlen><pstr><reserved><info_hash><peer_id>
        * pstrlen - length of pstr
        * pstr - identifier of the protocol
        * reserved - all zeros for current impl
        * info_hash - 20 byte SHA1 hash of the info key
        * peer_id - 20 byte string used as a unique ID for the client

## Terminology
* BitTorrent client - used to load .torrent file to join BitTorrent swarm with other computers who have loaded the same .torrent file
* Tracker - Defined inside a .torrent file whose main job is to keep track of all connected computers and share your IP with others in the swarm
* Seeding - The process that initiates after downloading enough small bits of file from swarm for P2P sharing.
* Seeders - nodes that only uploads pieces to other endpoints
* Swarm - The group of endpoints involved in the distribution of a particular file.