#include <stdlib.h>
#include "node.h"

struct Node_ {
    void *data;
    Node *next;
};

Node* cria_node(void *data) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

void libera_node(Node *node) {
    if (node != NULL) {
        free(node);
    }
}

void* get_data(Node *node) {
    return node->data;
}

Node* get_next(Node *node) {
    return node->next;
}

void set_next(Node *node, Node *next) {
    if (node != NULL) {
        node->next = next;
    }
}