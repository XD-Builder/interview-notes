# Abstract

- This documents explores **Amazon Machine Image(AMI)**, its management and operations.

## AMI Quick Tour

1. Def
   1. AMI provides information required to launch an instance. It can be used multiple times for the same instance configuration.
   2. AMI is composed of
      1. A template for the root volume for the instance (Ex. OS, app server, applications)
      2. Launch permissions that control which AWS accounts can use the AMI to launch instances
      3. A block device mapping that specifies the volumes to attach to the instance when it's launched
2. Using an AMI
   1. AMI Lifecycle
      1. Create => template for the root volume => register => AMI
         1. AMI => Launch => Instance
         2. AMI => Copy => AMI #2
         3. AMI => deregister
   2. Search AMIs
      1. [AMI Types](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/ComponentsAMIs.html)
      2. [Ways to Finding an AMI](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/finding-an-ami.html)
   3. Connecting to an AMI instance
      1. Once you are connected to an [instance](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/Instances.html), you can use it like any other servers.
3. Creating Your Own AMI
   1. To create a custom AMI, one can launch an instance from an existing AMI, customize the instance, and then save as a new AMI.
      1. **Instances launched from this new AMI include the customization** that you made when you create the AMI.
      2. The root storage device of the instance determines the process you follow to create an AMI.
         1. [Amazon EC2 Root Device Volume](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/RootDeviceStorage.html)
         2. [Creating an EBS-Backed Linux AMI](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/creating-an-ami-ebs.html)
         3. [Creating an Instance Store-Backed Linux AMI](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/creating-an-ami-instance-store.html)
   2. [EC2 Resources Tagging](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/Using_Tags.html) helps manage instances, images, and other EC2 resources
4. Buying, Sharing, and Selling AMIs
   1. **You can set visibility level of your custom AMI.**
      1. [Shared AMIs](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/sharing-amis.html)
   2. **You can purchase AMIs from a third party, including AMIs that come with service contracts from organizations such Red Hat.**
   3. You can create custom AMIs as [Paid AMIs](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/paid-amis.html) and sell to other EC2 users.
5. [Deregistering AMI](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/deregister-ami.html)
6. Amazon Linux 2 and Amazon Linux AMI
   1. Definition
      1. Amazon Linux 2 and the Amazon Linux AMI are supported and maintained Linux images provided by AWS.
   2. **Features of Amazon Linux 2 and Amazon Linux AMI**
      1. **A stable, secure, and high-performance execution environment for applications running on Amazon EC2**
      2. Provided at **no additional charge to Amazon EC2 users**
      3. **Repository access to multiple versions of MySQL, PostgreSQL, Python, Ruby, Tomcat, and many more common packages**.
      4. **Updated on a regular basis to include latest components**, and **these updates are also made available in the yum repositories for installation on running instances**
      5. **Includes packages that enable easy integration with AWS services, such as the AWS CLI, Amazon EC2 API and AMI tools, the Boto library for Python, and Elastic Load Balancing tools**.