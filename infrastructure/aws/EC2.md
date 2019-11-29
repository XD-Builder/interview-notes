# Abstract

- This documents explores **EC2**, its management and operations.

## What is EC2

1. Background
   1. Amazon EC2 provides scalable computing capacity in the AWS cloud. EC2 eliminates the need to invest in hardware up front and allows faster development and deployment of applications. EC2 can be used to launch as many virtual servers as you need, configure security and networking and manage storage. EC2 allows you to scale up and down to handle changes in requirements or spikes in popularity, reducing your need to forecast traffic.
2. Features of EC2
   1. Virtual computing environments - **Instances**
   2. Pre-configured templates for instances - **AMI**, which packages the OS and additional software.
   3. Various configurations of CPU, memory, storage, and networking capacity for instances - **Instance Types**
   4. Secure login information for instances - **Key Pairs**
   5. Storage volumes for temporary data that's deleted when you stop or terminate instance - **instance store volumes**
   6. Persistent storage volumes for data using Amazon Elastic Block Store - **EBS volumes**
   7. Multiple physical locations for your resources, such as instances and Amazon EBS volumes - **Regions and Availability Zones**
   8. A firewall that enables you to specify the protocols, ports, and source IP ranges that reach your instances - **Security Groups**
   9. Static IPv4 addresses for dynamic cloud computing - **Elastic IP addresses**
   10. Metadata that you can create and assign to your EC2 resources - **Tags**
   11. Virtual networks you can create that are logically isolated from the rest of the AWS cloud, and that you can optionally connect to your own network - **Virtual Private Clouds (VPCs)**

## Setting Up with EC2

1. Background
   1. You can open the EC2 console and choose Launch Instance, and follow the steps in the launch wizard to launch your first instance.
2. Steps to set up EC2
   1. Sign Up for AWS
   2. Create an IAM User
      1. Services in AWS requires credential so that AWS can determine your permission to resources.
         1. The console requires username password of an AWS account.
         2. You can create **access keys for AWS account to access via CLI or API**.
   3. Create a Key Pair
      1. You specify the name of the key pair when launching your instance, and then provide the private key when you login using SSH.
         1. A Linux instance has **no password**; **you use key pair to log in to EC2 instances securely**.
   4. Create a Virtual Private Cloud (VPC)
      1. **Enables launching AWS resources into a virtual network that you've defined**.
      2. VPCs are specific to a region and you need to select a region where you create your own key pair; You can configure public subnet.
   5. Create a Security Group
      1. **Act as a firewall for associated instances, controlling both inbound and outbound traffic at the instance level**.
      2. **You must add rules to a security group** that enable you to connect to your instance from your IP address using SSH
      3. If you plan to launch instances in multiple regions, you'll need to **create a security group in each region**.

## Getting Started with EC2 Linux Instances

1. Steps to work with EC2 instances - Launch a Linux instance using the AWS Management Console
   1. To launch an instance
      1. On EC2 console, choose Launch Instance and then configure AMI, HVM version and hardware configuration.
      2. Review and Launch with selected security group and launch.
      3. When prompted for a key pair, select an existing key pair, then select the key pair that you created when getting set up.
      4. Confirm instance is being launched and on the Instance screen, you can view the status of the launch.
   2. Connect to your instance
      1. Several ways to [connect to Linux Instance](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/AccessingInstances.html).
      2. To troubleshoot connection error to your instance, follow this [link](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/TroubleshootingInstancesConnecting.html)
   3. Clean up your instance
      1. Effects
         1. Terminating an instance effectively deletes it; you can't reconnect to an instance after you've terminated it.
      2. Reasons
         1. You'll stop incurring charges for a instance as soon as that instance's status changes to shutting down or terminated.
         2. If you'd like to keep your instance for later, but not incur charges, you can stop the instance now and then start it later again.

## Instance Lifecycle

1. About Instance Lifecycle
   1. Difference between instance store-backed instance and EBS-backed instances
      1. Instance store-backed instance can't be stopped, it can only be terminated via shutdown whereas EBS-backed instances can be stopped and restarted.
   2. Only running instance is billed.
   3. An instance can be in different states and they are
      1. Launched, pending, running, (rebooting, (shutting-down, terminated), (stopping, stopped, terminated)).
2. Instance Launch
   1. When you **launch an instance, it enters the pending state**. **The instance type** that you specified at launch **determines the hardware of the host computer** for your instance. The AMI you specified at launch is used to boot the instance.
      1. As soon as your instance is in running state you will be billed for each second with one-minute min, regardless of the workload of the instance.
3. Instance Stop and Start (EBS-Backed Instances Only)
   1. If your instance **fails a status check or is not running your applications as expected**, and if the **root volume of your instance is an EBS volume**, you **can stop and start your instance** to try to fix the problem.
   2. **Your instance retains its private IPv4/IPv6 address**, which means that an Elastic IP address associated with the private IPv4/IPv6 address or network interface is still associated with your instance.
4. Instance Hibernate (EBS-Backed Instances Only)
   1. When you hibernate an instance, AWS signal the OS to perform hibernation (suspend-to-disk), which saves the content from the instance memory (RAM) to EBS root volume.
   2. When you hibernate your instance, it enters the stopping state, and then the stopped state. This will not incur charge as it's in stopped state.
   3. Data transfer fees are not charged; only the storage of EBS is.
5. Instance Reboot
   1. Rebooting an instance is equivalent to rebooting an OS. The instance remains on the same host computer and maintains its public DNS name, private IP address, and any data on its instance store volumes.
   2. It does not start a new instance billing period, **per second billing continues without a further one-minute minimum charge**.
6. Instance Retirement
   1. An instance is scheduled to be retired when AWS detects the irreparable failure of the underlying hardware hosting the instance.
      1. When an instance reaches its scheduled retirement date, it is stopped or terminated by AWS.
7. Instance Termination
   1. If you enable termination protection, you can't terminate the instance using the console, CLI, or API.
   2. After you terminate an instance, it remains visible in the console for a short while, and then the entry is automatically deleted.
   3. Each EBS-backed instance supports the InstanceInitiatedShutdownBehavior attribute, which controls whether the instance stops or terminates when you initiate shutdown from within the instance itself.
      1. The default behavior is to stop the instance but you can modify the setting of this attribute while the instance is running or stopped.

## Instance Types

1. What is instance types?
   1. Instance type specifies the hardware of the host computer used for your instance.
   2. **Each instance type offers different compute, memory, and storage capabilities and are grouped in instance families based on these capabilities**.
   3. EC2 **dedicates some resources of the host computer, such as CPU, memory, and instance storage, to a particular instance**.
   4. EC2 **shares other resources of the host computer, such as the network and disk subsystem, among instances**.
      1. If each instance on a host computer tries to use as much of one of the these shared resources as possible, each receives an equal share of that resource.
      2. If a resource is underused, an instance can consume a higher share of that resource while it's available.
   5. Each instance type provides higher or lower min perf from a shared resource.
      1. Instance types with high I/O perf have a larger allocation of shared resources.
2. Available Instance Types
   1. General Purpose
   2. Compute Optimized
   3. Memory Optimized
   4. Storage Optimized
   5. Accelerated Computing
3. Virtualization Types
   1. Virtualization type is determined by the AMI that you use to launch an instance. **Current generation instance types support Hardare virtual machine (HVM) only**. Some previous generation support paravirtual (PV) and some AWS regions support PV instance.
4. Nitro-based Instances
   1. **A collection of AWS-built hardware and software components that enable high perf, high availability, and high security**. In addition, the Nitro system **provides bare metal capabilities that eliminate virtualization overhead and support workloads that require full access to host hardware**.
   2. Components
      1. Hypervisor
         1. A lightweight hypervisor that manages memory and CPU allocation and delivers perf that is indistinguishable from bare metal for most workloads
      2. Card
         1. Local NVMe storage volume, networking hardware support, management, monitoring, security.
      3. Security chip, integrated into the motherboard.

## Instance Purchasing options?

1. Options that optimize your costs based on your needs
   1. On-Demand Instances
      1. **Pay, by the second**, for the instance that you launch.
   2. Reserved instances
      1. **Purchase, at a significant discount, instances that are always available, for a term from one to three years**.
   3. Scheduled Instances
      1. **Purchase instances that are always available on the specified recurring schedule, for a one-year term**.
   4. Spot Instances
      1. **Request unused EC2 instances, which can lower EC2 costs significantly**
   5. Dedicated Hosts
      1. **Pay for a physical host that is fully dedicated to running your instances, and bring your existing per-socket, per-core, or per-VM software licenses to reduce costs**.
   6. Dedicated Instances
      1. **Pay, by the hour, for instances that run on single-tenant hardware**.
   7. Capacity Reservations
      1. **Reserve capacity for you EC2 instances** in a specific AZ for any duration.
2. About instance purchase options
   1. If you require a capacity reservation, **purchase Reserved Instances or Capacity Reservations for a specific Availability Zone, or purchase Scheduled Instances**. Spot Instances are a cost-effective choice if you can be flexible about when your applications run and if they can be interrupted. **Dedicated Hosts or Dedicated Instances can help you address compliance requirements and reduce costs by using your existing server-bound software licenses**.

## Remotely manage a fleet of EC2 instances and machines in a hybrid environment

1. What is AWS Systems Manager
   1. **A collection of capabilities for configuring and managing your Amazon EC2 instances, on-premises servers and virtual machines (VMs), and certain other AWS resources**.
   2. What it does
      1. Systems Manager includes a unified interface that lets you easily centralize operational data and automate tasks across your AWS resources.
      2. Systems Manager shortens the time to detect and resolve operational problems in your infrastructure.
      3. Systems Manager gives you a complete view of your infrastructure performance and configuration, simplifies resource and application management, and makes it easy to operate and manage your infrastructure at scale.
