#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    struct Node * next;
    void * content;
};

struct Libro {
    char* titulo;
    int paginas;
};

int countNodes(struct Node * node) {
    struct Node * temp = node;
    int count = 0;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

bool empty(struct Node * node) {
    return !node->content;
}

struct Node * vector() {
    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
    node->next = NULL;
    node->content = malloc(sizeof(void *));
    node->content = NULL;
    return node;
}

/*Checar si el primero esta vacio*/
struct Node * vectorSize(size_t n) {
    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
    node->content = malloc(sizeof (void *));
    node->content = NULL;
    struct Node * temp = node;

    for(int i = 0; i < n-1; i++){
        struct Node * newNode = (struct Node *) malloc(sizeof (struct Node));
        newNode->content = malloc(sizeof (void *));
        newNode->content = NULL;
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

    for(int i = 0; i < n; i++) {
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
    for(int i = 0; i < pos -1; i++){
        temp = temp->next;
    }
    struct Node * aux = temp->next;
    struct Node * newNode = (struct Node *) malloc(sizeof (struct Node));
    newNode->content = malloc(sizeof(void *));
    newNode->content = content;
    newNode->next = aux;
    temp->next = newNode;
}

struct Node * insertN(struct Node * node, int pos, size_t n, void * content) {
    if (pos > countNodes(node)){
        printf("Index out of bounds");
        return node;
    }
    /*
     * Crear nodo, ponerle contenido y agregarle el siguiente nodo
     * Al final, ponemos el primer nodo como next del último y regresamos el primero que creamos.
     *
     * */
    struct Node * temp = node;
    if(pos == 0) {
        struct Node * newNode = (struct Node *) malloc(sizeof (struct Node *));
        newNode->content = malloc(sizeof (void *));
        newNode->content = content;

        struct Node * aux = newNode;
        for(int i = 0; i < n-1; i++) {
            struct Node * newNode1 = (struct Node *) malloc(sizeof (struct Node *));
            newNode1->content = malloc(sizeof (void *));
            newNode1->content = content;
            aux->next = newNode1;
            aux = aux->next;
        }
        aux->next = temp;
        return newNode;
    }

    struct Node * previous;
    for(int i = 0; i < pos; i++) {
        previous = temp;
        temp = temp->next;
    }

    for(int j = 0; j < n; j++) {
        struct Node * newNode = (struct Node *) malloc(sizeof (struct Node *));
        newNode->content = malloc(sizeof (void *));
        newNode->content = content;
        previous->next = newNode;
        previous = previous->next;
    }

    previous->next = temp;
    return node;
}

void pushBack(struct Node * node, void * content) {

    if(node->next == NULL) {
        node->content = content;
        return;
    }

    struct Node * temp = node;


    struct Node * previous;
    while(temp->next) {
        temp = temp->next;
    }
    if (temp->content == NULL) {
        temp->content = content;
        return;
    }
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->content = malloc(sizeof(void *));
    newNode->content = content;
    temp->next = newNode;
    return;
}

void popBack(struct Node * node) {
    struct Node * temp = node;
    struct Node * previous;

    while(temp->next){
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    temp->content = NULL;
    temp = NULL;
    free(temp);
}

void printNodes(struct Node * node) {
    if (empty(node)) {
        printf("Empty list");
        return;
    }
    while(node) {

        if(node->content != NULL)
        printf(node->content);
        node = node->next;
    }
    printf("\n");
}

void printInt(struct Node* node){
    if (empty(node)) {
        printf("Empty list");
        return;
    }
    while (node)
    {
        printf(" %4d", (int *)node->content);
        node = node->next;
    }
    printf("\n");
}

void printLibro(struct Node* node){
    if (empty(node)) {
        printf("Empty list");
        return;
    }
    while (node)
    {
        printf("Title: %s Pages: %d \n", ((struct Libro*) node->content)->titulo,((struct Libro*) node->content)->paginas);
        node = node->next;
    }
    printf("\n");
}

typedef void (*printer)(struct Node* node);

void printAll(struct Node* node, printer print){
    (*print)(node);
}

void freeNodes(struct Node * node) {
    while(node) {
        struct Node * temp = node;
        node = node->next;
        free(temp);

    }
}



struct Node * erase(struct Node * node, int pos) {
    struct Node * temp = node;
    if(pos == 0) {
        if(temp->next) {
            struct Node * newHead = temp->next;
            free(temp);
            return newHead;
        }
        temp->content = NULL;
        return node;
    }
    struct Node * previous;
    for(int i = 0; i < pos; i++) {
        previous = temp;
        temp = temp->next;
    }

    if(temp->next) {
        struct Node * nextNode = temp->next;
        previous->next = nextNode;
        free(temp);
        return node;
    }

    previous->next = NULL;
    free(temp);
    return node;
}

struct Node * front(struct Node * node){
    return node;
}

struct Node * back(struct Node * node){
    struct Node * temp = node;
    while(temp->next){
        temp = temp->next;
    }
    return temp;
}

int begin(struct Node* node) {
    return 0;
}

int end(struct Node* node) {
    return countNodes(node) -1;
}

int next(struct Node* node, int current) {
    return current++;
}

struct Node * eraseRange(struct Node * node, int start, int end) {

    int range = (end - start);

    for(int i = 0; i <= range; i++) {
        node = erase(node, start);
    }
    return node;
}

int main() {

    int uno = 1;
    int dos = 2;
    int tres = 3;
    size_t m = 3;

    struct Node * intVector = vector();
    pushBack(intVector, dos);
    intVector = insertN(intVector, 0, 1 ,uno);
    insert(intVector, 2 , tres);

    printAll(intVector, &printInt);


    char * a = "a";
    char * b = "b";
    char * c = "c";
    size_t n = 3;

    struct Node * charVector = vector();
    pushBack(charVector, a);
    charVector = insertN(charVector, 1, 1 ,b);
    insert(charVector, 2,c);



     printAll(charVector, &printNodes);

     struct Libro hp;
     hp.titulo="Harry Potter";
     hp.paginas = 389;
     struct Libro lotr;
     lotr.titulo="Lord of the Rings";
     lotr.paginas = 789;
     struct Libro got;
     got.titulo="Game of Thrones";
     got.paginas = 987;
     struct Libro sw;
     sw.titulo = " Star Wars";
     sw.paginas = 542;

     struct Node * libroVector = vector();

     libroVector = insertN(libroVector, 0, 2, &hp);
     pushBack(libroVector, &lotr);


    printAll(libroVector, &printLibro);

    freeNodes(charVector);

    return 0;
}




