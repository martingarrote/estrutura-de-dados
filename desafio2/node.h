typedef struct Node_ Node;
Node* cria_node(void *data);
void libera_node(Node *node);
void* get_data(Node *node);
Node* get_next(Node *node);
void set_next(Node *node, Node *next);