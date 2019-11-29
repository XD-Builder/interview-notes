## Samza @ LinkedIn
* Designed to consume Hadoop-scale data on infinite, continuous streams with seconds to sub-second latencies.

## Apache Samza
* A distributed stream processing framework that uses Apache Kafka for messaging, and Apache Hadoop YARN to provide fault tolerance, processor isolation, security, and resource management.(Cluster Resource Management and Data Processing)
* Benefits
    * Simple API
        * Simple callback based "process message" API comparable to MapReduce.
    * Managed state
        * It manages snapshotting and restoration of a stream processor's state.
        * When a processor is restarted, Samza restores its state to a consistent snapshot.
        * It's built to handle large amounts of state (many GB per partition)
    * Fault tolerance
        * Whenever a machine in the cluster fails, it works with YARN to transparently migrate your tasks to another machine.
    * Durability
        * It uses Kafka to guarantee the messages are processed in the order they were written to a partition and that no messages are ever lost.
    * Scalability
        * It is partitioned and distributed at every level.
        * Kafka provides ordered, partitioned, replayable, fault-tolerant streams.
        * YARN provides distributed environment for Samza containers to run in.
    * Pluggable
        * Though it works out of the box with Kafka and YARN, Samza provides a pluggable API that lets you run Samza with other messaging systems and execution environments.
    * Processor isolation
        * It works with Apache YARN, which supports Hadoop's security model, and resource isolation through Linux CGroups.
            * cgroups is a Linux kernel feature that limits, accounts for, and isolates the resource usage (CPU, RAM, disk, network, etc.) of a collection of processes.

## Apache YARN
* A composition of two daemons
    * Global Resource Manager(RM)
        * RM and Node Manager (NM) form the data-computation framework.
        * RM is the ultimate authority that arbitrates resources among all the applications in the system.
        * NM is a per-machine framework agent who is responsible for containers, monitoring their resource usage and reporting the same to the RM/Scheduler
        * Per-application Application Master(AM)
            * tasked with negotiating resources from RM and working with NM to execute and monitor the tasks
    * Scheduler - Scheduling/monitoring
        * Responsible for allocating resources to the various running applications subject to familiar constraints of capacities, queues etc.
* Scaling
    * In order to scale YARN beyond few thousands nodes, YARN supports the notion of Federation, which allows to transparently wire together multiple yarn (sub-)clusters, and make them appear as a single massive cluster.
        * This can be used to achieve larger scale, and/or to allow multiple independent clusters to be used together for very large jobs, or for tenants who have capacity across all of them.

## Apache Kafka
* A distributed streaming platform
* Capabilities
    * Pub/Sub to streams of records
    * Store streams of records in a fault-tolerant durable way
    * Process streams of records as they occur.
* Use cases
    * build real-time streaming data pipelines that reliably get data between systems and applications
    * Build real-time streaming applications that transform or react to the streams of data.
* Concepts
    * Kafka is run as a cluster on one or more servers that can span multiple datacenters.
    * The Kafka cluster stores streams of records in categories called topics.
    * Each record consists of a key, a value, and a timestamp.
* Core APIs
    * Producer API
        * allows an app to pub a stream of records to Kafka topics
    * Consumer API
        * allows an app to sub to topics and process the stream of records produced
    * Streams API
        * allows an app to act as a stream processor, consuming an input stream from one or more topics and producing an output stream to one or more output topics, effectively transforming the input streams to output streams.
    * Connector API
        * allows building and running reusable producers or consumers that connect Kafka topics to existing apps or data systems.
            * Ex. a connector to a relational db might capture every change to a table.
* Topics and Logs
    * A topic is a category or feed name to which records are published.
    * A partition log is maintained by Kafka cluster
        * Each partition is an ordered, immutable sequence of records that is continually appended to - a structured commit log.
        * The records in the partitions are each assigned a sequence id number called offset that uniquely identifies each record within a partition.
    * Kafka cluster durably persists all published records - whether or not they have been consumed - using a configurable retention period.
        * Performance won't be affected by this.
    * Offset
        * In fact, the only metadata retained on a per-consumer basis is the offset or position of that consumer in the log.
        * Controlled by the consumer
        * Consumers are very cheap - they can come and go without much impact to the cluster or on other consumers.
* Distribution
    * Partitions of the log are distributed over the servers in the Kafka cluster with each server handling data and requests for a share of the partitions.
    * Each partition is replicated across a configurable number of servers for fault tolerance.
    * Each partition has one server which acts as the "leader" and zero and more server acts as "followers".
        * Leader handles all read and write requests for the partition while the followers passively replicate the leader.
        * If the leader fails, one of the followers will automatically become the new leader. Each server acts a leader for some of its partitions and a follower for others so load is well balanced within the cluster.
* Geo-Replication
* ....