#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a value into the hash table
void insert(int value) {
    int index = hashFunction(value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Search for a value in the hash table
int search(int value) {
    int index = hashFunction(value);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Value found
        }
        current = current->next;
    }
    return 0; // Value not found
}

int main() {
    // Initialize the hash table to NULL
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert some values into the hash table
    insert(3);
    insert(5);
    insert(9);
    insert(14);

    // Search for a value in the hash table
    int value = 5;
    if (search(value)) {
        printf("%d is in the hash table\n", value);
    } else {
        printf("%d is not in the hash table\n", value);
    }

    return 0;
}