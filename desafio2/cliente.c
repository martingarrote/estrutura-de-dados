#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cliente.h"

#define TAMANHO_NOME 40
#define TAMANHO_BAIRRO 40

struct Cliente_ {
    char nome[TAMANHO_NOME];
    char bairro[TAMANHO_BAIRRO];
    int pessoas;
    bool criancas;
    double renda;
};

Cliente* cria_cliente(char *nome, char *bairro, int pessoas, bool criancas, double renda) {
    Cliente* c = (Cliente *) malloc(sizeof(Cliente));

    if (c != NULL) {
        strncpy(c->nome, nome, TAMANHO_NOME - 1);
        c->nome[TAMANHO_NOME - 1] = '\0';

        strncpy(c->bairro, bairro, TAMANHO_BAIRRO - 1);
        c->bairro[TAMANHO_BAIRRO - 1] = '\0';

        c->pessoas = pessoas;

        c->criancas = criancas;

        c->renda = renda;
    }

    return c;
}

char* get_nome(Cliente *cliente) {
    return cliente->nome;
}

char* get_bairro(Cliente *cliente) {
    return cliente->bairro;
}

int get_pessoas(Cliente *cliente) {
    return cliente->pessoas;
}

bool get_criancas(Cliente *cliente) {
    return cliente->criancas;
}

double get_renda(Cliente *cliente) {
    return cliente->renda;
}