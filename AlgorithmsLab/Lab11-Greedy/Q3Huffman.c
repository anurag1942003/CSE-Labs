#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct htnode* Node;

typedef struct htnode {
    char title;
    float value;
    struct htnode *left, *right;
} htnode;

Node initNode (char title, float value) {
    Node node = (Node) malloc(sizeof(htnode));
    node->title=title;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node nodes[100];
Node head;

int n;
int i, j;

void input () {
    printf("Enter number of characters: ");
    scanf(" %d", &n);
    for (i = 0; i < n; ++i) {
        char title;
        float value;
        printf("Character [%d], enter symbol and value: ", i);
        scanf(" %c", &title);
        scanf(" %f", &value);
        Node node = initNode(title, value);
        nodes[i] = node;
    }
}

void sort () {
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            Node a = nodes[j];
            Node b = nodes[j+1];
            if (a->value < b->value) {
                Node c = a;
                nodes[j] = b;
                nodes[j+1] = c;
            }
        }
    }
}

void huffman () {
    do {
        sort();
        if (n > 1) {
            Node a = nodes[n-1];
            Node b = nodes[n-2];
            Node c = initNode("*", a->value + b->value);
            c->left = a;
            c->right = b;
            nodes[n-2] = c;
            n -= 1;
        }
    } while (n > 1);
    head = nodes[0];
}

void printHuffmanCodes(Node head, char code[], int top) {
    if (head->left == NULL && head->right == NULL) {
        code[top] = '\0'; // Add null terminator to the code string
        printf("%c: %s\n", head->title, code);
        return;
    }
    if (head->left != NULL) {
        code[top] = '0';
        printHuffmanCodes(head->left, code, top+1);
    }
    if (head->right != NULL) {
        code[top] = '1';
        printHuffmanCodes(head->right, code, top+1);
    }
}


int main () {
    input();
    huffman();
    int top=0;
    char code[100];
    printHuffmanCodes(head,code,top);
    return 0;
}
