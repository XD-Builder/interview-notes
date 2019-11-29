# Abstract

- This documents explores **Security Group**, its management and operations.

## Security Group Basics

1. What is
   1. A security group acts as **a virtual firewall for your instance to control inbound and outbound traffic**.
      1. When you launch an instance in a VPC, you can assign up to five security groups to the instance. **Security groups act at the instance level, not the subnet level**. Therefore, each instance in a subnet in your VPC could be assigned to a different set of security groups. If you don't specify a particular group at launch time, the instance is automatically assigned to the default security group for the VPC.
2. Basic characteristics of security group for your VPC
   1. Limited number of SGs per VPC
   2. Only allow rules not deny rules
   3. By default, a SG has no inbound rules.
   4. By default, a SG includes an outbound rule that allows all outbound traffic.
   5. Instances associated with a SG can't talk to each other unless rules added. Default SG is an exception as rules are added by default.
   6. SGs are associated with network interfaces. After you launch an instance, you can change the SG associated with the instance, which changes the SG associated with the primary network interface(eth0).

## Default Security Group for Your VPC

1. A VPC automatically comes with a default SG.
2. It will have following rules
   1. Inbound rule include source from the default SG for all protocol and all port range.
   2. Outbound rule include all IPv4 and IPv6 destination on all protocols and port ranges
