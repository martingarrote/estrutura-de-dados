#include <string.h>
#include <stdlib.h>
#include "requisicao.h"
#define TAMANHO_NOME 40
#define TAMANHO_CODIGO_PROCEDIMENTO 10

struct Requisicao_ {
    char nome[TAMANHO_NOME];
    int inscricao;
    char procedimento[TAMANHO_CODIGO_PROCEDIMENTO];
};

Requisicao* cria_requisicao(char *nome, int inscricao, char *procedimento) {
    Requisicao* r = (Requisicao *) malloc(sizeof(Requisicao));

    if (r != NULL) {
        strncpy(r->nome, nome, TAMANHO_NOME - 1);
        r->nome[TAMANHO_NOME - 1] = '\0';


        r->inscricao = inscricao;

        strncpy(r->procedimento, procedimento, TAMANHO_CODIGO_PROCEDIMENTO - 1);
        r->procedimento[TAMANHO_CODIGO_PROCEDIMENTO - 1] = '\0';
    }
    
    return r;
}

void libera(Requisicao *r) {
    if (r != NULL) {
        free(r);
    }
}

char* get_nome(Requisicao *r) {
    return r->nome;
}

int get_inscricao(Requisicao *r) {
    return r->inscricao;
}

char* get_procedimento(Requisicao *r) {
    return r->procedimento;
}
