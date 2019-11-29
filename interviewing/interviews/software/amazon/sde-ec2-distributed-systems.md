## Distributed computing

1. Definition
   1. A field of computer science that studies distributed systems, one whose components are located on different networked computers, which then communicate and coordinate their actions by **passing messages** to one other.
      1. The components interact with one other in order to achieve a common goal.
   2. Also refers to the use of distributed systems to solve computational problems.
      1. A program is divided into many tasks, each of which is solved by one or more computers, which communicate with each other via message passing.
2. Characteristics
   1. Concurrency of components
   2. lack of a global clock
   3. independent failure of components
      1. Examples
         1. SOA-based systems, massively multiplayer online games and peer-to-peer applications
3. Messaging Implementation
   1. Distributed program
      1. A computer program that runs within a distributed system.
      2. Distributed programming is the process of writing such programs.
   2. Many different types of implementations
      1. HTTP
      2. RPC-like connectors
      3. message queues
4. Properties
   1. The system has to tolerate failures in individual computers.
   2. The structure of system (network topology, network latency, number of computers) is not known in advance, the system may consist of different kinds of computers and network links, and the system may change during the execution of a distributed program.
   3. Each computer has only a limited, incomplete view of the system. Each computer may know only one part of the input.
5. Parallel and distributed computing
   1. It is possible to roughly classify concurrent systems as "parallel" or distributed"
      1. In parallel computing, all processors may have access to a shared memory to exchange information between processors.
      2. In distributed computing, each processor has its own private memory. Information is exchanged by passing messages between the processors.
6. Architecture
   1. Client-server
      1. Smart clients contact the server for data then format and display it to the users. Input at the client is committed back to the server when it represents a permanent change.
   2. Three-tier
      1. An architecture that moves the client intelligence to a middle tier so that stateless clients can be used. This simplifies application deployment. Most web app are three-tier.
   3. n-tier
      1. Web applications which further forward their requests to other enterprise services. The type of application is the one most responsible for the success of application servers.
   4. Peer-to-peer
      1. No special machines that provide a service or manage the network resources. Instead all responsibilities are uniformly divided among all machines, known as peers. Peers can serve both as clients and as servers.
7. Examples of distributed systems and applications of distributed computing:
   1. Telecommunication networks
      1. Telephone networks and cellular networks
      2. Computer networks such as the Internet
      3. Wireless sensor networks
      4. Routing algorithms
   2. Network applications
      1. World Wide Web and p2p networks
      2. Massively multiplayer online games and virtual reality communities
      3. distributed databases
      4. network file systems
      5. distributed information processing systems such as banking and airline reservation systems.
   3. Real-time process control
      1. Aircraft control systems
      2. Industrial control systems
   4. Parallel computation
      1. Scientific computing, including cluster, grid computing and various volunteer computing projects.
      2. Distributed rendering in computer graphics
8. Theoretical foundations
   1. Computational problems
      1. A task that we would like to automate by using a computer are of question-answer type is called computational problem in theoretical computer science.
         1. Formally, a computational problem consists of instances together with a solution for each instance.
      2. It seeks to understand which computational problem can be solved by using a computer (computability theory) and how efficiently (computational complexity theory).
         1. Traditionally, it is said that a problem can be solved by using a computer if we can design an algorithm that produces a correct solution for any given instance.
   2. Computational problems - concurrent/distributed
      1. The field of concurrent and distributed computing studies similar questions in the case of either multiple computers, or a computer that executes a network of interacting processes: which computational problems can be solved in such a network and how efficiently?
9. Multiple computers concurrent processing
   1. Parallel algorithms in shared-memory model
      1. All processors have access to a shared memory. The algorithm designer chooses the program executed by each processor.
      2. One theoretical model is the parallel random access machine that are used.
      3. Shared memory programs can be extended to distributed systems if the underlying OS encapsulates the communication between nodes and virtually unifies the memory across all individual systems.
   2. Parallel algorithms in message-passing model
      1. The algorithm designer chooses the structure of the network, as well as the program executed by each computer.
   3. Distributed algorithms in message-passing model
      1. The algorithm designer only chooses the computer program. All computers run the same program. The system must work correctly regardless of the structure of the network.
      2. A commonly used model is a graph with one finite-state machine per node.
10. A problem solved with traditional and distributed approach
    1. Consider the computation problem of finding coloring of a given graph G.
       1. Centralized algorithms
          1. The graph G is encoded as a string, and the string is given as input to a computer. The computer program finds a coloring of the graph, encodes the coloring as a string, and outputs the result
       2. Parallel algorithms
          1. ..., multiple computers can access the same string in parallel. Each computer might focus on one part of the graph and produce coloring for that part.
          2. The main focus is high perf computation exploiting the processing power of multiple computers in parallel.
       3. Distributed algorithms
          1. The graph G is the structure of the computer network. There is one computer for each node of G and one communication link for each edge of G. Initially, each computer only knows about its immediate neighbors in the graph G; the computers must exchange messages with each other to discover more about the structure of G. Each computer must produce its own color as output.
          2. The main focus is on coordinating the operation of an arbitrary distributed system.
11. Challenges
    1. Traditional computational problems
       1. We take the perspective that we ask a question, a computer (or a distributed system) processes the question for a while, and then produces an answer and stops.
       2. What if we have problems where we do not want the system to ever stop?
          1. Example include dining philosophers problem and other similar mutual exclusion problems.
             1. In these problems, the distributed system is supposed to continuously coordinate the use of shared resources so that no conflicts or deadlocks occur.
          2. There are fundamental challenges that are unique to distributed computing. The first example is challenges that are related to fault-tolerance.
             1. Examples of related problems include consensus problems, Byzantine fault tolerance, and self-stabilization.
    2. Research on distributed systems
       1. A lot of research focuses on understanding the asynchronous nature of distributed systems
          1. Synchronizers can be used to run synchronous algorithms in asynchronous systems.
          2. Logical clocks provide a causal happened-after ordering event.
          3. Clock synchronization algorithm provides globally consistent physical time stamp.
