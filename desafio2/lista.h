#include "node.h"

typedef struct Lista_ Lista;
Lista* cria_lista();
void libera_lista(Lista *lista, int libera_dados);
int insere_inicio(Lista *lista, void *data);
int insere_fim(Lista *lista, void *data);
Node* get_inicio(Lista *lista);
Node* get_fim(Lista *lista);
int get_quantidade(Lista *lista);
int esta_vazia(Lista *lista);