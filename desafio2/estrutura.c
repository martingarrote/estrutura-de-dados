#include <stdlib.h>
#include <string.h>
#include "estrutura.h"
#include "cliente.h"
#include "lista.h"

#define CRITERIO_NOME 1
#define CRITERIO_BAIRRO 2
#define CRITERIO_PESSOAS 3
#define CRITERIO_CRIANCAS 4
#define CRITERIO_RENDA 5

#define TAMANHO_HASH_NOME 100
#define TAMANHO_HASH_BAIRRO 50
#define TAMANHO_HASH_PESSOAS 5
#define TAMANHO_HASH_CRIANCAS 2
#define TAMANHO_HASH_RENDA 4

struct Estrutura_ {
    Lista *hash_nome[TAMANHO_HASH_NOME];
    Lista *hash_bairro[TAMANHO_HASH_BAIRRO];
    Lista *hash_pessoas[TAMANHO_HASH_PESSOAS];
    Lista *hash_criancas[TAMANHO_HASH_CRIANCAS];
    Lista *hash_renda[TAMANHO_HASH_RENDA];
};

unsigned int hash_string(char *str, int tamanho) {
    unsigned int hash = 0;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash % tamanho;
}

int hash_pessoas(int pessoas) {
    if (pessoas < 1) {
        return 0;
    } else if (pessoas > 5) {
        return 4;
    } else {
        return pessoas - 1;
    }
}

int hash_criancas(int criancas) {
    return (criancas > 0) ? 1 : 0;
}

int hash_renda(double renda) {
    if (renda <= 2000.0) {
        return 0;
    } else if (renda <= 3000.0) {
        return 1;
    } else if (renda <= 5000.0) {
        return 2;
    } else {
        return 3;
    }
}

Estrutura* cria_estrutura() {
    Estrutura *estrutura = (Estrutura*) malloc(sizeof(Estrutura));
    if (estrutura == NULL) {
        return NULL;
    }

    int i;
    
    for (i = 0; i < TAMANHO_HASH_NOME; i++) {
        estrutura->hash_nome[i] = NULL;
    }
    
    for (i = 0; i < TAMANHO_HASH_BAIRRO; i++) {
        estrutura->hash_bairro[i] = NULL;
    }
    
    for (i = 0; i < TAMANHO_HASH_PESSOAS; i++) {
        estrutura->hash_pessoas[i] = NULL;
    }
    
    for (i = 0; i < TAMANHO_HASH_CRIANCAS; i++) {
        estrutura->hash_criancas[i] = NULL;
    }
    
    for (i = 0; i < TAMANHO_HASH_RENDA; i++) {
        estrutura->hash_renda[i] = NULL;
    }
    
    return estrutura;
}

void libera_estrutura(Estrutura *estrutura) {
    if (estrutura != NULL) {
        int i;
        
        for (i = 0; i < TAMANHO_HASH_NOME; i++) {
            if (estrutura->hash_nome[i] != NULL) {
                libera_lista(estrutura->hash_nome[i], 0);
            }
        }
        
        for (i = 0; i < TAMANHO_HASH_BAIRRO; i++) {
            if (estrutura->hash_bairro[i] != NULL) {
                libera_lista(estrutura->hash_bairro[i], 0);
            }
        }
        
        for (i = 0; i < TAMANHO_HASH_PESSOAS; i++) {
            if (estrutura->hash_pessoas[i] != NULL) {
                libera_lista(estrutura->hash_pessoas[i], 0);
            }
        }
        
        for (i = 0; i < TAMANHO_HASH_CRIANCAS; i++) {
            if (estrutura->hash_criancas[i] != NULL) {
                libera_lista(estrutura->hash_criancas[i], 0);
            }
        }
        
        for (i = 0; i < TAMANHO_HASH_RENDA; i++) {
            if (estrutura->hash_renda[i] != NULL) {
                libera_lista(estrutura->hash_renda[i], 0);
            }
        }
        
        free(estrutura);
    }
}

int insere_cliente(Estrutura *estrutura, int criterio, Cliente *cliente) {
    if (estrutura == NULL || cliente == NULL) {
        return 0;
    }
    
    unsigned int indice;
    Lista **lista_destino = NULL;
    
    switch (criterio) {
        case CRITERIO_NOME:
            indice = hash_string(get_nome(cliente), TAMANHO_HASH_NOME);
            lista_destino = &(estrutura->hash_nome[indice]);
            break;
        
        case CRITERIO_BAIRRO:
            indice = hash_string(get_bairro(cliente), TAMANHO_HASH_BAIRRO);
            lista_destino = &(estrutura->hash_bairro[indice]);
            break;
        
        case CRITERIO_PESSOAS:
            indice = hash_pessoas(get_pessoas(cliente));
            lista_destino = &(estrutura->hash_pessoas[indice]);
            break;
        
        case CRITERIO_CRIANCAS:
            indice = hash_criancas(get_criancas(cliente));
            lista_destino = &(estrutura->hash_criancas[indice]);
            break;
        
        case CRITERIO_RENDA:
            indice = hash_renda(get_renda(cliente));
            lista_destino = &(estrutura->hash_renda[indice]);
            break;
        
        default:
            return 0;
    }
    
    if (*lista_destino == NULL) {
        *lista_destino = cria_lista();
        if (*lista_destino == NULL) {
            return 0;
        }
    }
    
    return insere_fim(*lista_destino, cliente);
}

Lista* recupera_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca) {
    if (estrutura == NULL) {
        return cria_lista();
    }
    
    Lista *resultado = cria_lista();
    if (resultado == NULL) {
        return NULL;
    }
    
    unsigned int indice;
    Lista *lista_origem = NULL;
    
    switch (criterio) {
        case CRITERIO_NOME:
            if (busca == NULL) {
                return resultado;
            }
            
            indice = hash_string(busca, TAMANHO_HASH_NOME);
            lista_origem = estrutura->hash_nome[indice];
            
            if (lista_origem != NULL) {
                Node *atual = get_inicio(lista_origem);
                
                while (atual != NULL) {
                    Cliente *cliente = (Cliente*) get_data(atual);
                    
                    if (strcmp(get_nome(cliente), busca) == 0) {
                        insere_fim(resultado, cliente);
                    }
                    
                    atual = get_next(atual);
                }
            }
            break;
        
        case CRITERIO_BAIRRO:
            if (busca == NULL) {
                return resultado;
            }
            
            indice = hash_string(busca, TAMANHO_HASH_BAIRRO);
            lista_origem = estrutura->hash_bairro[indice];
            
            if (lista_origem != NULL) {
                Node *atual = get_inicio(lista_origem);
                
                while (atual != NULL) {
                    Cliente *cliente = (Cliente*) get_data(atual);
                    
                    if (strcmp(get_bairro(cliente), busca) == 0) {
                        insere_fim(resultado, cliente);
                    }
                    
                    atual = get_next(atual);
                }
            }
            break;
        
        case CRITERIO_PESSOAS:
            if (complemento < 1 || complemento > 5) {
                return resultado;
            }
            
            indice = hash_pessoas(complemento);
            lista_origem = estrutura->hash_pessoas[indice];
            
            if (lista_origem != NULL) {
                Node *atual = get_inicio(lista_origem);
                
                while (atual != NULL) {
                    Cliente *cliente = (Cliente*) get_data(atual);
                    
                    if ((complemento < 5 && get_pessoas(cliente) == complemento) ||
                        (complemento == 5 && get_pessoas(cliente) >= 5)) {
                        insere_fim(resultado, cliente);
                    }
                    
                    atual = get_next(atual);
                }
            }
            break;
        
        case CRITERIO_CRIANCAS:
            if (complemento != 0 && complemento != 1) {
                return resultado;
            }
            
            indice = hash_criancas(complemento);
            lista_origem = estrutura->hash_criancas[indice];
            
            if (lista_origem != NULL) {
                Node *atual = get_inicio(lista_origem);
                
                while (atual != NULL) {
                    Cliente *cliente = (Cliente*) get_data(atual);
                    insere_fim(resultado, cliente);
                    atual = get_next(atual);
                }
            }
            break;
        
        case CRITERIO_RENDA:
            if (complemento < 1 || complemento > 4) {
                return resultado;
            }
            
            indice = complemento - 1;
            lista_origem = estrutura->hash_renda[indice];
            
            if (lista_origem != NULL) {
                Node *atual = get_inicio(lista_origem);
                
                while (atual != NULL) {
                    Cliente *cliente = (Cliente*) get_data(atual);
                    insere_fim(resultado, cliente);
                    atual = get_next(atual);
                }
            }
            break;
        
        default:
            break;
    }
    
    return resultado;
}