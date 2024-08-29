#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"

int main(void) {
  int op, posicao;
  op=0;
  struct nodo *novoNodo;
	struct desc_LSE *novaLista;
  
  while(1){
	 printf("\n");
    setbuf(stdin,NULL);
  printf("1.Cria Lista\n2.Insere\n3.Remove\n4.Consulta\n5.Imprime\n6.Sair\nEscolha uma opcao:");
    setbuf(stdin,NULL);
  scanf("%i", &op);
  setbuf(stdin,NULL);
    
  switch(op){
    case 1:
    novaLista=criaDescritor();
      
    break;
    case 2:
      novoNodo=crianodo();
      insere(novaLista,novoNodo);
    
    break;
    case 3:
    printf("digite a posicao da remocao\n");
	setbuf(stdin,NULL);
	scanf("%d",&posicao);
    removelista(novaLista, posicao);
    break;

    case 4:
    imprime(novaLista);
    pesquisa(novaLista);
    break;

    case 5:
    imprime(novaLista);

    break;

    case 6:
    return 0;
    break;
    
    default:
    printf("Opção Inválida!");
  }}
  return 0;
}
