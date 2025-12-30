#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"
int Hash(int key){
    int hashed=key%MAX_SIZE;
    if (hashed>=0)
    return hashed;
    else
    return hashed+MAX_SIZE;
}
void AddOrCreate(element** hashtable, int key) {
	int idx = Hash(key);
	element* cur = hashtable[idx];
	while (cur) {
		if (cur->key == key) {
			cur->occurance++;
			return;
		}
		cur = cur->next;
	}
	element* p = (element*)malloc(sizeof(element));
	p->key = key;
	p->occurance = 1;
	p->next = hashtable[idx];
hashtable[idx] = p;
}
element* Find(element** hashtable, int key) { 
	int idx = Hash(key);
	element* cur = hashtable[idx];
	while (cur) {
		if (cur->key == key) return cur;
		cur = cur->next;
	}
	return NULL;
}
int subarraySum(int* nums, int n, int k) {
    element* hashtable[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) hashtable[i] = NULL;

    AddOrCreate(hashtable, 0); // empty prefix

    int current_sum = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        current_sum += nums[i];

        int target = current_sum - k;
        element* found = Find(hashtable, target);
        if (found) res += found->occurance;

        AddOrCreate(hashtable, current_sum);   // record current for future
    }

    return res;
}