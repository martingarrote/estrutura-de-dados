typedef struct Cliente_ Cliente;
Cliente* cria_cliente(char *nome, char *bairro, int pessoas, bool criancas, double renda);
char* get_nome(Cliente *cliente);
char* get_bairro(Cliente *cliente);
int get_pessoas(Cliente *cliente);
bool get_criancas(Cliente *cliente);
double get_renda(Cliente *cliente);