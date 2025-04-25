#include <stdlib.h>
#include "estrutura.h"

typedef struct no {
    Requisicao *requisicao;
    struct no *proximo;
} No;

struct Estrutura_ {
    No *inicio;
    No *fim;
    int tamanho;
};

Estrutura* create() {
    Estrutura *estrutura = (Estrutura*) malloc(sizeof(Estrutura));

    if (estrutura != NULL) {
        estrutura->inicio = NULL;
        estrutura->fim = NULL;
        estrutura->tamanho = 0;
    }

    return estrutura;
}

void libera_estrutura(Estrutura *estrutura) {
    if (estrutura != NULL) {
        No *atual = estrutura->inicio;
        No *proximo;

        while (atual != NULL) {
            proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }

    free(estrutura);
}

void inserir(Estrutura *estrutura, Requisicao *requisicao) {
    No *novo_no = (No *) malloc(sizeof(No));

    if (novo_no != NULL) {
        novo_no->requisicao = requisicao;
        novo_no->proximo = NULL;

        if (estrutura->inicio == NULL) {
            estrutura->inicio = novo_no;
        } else {
            estrutura->fim->proximo = novo_no;
        }

        estrutura->fim = novo_no;
        estrutura->tamanho++;
    }
}

Requisicao* remover(Estrutura *estrutura) {
    if (estrutura->inicio == NULL) {
        return NULL;
    }

    No *no_removido = estrutura->inicio;
    Requisicao *requisicao = no_removido->requisicao;

    estrutura->inicio = no_removido->proximo;

    if (estrutura->inicio == NULL) {
        estrutura->fim = NULL;
    }

    free(no_removido);
    estrutura->tamanho--;

    return requisicao;
}

int get_size(Estrutura *estrutura) {
    return estrutura->tamanho;
}