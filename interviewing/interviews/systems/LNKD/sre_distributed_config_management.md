# Brief
* As number of servers grow, it's important for administrator to be able to manage configurations and run arbitrary commands on all servers, monitor and scale them efficiently with least human intervention.


## Puppet vs. Chef vs. Ansible vs. SaltStack
* Puppet
    * a pioneering configuration automation and deployment orchestration solution for distributed apps and infrastructure
    * built with **Ruby** and offers custom Domain Specific Language (DSL) and Embedded Ruby (ERB) templates to create custom Puppet language files, and offers a declarative paradigm programming approach
    * uses an **agent/master architecture**
        * Agents manage nodes and request relevant info from masters that control configuration info. 
        * The agent polls status reports and queries regarding its associated server machine from the master Puppet server, which then communicates its response and required commands using the **XML-RPC protocol over HTTPS**
    * The Puppet Enterprise product offers:
        * Orchestration
        * Automated provisioning
        * Configuration automation
        * Visualization and reporting
        * Code management
        * Node management
        * Role-based access control
* Chef
    * A client-server architecture and offers configuration in a **Ruby DSL** using the **imperative programming** paradigm
    * Its flexible cloud infrastructure automation framework allows users to install apps to bare metal VMs and cloud containers
    * Similar to the Puppet master-agent model and uses a pull-based approach, except that **an additional logical Chef workstation is required** to control configurations from the master to agents. 
    * Agents poll the information from master servers that respond via **SSH**.
    * Several SaaS and hybrid delivery models are available to handle analytics and reporting.
    * Capabilities:
        * Infrastructure automation
        * Cloud automation
        * Automation for DevOps workflow
        * Compliance and security management
        * Automated workflow for Continuous Delivery
* Ansible
    * A latest entrant in the market compared with Puppet, Chef and Salt, Ansible was developed to simplify complex orchestration and configuration management tasks.
    * The platform is written in Python and allows users to script commands in **YAML** as an **imperative programming** paradigm
    * Ansible offers **multiple push models** to send **command modules** to nodes via **SSH** that are **executed sequentially**.
    * Ansible **doesn’t require agents** on every system, and **modules can reside on any server**
    * A centralized Ansible workstation is commonly used to tunnel commands through multiple Bastion host servers and access machines in a private network.
    * Capabilities:
        * Streamlined provisioning
        * Configuration management
        * App deployment
        * Automated workflow for Continuous Delivery
        * Security and Compliance policy integration into automated processes
        * Simplified orchestration
    * Pro
        * Lack of master eliminates failure points and performance issues. Agent-less deployment and communication is faster than the master-agent model.
* SaltStack
    * Designed to enable **low-latency** and **high-speed communication** for **data collection** and **remote execution** in sysadmin environments.
    * The platform is written in Python and uses the **push model for executing commands via SSH protocol**
    * Salt allows **parallel execution** of **multiple commands** **encrypted via AES** and offers both **vertical and horizontal scaling**. 
    * A single master can manage multiple masters, and the peer interface allows users to control multiple agents (minions) directly from an agent.
    * In addition to the usual queries from minions, **downstream events can also trigger actions from the master**
    * The platform **supports both master-agent and de-centralized, non-master models**. 
    * Like Ansible, users can script using YAML templates based on imperative paradigm programming. 
    * The **built-in remote execution system executes tasks sequentially**.
    * Capabilities:
        * Orchestration and automation for CloudOps
        * Automation for ITOps
        * Continuous code integration and deployment
        * Application monitoring and auto-healing
        * DevOps toolchain workflow automation with support for Puppet, Chef, Docker, Jenkins, Git, etc.
    * Pros
        * Effective for high scalability and resilient environments.
        * Easy and straightforward usage past the initial installation and setup.
        * Strong introspection.
        * Active community and support.
        * Feature-rich and consistent YAML syntax across all scripting tasks. Python offers a low learning curve for developers.

