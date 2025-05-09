#include <stdlib.h>
#include "lista.h"
#include "node.h"
#include "cliente.h"

struct Lista_ {
    Node *inicio;
    Node *fim;
    int quantidade;
};

Lista* cria_lista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL) {
        return NULL;
    }
    
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;
    
    return lista;
}

void libera_lista(Lista *lista, int libera_dados) {
    if (lista != NULL) {
        Node *atual = lista->inicio;
        Node *prox = NULL;
        
        while (atual != NULL) {
            prox = get_next(atual);
            
            if (libera_dados) {
                libera_cliente(get_data(atual));
            }
            
            libera_node(atual);
            atual = prox;
        }
        
        free(lista);
    }
}

int insere_inicio(Lista *lista, void *data) {
    if (lista == NULL) {
        return 0;
    }
    
    Node *node = cria_node(data);
    if (node == NULL) {
        return 0;
    }
    
    if (lista->inicio == NULL) {
        lista->inicio = node;
        lista->fim = node;
    } else {
        set_next(node, lista->inicio);
        lista->inicio = node;
    }
    
    lista->quantidade++;
    return 1;
}

int insere_fim(Lista *lista, void *data) {
    if (lista == NULL) {
        return 0;
    }
    
    Node *node = cria_node(data);
    if (node == NULL) {
        return 0;
    }
    
    if (lista->fim == NULL) {
        lista->inicio = node;
        lista->fim = node;
    } else {
        set_next(lista->fim, node);
        lista->fim = node;
    }
    
    lista->quantidade++;
    return 1;
}

Node* get_inicio(Lista *lista) {
    if (lista == NULL) {
        return NULL;
    }
    
    return lista->inicio;
}

Node* get_fim(Lista *lista) {
    if (lista == NULL) {
        return NULL;
    }
    
    return lista->fim;
}

int get_quantidade(Lista *lista) {
    if (lista == NULL) {
        return 0;
    }
    
    return lista->quantidade;
}

int esta_vazia(Lista *lista) {
    if (lista == NULL) {
        return 1;
    }
    
    return (lista->quantidade == 0);
}