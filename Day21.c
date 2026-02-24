/* Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6 */
#include <stdio.h>
#include <stdlib.h>

// Hash map node structure
struct Node {
    int prefixSum;
    int count;
    struct Node* next;
};

// Hash function
int hash(int key, int size) {
    if (key < 0) key = -key;
    return key % size;
}

// Insert or update prefix sum in hash map
void insert(struct Node** hashTable, int size, int prefixSum) {
    int index = hash(prefixSum, size);
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->prefixSum == prefixSum) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prefixSum = prefixSum;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Get count of prefix sum from hash map
int getCount(struct Node** hashTable, int size, int prefixSum) {
    int index = hash(prefixSum, size);
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->prefixSum == prefixSum) {
            return temp->count;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int size = 10007; // hash table size
    struct Node* hashTable[size];
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }

    int prefixSum = 0;
    int count = 0;

    // Insert prefix sum 0 initially
    insert(hashTable, size, 0);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        count += getCount(hashTable, size, prefixSum);
        insert(hashTable, size, prefixSum);
    }

    printf("%d\n", count);
    return 0;
}
