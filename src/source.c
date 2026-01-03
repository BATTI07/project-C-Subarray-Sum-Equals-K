#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

// Hash function: maps a sum to a bucket index
int Hash(int key) {
    int hashed = key % MAX_SIZE;
    if (hashed >= 0) 
        return hashed;
    else 
        return hashed + MAX_SIZE;
}

// Add a sum to the hash table or increment its occurrence
void AddOrCreate(element** hashtable, int key) {
    int idx = Hash(key);
    element* cur = hashtable[idx];

    // Check if the sum already exists in this bucket
    while (cur) {
        if (cur->key == key) {
            cur->occurrence++;
            return;
        }
        cur = cur->next;
    }

    // Sum not found → create a new node
    element* p = (element*)malloc(sizeof(element));
    p->key = key;
    p->occurrence = 1;
    p->next = hashtable[idx];
    hashtable[idx] = p;
}

// Find a sum in the hash table
element* Find(element** hashtable, int key) {
    int idx = Hash(key);
    element* cur = hashtable[idx];
    while (cur) {
        if (cur->key == key) return cur;
        cur = cur->next;
    }
    return NULL;
}

// Free all memory in the hash table
void FreeHashTable(element** hashtable) {
    for (int i = 0; i < MAX_SIZE; i++) {
        element* cur = hashtable[i];
        while (cur) {
            element* temp = cur;
            cur = cur->next;
            free(temp);
        }
        hashtable[i] = NULL; // optional: clear pointer
    }
}

// Count number of subarrays with sum == k
int subarraySum(int* nums, int n, int k) {
    element* hashtable[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) 
        hashtable[i] = NULL;

    AddOrCreate(hashtable, 0); // empty prefix sum

    int prefix_sum = 0;   // running total of array
    int count = 0;        // number of valid subarrays found

    for (int i = 0; i < n; i++) {
        prefix_sum += nums[i];

        int target = prefix_sum - k;           // Look for previous sum that makes subarray sum == k
        element* node = Find(hashtable, target);
        if (node) 
            count += node->occurrence;

        AddOrCreate(hashtable, prefix_sum);   // Record current sum for future
    }

    FreeHashTable(hashtable);  // Clean up all allocated memory
    return count;
}
