#ifndef SUBARRAY_H
#define SUBARRAY_H
#include <stddef.h>  // for NULL

// Prime number for hash table size to reduce collisions
#define MAX_SIZE 10007

// Forward declaration of hash table node
typedef struct element element;

// Hash table node to store a sum and how many times it appeared
struct element {
    int key;            // The sum value
    int occurrence;     // How many times the sum occurred
    element* next;      // Pointer to next node in the same hash bucket
};

// Hash function: maps a sum to a bucket index
int Hash(int key);

// Add a sum to the hash table or increment its count
void AddOrCreate(element** hashtable, int key);

// Count subarrays with sum k
int subarraySum(int* nums, int n, int k);

#endif
