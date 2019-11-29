# Abstract

- This documents explores **Route Table**, its management and operations.

## Route Table Basics

1. About
   1. A set of rules, called routes, that are used to determine where network traffic is directed.
   2. **Each subnet in your VPC must be associated with a route table**; **the table controls the routing for the subnet**.
   3. **A subnet can only be associated with one route table at a time**.
   4. **You can associate multiple subnets with the same route table**.
2. Basics of Route Table
   1. VPC has an implicit router; **VPC automatically comes with a main route table that one can modify**.
   2. You can create additional custom route tables for a VPC.
   3. **Each subnet must be associated with a route table, which controls the routing for the subnet**. If you don't explicitly associate a subnet with a particular route table, the subnet is implicitly associated with the main route table.
   4. **You cannot delete the main route table**, but you can replace the main route table with a custom table that you've created.
   5. Each route in a table specifies a destination CIDR and a target.
      1. We use the **most specific route that matches the traffic to determine how to route the traffic**.
   6. Every route table contains a local route for communication within the VPC over IPv4.
   7. **When you add an Internet gateway, an egress-only Internet gateway, a virtual private gateway, a NAT device, a peering connection, or a VPC endpoint in your VPC, you must update the route table for any subnet that uses these gateways or connections**.
   8. There is a limit on the number of route tables you can create per VPC,

## Route Priority

1. We use **the most specific route in your route table** that matches the traffic to determine how to route the traffic (longest prefix match).

## Routing Options

1. Options
   1. **Route Tables for an Internet Gateway**
   2. **Route Tables for a NAT Device**
   3. **Route Tables for a Virtual Private Gateway**
   4. **Route Tables for a VPC Peering Connection**
   5. Route Tables for ClassicLink
   6. **Route Tables for a VPC Endpoint**
   7. Route Tables for an Egress-Only Internet Gateway
   8. **Route Tables for Transit Gateways**
