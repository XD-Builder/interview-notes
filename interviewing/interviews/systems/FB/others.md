---
layout: post
title: "Preparing for the Production Engineer interview"
date: 2017-08-13
categories: facebook, production engineer, interview
---

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Summary](#summary)
- [Introduction](#introduction)
- [My background](#my-background)
- [The interview process](#the-interview-process)
- [Studying for the interviews](#studying-for-the-interviews)
    - [System design](#system-design)
    - [Computer networks](#computer-networks)
    - [Linux and troubleshooting](#linux-and-troubleshooting)
        - [Linux internals and systems programming](#linux-internals-and-systems-programming)
        - [Troubleshooting](#troubleshooting)
    - [Coding](#coding)
    - [Soft skills](#soft-skills)
- [Final words](#final-words)


## Summary

In this document I go over the steps I took and resources I used when preparing
for the Production Engineer interview at Facebook. I believe the information I
provide here will be useful not only for those of you interviewing at Facebook,
but for anyone applying for SRE or Devops positions at other companies.


## Introduction

A few months ago, I started the interview process for a Production Engineer
(PE) role at Facebook. The PE role, from what I gathered reading online and
going through the interview process, is very similar (if not equal) to the
Site-Reliability Engineer (SRE) role in other companies (e.g., Google).

I think [this
guy](https://blog.balthazar-rouberol.com/preparing-the-sre-interview)
summarizes the responsibilites of a SRE and, by extension, of a PE very well:

> - Develop tools and systems reducing toil and repetitive work from engineers
> - Automate everything (deployments, maintenances, tests, scaling, mitigation)
> - Monitor everything
> - Think scalable from the start
> - Build resilient-enough architectures
> - Handle change and risk through SLAs, SLOs and SLIs
> - Learn from outages

If you read the items above and it perked your interest, I'd say you might be
someone who would likely enjoy working in this role and this guide ought to be
useful to you.

Writing about this is also useful to me, as I can reflect on my experience
and analyse the areas where I need to improve.

## My background

I used to work for a company as a software engineer, mostly maintaining
software that was responsibile for automated build of RPM packages.  I also did
some work on internal APIs and front-end programming.

Some of the work I did was devops-ish: managing Jenkins instances, writing
Ansible playbooks to automate my team's infrastructure, etc.

I'm not someone with a strict devops (or SRE) background.

## The interview process

I don't think there's much secret here. Basically all of the Big 4 (Amazon,
Facebook, Google, and Microsoft) interviews follow the same template: 2-3 phone
interviews, followed by a full day of onsite interviews (usually 5).

The first phone interview involved two coding exercises. Nothing crazy.  It was
something you would expect a sysadmin or devops professional do code.  The
difficult part is managing your time, though. I wasted some time on the first
question and had to rush the second one bit. In the end, I managed to solve
both. Again, beware of how you manage your time.

On the second phone interview, we covered some topics on Linux internals and
troubleshooting. Specifically on the troubleshooting part, it is not enough
to simply say "oh, I'd run X tool to check this". You have to know _why_ you
are checking that and explain it to the interviewer.

The second interviewer was nice too, but a bit more serious then the first.

After these two, Facebook flew me to their office for the onsite interviews.
They were five (5) in total:

- Systems design
- Computer Networks
- Linux and troubleshooting
- Coding (whiteboard)
- Soft-skills interview (with my would-be manager)

As you can see, the interviews I listed above are pretty standard for these
companies and this sort of role.

The onsite interview was really fun and challenging. Though I must admit it is
quite tiring. When I was done with all of the interviews I could feel my head
spinning. But I felt great after all that. I really pushed myself and solved
problems I had never seen before.

## Studying for the interviews

The recruiter was quite helpful. He sent me a list of topics to study for each
interview, as well as some suggested materials to read.

Here I list some other useful material I found on my own and my general
approach when studying for the interview.

### System design

Preparing for this interview boils down to this: know how to design distributed
systems, understand the trade-offs of different approaches.

The problem is how to go about learning that.

A friend of mine that is an SRE gave me an invuluable advice on this: **read
white papers**; a lot of them.

I never designed a distributed system, so I had no clue where to begin. Reading
a bunch of papers helped me grasp what the trade-offs of different
implementations were and what problems they helped solve. This is the skill you
should learn to do well in these interviews.

I basically read one paper a day until the onsite interviews. Honestly, I
didn't understand much from the first 4-5 papers I read. But then things
started to click and I was like "ooh, so they did this different from X,
because their system had this requirementent Y that was not present in X". Just
take your time and things will start to make sense.

If you don't know how to read papers effectively, read
[this](http://ccr.sigcomm.org/online/files/p83-keshavA.pdf).

Here's list of some papers I read:

1. [The Google File System](https://research.google.com/archive/gfs.html)
2. [The Hadoop Distributed File System](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.178.989&rep=rep1&type=pdf) 
3. [HopFS: Scaling Hierarchical File System Metadata](https://www.usenix.org/system/files/conference/fast17/fast17-niazi.pdf)
4. [The Chubby lock service for loosely-coupled distributed systems](https://research.google.com/archive/chubby.html)
5. [Maglev: A Fast and Reliable Network Load Balancer](https://research.google.com/pubs/pub44824.html)
6. [Cassandra - A Decentralized Structured Storage System](https://www.cs.cornell.edu/projects/ladis2009/papers/lakshman-ladis2009.pdf)
7. [Bigtable: A Distributed Storage System for Structured Data](https://cloud.google.com/bigtable/)
8. [Dynamo: Amazon‚Äôs Highly Available Key-value Store](http://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf)
9. [Finding a needle in Haystack - Facebook's photo storage](https://www.usenix.org/legacy/event/osdi10/tech/full_papers/Beaver.pdf)
10. [f4: Facebook‚Äôs Warm BLOB Storage System](https://www.usenix.org/system/files/conference/osdi14/osdi14-paper-muralidhar.pdf)
11. [Scaling Memcached at Facebook](https://www.usenix.org/system/files/conference/nsdi13/nsdi13-final170_update.pdf)

I'd suggest starting with the _Google File System_ (GFS) paper, then _Hadoop_
and _HopFS_. It makes sense to read them like this because that's the order
they were published. You should read the _Haystack_ paper before you read _f4_
one.

Just remember: **focus on identifying the trade-offs**. Don't worry about
understanding everything or how it was implemented.

[The Morning Paper](https://blog.acolyer.org) is a blog that has summaries of
an incredible number of papers. It proved itself to be a useful tool to check
my understading of what I read.

I'd also suggest getting familiar with stuff like
[HyperLogLog](https://en.wikipedia.org/wiki/HyperLogLog) (HLL). There is an
excellent post on Reddit's blog about how they used HLL to estimate the number
of views in posts.  You can find it
[here](https://redditblog.com/2017/05/24/view-counting-at-reddit/). If you read
this, pay attention to the constraints they had and the trade-offs of their
solution.

And last but not least: check out Donne's Martin [System Design
Primer](https://github.com/donnemartin/system-design-primer).  This is a gold
mine. Read as much of it as you can. The system design exercises are pretty
helpful and he has a lot of pointers to extra stuff you can read.


### Computer networks

No secret here: learn how TCP, UDP, DNS, HTTP, TLS/SSL work. Try to learn with
as much depth as you can:

- How does the `traceroute` program work?
- What is the difference between UDP and TCP? What guarantees does TCP give
  that UDP does not?
- How is a TCP connection stablished/terminated?
- How DNS works? What are common DNS query types?
- How does a HTTP request look like? What about a HTTP response? Also learn
  what the HTTP status codes are for.
- How does the TLS handshake work? Describe every step.

Grab a copy of _TCP/IP Illustrated: Volume 1_ and dig in. The writing is
excellent and straight to the point. Don't bother with Tanenbaum or Kurose.

On top of that, skim through the RFCs of each protocol.

I didn't have much time to study this, so I tried to get a broad view of
networking protocols. The only protocol I knew with reasonable depth was DNS.
Looking back, it would have helped to know more TCP more in-depth.

I also read Facebook's [Robotron: Top-down Network Management at Facebook
Scale](https://research.fb.com/publications/robotron-top-down-network-management-at-facebook-scale/)
paper. Very interesting to learn how they manage network devices configs. Also
(I learned this at the onsite), things like Robotron are developed by
Production Engineers. How cool is that?


### Linux and troubleshooting

#### Linux internals and systems programming

The standard advice here is to go read _Advanced Programming in the Unix
Environment_ (APUE), for the systems internals part. I'd say ditch that.

APUE is a great book, but it is only really useful if you are doing
cross-platform work. You don't need to know stuff about Solaris or BSDs; just
Linux.

The book I used to prepare for this was _The Linux Programming Interface_
(TLPI).  This is specifically about how Linux does things. The chapters are
quite short and easy to read.  I also liked the exercises a lot more than I
liked APUE's: they where shorter and focused on a single topic.

I mostly read stuff about processes, system calls, signals, and sockets. Learn
how to use pipes and sockets. It would be nice if you could code something to
apply these things.

Thorsten Ball has a few interesting posts on his blog for this. The one I found
specially useful was [Unicorn Unix Magic
Tricks](https://thorstenball.com/blog/2014/11/20/unicorn-unix-magic-tricks/).
This gave me a good understading on how to use forks and pipes for
inter-process communication. I then had a look at
[Unicorn](https://bogomips.org/unicorn/)'s and
[NGINX](https://github.com/nginx/nginx)'s sources: I wanted to see how they
managed workers and handled signals. I learned a lot from this.

After going through the sources and posts I mentioned above, I wrote my own web
server (in C) using `fork` and `pipe`s. It was nowhere near production level,
but it helped solidify what I had learned.


#### Troubleshooting

I read a lot of stuff on [Brendan's Gregg website](http://brendangregg.com).
This guy is awesome.  His writing is very accessible and there is a lot of
practical stuff.  If you have the time, make sure to grab a copy of his
_Systems Performance_ book. There are some really good insights there. I just
skimmed through it, but intend to give it a thorough read in the future.

The Netflix blog is also a good resource for this topic. I can specially
suggest their [Linux Performance Analysis in 60,000
Milliseconds](https://medium.com/netflix-techblog/linux-performance-analysis-in-60-000-milliseconds-accc10403c55)
post as a quick way to get familiar with some tools.

[Julia's Evans zines](https://jvns.ca/zines/) were very handy! Read them
all if you can. They are very short and fun; also served me as a nice break
from all that serious studying.

I also read a lot of the [Prometheus.io](https://prometheus.io) documentation
and set it up on an VM. I found this useful to understand what kinds of metrics
I could collect from a server and how to analyse the data.

Actually practicing troubleshooting was something I didn't manage to do very
well. I tried writing a few simple programs, running the debugging tools on
them, and figuring out what the output meant. Running `strace` on a bunch of
programs and checking the data I got was very helpful in my troubleshooting
interview. 

I think it would be an excelent experience if you had a friend set up a server
with some app running, break something, and have you find out what the problem
is.

### Coding

This is pretty much common knowledge by now, but here it goes: you should know
your data structures and algorithms well, and be comfortable writing code
outside of an IDE. It is specially helpful if you time yourself solving
problems.  Try to keep it under 30 minutes for each exercise.

When preparing for this kind of interview, a lot of people say _Cracking the
Coding Interview_ is the way to go. It didn't work for me.

I bought the book and skimmed a bit through it. Most of the exercises were
pretty simplistic and I didn't feel they were actually helping me.

So I took a different route:

- Read about and implemented some simple data structures: linked lists, binary
  trees, hash tables, and graphs.
- Read about and implemented some standard algorithms: binary search, insertion
  sort, radix sort, merge sort, depth-first search, and breadth-first search.
- Read about dynamic programming.
- Solved a bunch of problems from [LeetCode](https://leetcode.com).

LeetCode was probably the best resource for this. I used this [list of LeetCode
problems by
company](http://www.learn4master.com/interview-questions/leetcode/leetcode-problems-classified-by-company)
. I tried to solve as many of the ones listed under "Facebook" as I could.

Now, I'm someone who never participated in programming competitions. Solving
this sort of problems is not something that comes easy for me. When I started
working on the LeetCode problems, I could not solve most of the exercises. So I
just read the solutions other people posted there and typed them in my text
editor. When I did this, I just focused on understanding how the solution
worked. Then I'd make a note to retry that exercise a few days later.
Sometimes, I was able to solve it right away on a second attempt; oftentimes, I
would not. So I just kept retrying some time later until I got it.

I'd say after I had solved around 20-30 problems things started to click and I
managed to solve a lot more with ease. **If you're having a hard time solving
these problems, just keep at it and things will start to make sense sooner than
you would expect.**

### Soft skills

I'm bad at interviewing. I remember when I was in uni and did one of my
very first job interviews. I was asked what my greatest weakness
was: I had absolutely no clue what I should answer.

There are a lot of "HR questions" that are pretty standard, like the "What are
your weaknesses?" above. You know they will come, so prepare for them.

I spent some time thinking and researching what kinds of questions I could be
asked. Then I wrote down my answers and rehearsed them out loud. Yeah, I know
it sounds like a chore, but this is pretty useful. For me, there's nothing
worse than being caught off guard by a question and having no clue what to
answer.

I even recorded my answers on my phone and played them back to check
how they sounded. If they were too long, I'd trim the excess and try again; if
they were to simplistic, I'd add more details.

I got the idea of rehearsing and a lot of other tips from a blog called
[HRNasty](http://hrnasty.com). Give it a shot.

Also, try to learn about the challenges of working in a PE/SRE/Devops team.
This will give a good idea of things to talk about with the
manager/interviewer.

Read Google's [SRE book](https://landing.google.com/sre/book.html). It won't
tell you how every PE/SRE/Devops team works, but it will at least give you an
idea of how one company approaches this.


## Final words

If you made it this far, thank you for reading all this.

Interviewing is hard. I hope that by sharing my experience I can help others
prepare for this kind of interviews. In case you found this text helpful,
please share it with anyone you know is preparing to go through the interview
process. It might be of use to them as well.

I also hope that this post serves to divulge more information about the
Production Engineer role at Facebook.
