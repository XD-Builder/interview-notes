# About O(1) Labs

- A company that uses cryptography and cryptocurrency to build computing systems that put people back in control of their digital lives.
- The company currently has two projects
  - CODA is the first cryptocurrency protocol with a constant-sized blockchain
  - Snarky is an OCaml front-end for writing R1CS SNARKs

## About CODA

1. What is?
   1. Coda is the first cryptocurrency protocol with a constant-sized blockchain. Coda compresses the entire blockchain into a tiny snapshot the size of a few tweets.
      1. It means that no matter how many transactions are performed, verifying the blockchain remains inexpensive and accessible to everyone
   2. **Coda is a cryptocurrency that can scale to millions of users and thousands if transactions per second while remaining decentralized**.
      1. Any client, including smartphones, will be able to instantly validate the state of the ledger. This is in service of our goal to make software transparent, legible, and respectful
2. Features
   1. Compact blockchain
      1. Coda uses recursive composition of zk-SNARKs to compress the whole blockchain down to the size of a few tweets. No one needs to store or download transaction history in order to verify the blockchain
   2. Instant sync
      1. Coda syncs instantly, allowing you to verify the blockchain even on a mobile phone. Interact with the blockchain anywhere.

## About Snarky

1. What is?
   1. An OCaml front-end for writing R1CS SNARKs. It is modular over the backend SNARK library, and comes with backends from libsnark.
   2. R1CS
      1. rank-1 constraint system.
      2. **A sequence of groups of three vectors (a, b, c), and the solution to an R1CS is a vector s, where s must satisfy the equation s . a \* s . b - s . c = 0, where . represents the dot product** - in simpler terms, if we "zip together" a and s, multiplying the two values in the same positions, and then take the sum of these products, then do the same to b and s and then c and s, then the third result equals the product of the first two results.

## What is zk-SNARKs

1. What is?
   1. Zcash is the first widespread application of zk-SNARKs.
   2. zk-SNARKs is **a novel form of zero-knowledge cryptography**.
      1. The strong **privacy guarantee of Zcash is derived from the fact that shielded transactions in Zcash can be fully encrypted on the blockchain**, yet **still be verified as valid under the network's consensus rules by using zk-SNARK proofs**.
   3. The acronym for zk-SNARK stands for "**Zero-Knowledge Succinct Non-Interactive Argument of Knowledge**"
      1. A proof construction where one can prove possession of certain information, e.g. a secret key, without revealing that information, and without any interaction between the prover and verifier.
2. What it does?
   1. **It allows one party to prove to another (the prover to the verifier) that a statement is true, without revealing any information beyond the validity of the statement itself**.
      1. Ex. Given the hash of a random number, the prover could convince the verifier that there indeed exists a number with this hash value, without revealing what it is.
   2. In zero-knowledge "Proof of Knowledge", the prover can can convince the verifier not only that the number exists, but that they in fact know such a number.
   3. **"succinct" zero-knowledge proofs can be verified within a few milliseconds, with a proof length of only a few hundred bytes even for statements about programs that are very large.**
      1. **In the first zero-knowledge protocols, the prover and verifier had to communicate back and forth for multiple rounds**, but in **“non-interactive” constructions, the proof consists of a single message sent from prover to verifier**. Currently, **the most efficient** known way to produce zero-knowledge proofs that are non-interactive and short enough to publish to a block chain is to **have an initial setup phase that generates a common reference string shared between prover and verifier. We refer to this common reference string as the public parameters of the system**.
         1. **If someone had access to the secret randomness used to generate these parameters, they would be able to create false proofs that would look valid to the verifier**. For Zcash, this would mean the malicious party could create counterfeit coins. **To prevent this from ever happening, Zcash generated the public parameters through an elaborate, multi-party ceremony**.
3. How zk-SNARKs are constructed in Zcash
   1. In order to have zero-knowledge privacy in Zcash, the function determining the validity of a transaction according to the network's consensus rules must return the answer of whether the transaction is valid or not, without revealing any of the information it performed the calculations on. This is done by encoding some of the network's consensus rules in zk-SNARKs.
   2. At a high level, zk-SNARKs work by first turning what you want to prove into an equivalent form about knowing a solution to some algebraic equations. 
      1. **Computation → Arithmetic Circuit → R1CS → QAP → zk-SNARK**
         1. **The first step in turning our transaction validity function into a mathematical representation is to break down the logical steps into the smallest possible operations, creating an “arithmetic circuit”. Similar to a boolean circuit where a program is compiled down to discrete, single steps like AND, OR, NOT, when a program is converted to an arithmetic circuit**, it’s broken down into single steps consisting of the basic arithmetic operations of addition, subtraction, multiplication, and division (although in our particular case, we will avoid using division).
         2. Our next step is to build what is called a Rank 1 Constraint System, or R1CS, to check that the values are “traveling correctly”. In this example, the R1CS will confirm, for instance, that the value coming out of the multiplication gate where b and c went in is b*c.
            1. In this R1CS representation, the verifier has to check many constraints — one for almost every wire of the circuit. (For technical reasons, it turns out we only have a constraint for wires coming out of multiplication gates.) In a 2012 paper on the topic, Gennaro, Gentry, Parno and Raykova presented a nice way to “bundle all these constraints into one”. This method uses a representation of the circuit called a Quadratic Arithmetic Program (QAP). **The single constraint that needs to be checked is now between polynomials rather than between numbers. The polynomials can be quite large, but this is alright because when an identity does not hold between polynomials, it will fail to hold at most points. Therefore, you only have to check that the two polynomials match at one randomly chosen point in order to correctly verify the proof with high probability.**

## Turing complete

1. What is?
   1. A term used in computability theory to describe abstract machines, usually called automata. **Such an automation is Turing complete, if it can be used to emulate a Turing machine**. It is also called computationally universal.
   2. Most modern programming languages are Turing complete.
2. What is not Turing complete
   1. There are languages that are used to classify and describe the contents of document like HTML which is not Turing complete because it cannot actively change the state of the system.
      1. HTML can be combined with a technology such as JavaScript; both together can be made Turing complete.
   2. The standard regular expressions, which most programming languages use are not Turing complete either.
      1. **Most regular expression engines have been adapted to include back-references. The problem with this is that a finite automation cannot handle back references**.
