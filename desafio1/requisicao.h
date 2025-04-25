typedef struct Requisicao_ Requisicao;
Requisicao* cria_requisicao(char *nome, int inscricao, char *procedimento);
void libera(Requisicao *r);
char* get_nome(Requisicao *r);
int get_inscricao(Requisicao *r);
char* get_procedimento(Requisicao *r);