#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct desc_LSE *criaDescritor() {
  struct desc_LSE *novoDescLista =
      (struct desc_LSE *)malloc(sizeof(struct desc_LSE));
  novoDescLista->tamanho = 0;
  novoDescLista->lista = NULL;
  return novoDescLista;
}
struct nodo *crianodo() {
  struct nodo *novoElemento = (struct nodo *)malloc(sizeof(struct nodo));
  novoElemento->informacao = NULL;
  novoElemento->prox = NULL;

  struct musica *novaMusica = (struct musica *)malloc(sizeof(struct musica));
  

  char musica[256], artista[256], letra[256];
  int codigo = 0;
  printf("Nome da musica:");
  setbuf(stdin, NULL);
  scanf("%s", musica);
  printf("Nome da artista:");
  setbuf(stdin, NULL);
  scanf("%s", artista);
  printf("Nome da letra:");
  setbuf(stdin, NULL);
  scanf("%s", letra);
  printf("digite codigo:");
  setbuf(stdin, NULL);
  scanf("%i", &codigo);
  ////////inserir dados no novo
  strcpy(novaMusica->titulo, musica);
  strcpy(novaMusica->artista, artista);
  strcpy(novaMusica->letra, letra);
  novaMusica->codigo = codigo;
  novoElemento->prox = NULL;
  novoElemento->informacao = novaMusica;

  return novoElemento;
}
///////////////////
void insere(struct desc_LSE *minhaLista, struct nodo *novoElemento) {
  int posicao = 0;
  setbuf(stdin,NULL);
  printf("insira a posicao:");
	scanf("%i", &posicao);

  if ((minhaLista->lista== NULL) ||
      (posicao == 0)) { // insercao no inicio da lista
    novoElemento->prox = minhaLista->lista;
    minhaLista->lista=novoElemento;
    minhaLista->tamanho++;
    return;
  } else {
    struct nodo *aux = minhaLista->lista;
    int listaPos = 0;
    if (minhaLista->tamanho < posicao) {
      while (aux->prox != NULL) {
        aux = aux->prox;
      }
      aux->prox=novoElemento;
      minhaLista->tamanho++;
      return;
    } else { // posicao valida na lista insere na posicao
      struct nodo *anterior;
      while (aux!= NULL) {
        anterior = aux;
        aux = aux->prox;
        listaPos++;
        if (listaPos == posicao) {
          novoElemento->prox = aux;
          anterior->prox = novoElemento;
          minhaLista->tamanho++;
          return;
        }}}}}

struct nodo *removelista(struct desc_LSE *minhaLista, int posicao){
	printf("tamanho %i", minhaLista->tamanho);
  if((minhaLista->tamanho==0) || (posicao > minhaLista->tamanho)){
    printf("A posicao não é valida");
    printf ("\n");
  }
  else{
    if(posicao==0){
      struct nodo *aux = minhaLista->lista;////cria um auxiliar 
			minhaLista->lista = minhaLista->lista->prox;////o primeiro da lista aponta um a frente
			minhaLista->tamanho--;
			return aux; 
		}else{ //delecao no meio ou no fim da lista
			int listaPos=0;///criar um contador 
			struct nodo *anterior;///cria um anterior 
			struct nodo *aux = minhaLista->lista;
			while(aux != NULL){
				anterior = aux;
				aux = aux->prox;
				listaPos++;
				if(listaPos == posicao){
					anterior->prox = aux->prox;///o apont do anterior passa para o apont do aux ou seja pula uma casa
					minhaLista->tamanho--;
					return aux;
				}}}}return 0;}
struct nodo *pesquisa(struct desc_LSE *minhaLista){
  
  int codigo;
  printf("informe o codigo da musica:");
  setbuf(stdin, NULL);
  scanf("%i", &codigo);
  struct nodo *aux = minhaLista->lista;
  while(aux!=NULL){
  
    if(aux->informacao->codigo==codigo){
     printf("\n titulo:%s\n Artista:%s \n Letra:%s\n codigo: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo);
      return 0;
    }
    aux=aux->prox;
  }return 0;}
void imprime(struct desc_LSE *minhaLista){
  struct nodo *aux = minhaLista->lista;
  printf(" =================================LISTA======================\n" );
  while(aux!=NULL){
	  printf(" elemento --------------\n" );
     printf("\n titulo:%s\n Artista:%s \n Letra:%s\n codigo: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo);
    aux=aux->prox;
    
}
  printf(" =======================================================\n" );
}
