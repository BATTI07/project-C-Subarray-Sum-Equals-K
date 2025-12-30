#ifndef SUBARRAY_H
#define SUBARRAY_H
#define MAX_SIZE 10007 // first prime after 10^4 to avoid collisions

int subarraySum(int* nums, int n, int k);
typedef struct element element;
struct element {
    int key;
    int occurance;
    element* next;
};
int Hash(int key);
void AddOrCreate(element** hashtable,int key);
#endif
