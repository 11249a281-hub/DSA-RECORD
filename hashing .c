#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1; // -1 indicates empty
}

// Simple hash function
int hash(int key) {
    return key % SIZE;
}

// Insert a key into hash table
void insert(int key) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search a key
void search(int key) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        if (index == originalIndex)
            break;
    }
    printf("%d not found in hash table\n", key);
}


