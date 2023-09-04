Universal hashing is a technique used in hashing where the hash function is randomly selected from a set of possible hash functions. This random selection helps to reduce the likelihood of collisions and improve the overall performance of the hash table.

Here's a simplified explanation of universal hashing with an example:

Imagine you have a set of four hash functions: H1, H2, H3, and H4. Each of these hash functions takes a key as input and produces a hash value. Now, instead of using a single fixed hash function, you randomly choose one of these four hash functions for each key that you want to store in the hash table.

For example, let's say we want to hash two keys: "apple" and "banana."

1. For the key "apple," we randomly select hash function H3.
   H3("apple") = 7.

2. For the key "banana," we randomly select hash function H1.
   H1("banana") = 2.

Now we have the hash values: 7 for "apple" and 2 for "banana."

By using different hash functions for different keys, we can distribute the keys more evenly across the hash table, reducing the chance of collisions and improving the performance of the hash table. With each key, we randomly select a hash function from the set of possible hash functions, ensuring a more uniform distribution of keys.

The key idea behind universal hashing is that the specific hash function used for each key is chosen randomly, making it difficult for an adversary to predict or deliberately craft inputs that could cause a high number of collisions.

In practice, the set of possible hash functions is often defined by using prime numbers and modular arithmetic operations, but the important concept is that the specific hash function is chosen randomly from this set.

By employing universal hashing, we can achieve better performance and security in hash tables by minimizing collisions and distributing the keys more evenly across the available slots.