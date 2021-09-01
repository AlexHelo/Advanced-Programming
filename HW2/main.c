#include <stdio.h>
#include <stdlib.h>

#define N 10;

struct Node {
    struct Node * next;
    void * content;
};


struct Node * vector() {
    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
    node->content = malloc(sizeof(void *));
    return node;
}


struct Node * vectorSize(size_t n) {
    struct Node * node;
    struct Node * temp = node;
    for(int i = 0; i < n; i++){
        struct Node * newNode = (struct Node *) malloc(sizeof (struct Node));
        newNode->content = malloc(sizeof (void *));
        temp->next = newNode;
        temp = newNode;
    }

    return node;
}

struct Node * vectorCopy(size_t n, void * content) {
    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
    node->content = malloc(sizeof(void *));
    node->content = content;
    struct Node * temp = &node;

    for(int i = 0; i < n; i++){
        struct Node * newNode  = (struct  Node *) malloc(sizeof (struct Node));
        newNode->next = NULL;
        newNode->content = malloc(sizeof (content));
        newNode->content = content;
        temp->next = newNode;
        temp = newNode;
    }

    return node;
}


void insert(struct Node * node, int pos, void * content) {
    struct Node * temp = node;
    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }
    struct Node * aux = temp->next;
    struct Node * newNode = (struct Node *) malloc(sizeof (struct Node));
    newNode->content = malloc(sizeof(void *));
    newNode->content = content;
    newNode->next = aux;
    temp->next = newNode;
}
void insertN(int pos, size_t n, void * content) {

}

void printNodes(struct Node * node) {

    while(node) {
        printf(node->content);
        node = node->next;
    }

}

void freeNodes(struct Node * node) {
    while(node) {
        struct Node * temp = node;
        node = node->next;
        free(temp);

    }
}

int main() {
    int integer = 5;
    char * string = "hola";
    size_t n = 2;
    struct Node * test = vector();

    insert(test, 0, (void *) string);
    insert(test, 1, (void *) string);
    printNodes(test);
    freeNodes(test);

    return 0;
}




