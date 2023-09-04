// Double hashing uses two hash functions instead of just one. When a collision happens,
//  the second hash function is used to calculate a new index for the item. This second hash function typically incorporates additional parameters, 
//  such as the original hash value or the number of previous collisions, to determine the new index.

// The idea is to probe different indices based on the original hash value until an empty or available slot is found in the hash table.
//  By using a different hash function, double hashing aims to distribute the data more evenly across the table and reduce the likelihood of collisions.

// When inserting or searching for an item in a hash table using double hashing, 
// the process involves calculating the initial hash value and then applying the second hash function until an empty slot or the desired item is found.