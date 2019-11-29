# Abstract

- This document explores what composes a multi-sig wallet, how it works, single-key vs multisig, increasing security, two-factor authentication, escrow transactions, decision making and more.

## About Multisig

1. Def & History
   1. Multisig stands for multi-signature, which is a specific type of digital signature that makes it possible for two or more users to sign documents as a group. Therefore, a multi-signature is produced through the combination of multiple unique signatures.
      1. Multisig technology has been extant within the world of cryptocurrencies, but the principle is one that existed long before the creation of Bitcoin.
      2. In the context of cryptocurrencies, the technology was first applied to Bitcoin addresses in 2012, which eventually led to the creation of multisig wallets, one year later. Multisig addresses may be used in different contexts, but most use cases are related to security concerns.
2. Concepts
   1. Fund stored on a multi-signature address can only be **accessed by using 2 or more signatures**. Therefore, the use of a multisig wallet enables users to **create an additional layer of security to their funds**.
      1. Ex. We can imagine a secure deposit box that has two locks and two keys. One key is held by Alice and the other one is held by Bob. **The only way they can open the box is by providing their both keys at the same time, so one cannot open the box without the consent of the other**.
      2. It is important to understand the basics of a **standard Bitcoin address, which relies on a single key instead of multiple** (single-key address)
3. Single-key vs. Multisig
   1. **Bitcoins are stored in a standard, single-key address, meaning that whoever holds the corresponding private key is able to access the funds**. This means that only one key is needed to sign transactions and that anyone that has the private key, is able to transfer the coins at will, without authorization from anybody else.
   2. **While managing a single-key address is faster and easier than a multisig one, it presents a number of issues, especially in regards to security**. By having a single key, the funds are protected by a single point of failure, and that is why cyber criminals are constantly developing new phishing techniques to try and steal the funds of cryptocurrency users.
   3. Moreover, **single-key addresses are not the best option for businesses involved with cryptocurrencies**. Imagine the funds of a big company being stored on a standard address, which has a single corresponding private key. This would imply that the private key would be either entrusted to a single person or multiple individuals at the same time - and that is clearly not the safest way to go.
      1. Multsig wallets offer a potential solution to both of these problems. Unlike single-key, the funds stored on a multisig address can only be moved if multiple signatures are provided (which are generated through the use of different private keys)
   4. **According to the way a multisig address is configured, it may require a different combination of keys**: 2-of-3 is the most common one, where only 2 signatures are sufficient to access the funds of a 3-signature address. However, there are many other variations, such as 2-of-2, 3-of3, 3-of-4, etc.

## Security & use cases

1. Increasing security
   1. By using a multisig wallet, users are able to prevent the problems caused by the loss or theft of a private key. So even if one of the keys are compromised, the funds are still safe.
2. Two-factor authentication
   1. **By creating a multisig wallet that requires two keys, Alice is able to create a two-factor authentication(two-keys) mechanism to access her fund**s.
      1. For instance, Alice have one private key stored in her laptop and the other one in her mobile device. This would ensure that only someone who has access to both keys is able to make a transaction.
      2. Using multisig technology as a two-factor authentication can be dangerous especially if it is set as a 2-of-2 multisig address. If one of the keys are lost, you won't be able to access your funds. Therefore, using a 2-of-3 setup or third party 2FA service that counts with backup codes would be safer. When it comes to exchange trading accounts, using Google Authenticator is highly recommended.
3. Escrow transactions
   1. Creating a 2-of-3 multisig wallet can **allow for an escrow transaction between two parties that includes a third party as a mutually trusted arbiter in case anything goes wrong**.
4. Decision making
   1. A board of directors might use a multisig wallet to control access to a company's fund.
   2. Ex. by setting up a 4-of-6 wallet where each board member holds one key, no individual board member is able to misuse the funds. Therefore, **only decisions that are agreed upon by the majority can be executed**.

## Disadvantages & closing thoughts

1. Disadvantages
   1. Although multisig wallets are a good solution for a range of problems, it is important to keep in mind that there are some risks and limitations involved. **Setting up a multisig address requires some technical knowledge**, especially if you do not want to rely on third-party providers
   2. Additionally, since blockchain and multisig addresses are both relatively new, it may be **difficult to seek legal recourse** if something goes wrong. **There is no legal custodian of funds deposited into a shared wallet with multiple keyholders**.
2. Closing thoughts
   1. Despite having a few disadvantages, multisig wallet have numerous interesting applications, making Bitcoin and other cryptocurrencies even more useful and appealing - especially to businesses. By requiring more than one signature to transfer funds, **multisig wallets provide enhanced security and allow for trustless escrow transactions**, and as such, the technology is likely to see increasing usage in the future.
