#include <string.h>
#include <stdlib.h>
#include "cliente.h"

#define TAMANHO_NOME 41
#define TAMANHO_BAIRRO 41

struct Cliente_ {
    char nome[TAMANHO_NOME];
    char bairro[TAMANHO_BAIRRO];
    int pessoas;
    int criancas;
    double renda;
};

Cliente* cria_cliente(char *nome, char *bairro, int pessoas, int criancas, double renda) {
    Cliente* c = (Cliente *) malloc(sizeof(Cliente));

    if (c != NULL) {
        int tamanho = strlen(nome);

        if (tamanho > TAMANHO_NOME - 1) {
            tamanho = TAMANHO_NOME - 1;
        }

        strncpy(c->nome, nome, tamanho);
        c->nome[TAMANHO_NOME - 1] = '\0';


        tamanho = strlen(bairro);

        if (tamanho > TAMANHO_BAIRRO - 1) {
            tamanho = TAMANHO_BAIRRO - 1;
        }
        
        strncpy(c->bairro, bairro, tamanho);
        c->bairro[TAMANHO_BAIRRO - 1] = '\0';

        c->pessoas = pessoas;
        c->criancas = criancas;
        c->renda = renda;
    }

    return c;
}

void libera_cliente(Cliente *cliente) {
    if (cliente != NULL) {
        free(cliente);
    }
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

int get_criancas(Cliente *cliente) {
    return cliente->criancas;
}

double get_renda(Cliente *cliente) {
    return cliente->renda;
}