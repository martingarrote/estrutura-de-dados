#include "cliente.h"
#include "lista.h"

typedef struct Estrutura_ Estrutura;
Estrutura* cria_estrutura();
void libera_estrutura(Estrutura *estrutura);
int insere_cliente(Estrutura *estrutura, int criterio, Cliente *cliente);
Lista* recupera_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca);