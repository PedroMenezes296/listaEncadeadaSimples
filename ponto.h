struct musica{
char titulo[256];
char artista[256];
char letra[256];
int codigo;
int execucoes;
};
struct nodo{
struct nodo *prox;
struct musica *informacao;
};
struct desc_LSE{
struct nodo *lista;
int tamanho;
};
struct nodo *crianodo();

struct desc_LSE *criaDescritor();

struct nodo *removelista(struct desc_LSE *minhaLista, int posicao);
struct nodo *pesquisa(struct desc_LSE *minhaLista);
void insere(struct desc_LSE *minhaLista, struct nodo *novo_elemento);
int tamanho(struct desc_LSE *minhaLista);
void imprime(struct desc_LSE *minhaLista);
