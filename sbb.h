#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct ArvoreSBB{
  struct ArvoreSBB* esq;
  struct ArvoreSBB* dir;
  Elemento* reg;
  int esqtipo;
  int dirtipo;
}ArvoreSBB;
/*--------------FUNCOES DE ALOCAÇÃO-----------------
funcao: recebe o elemento n e cria a raiz da árvore com
ponteiros nulos para os ramos esquerdo e direito,
esqtipo e dirtipo são definidos como verticais e o elemento
n é inserido no registro
prototipo: void criaArvoreSBB(Elemento* r)
entrada: o elemento da raiz
saida: a nova árvore
--------------------------------------------------*/
ArvoreSBB* criaArvoreSBB(Elemento* r);
Elemento* pesquisaSBB(ArvoreSBB* a, Chave v);
/*--------------FUNCOES DE ALOCAÇÃO-----------------
funcao: recebe a raiz da árvore e a inicializa como NULL
prototipo: void inicializaSBB(ArvoreSBB** t)
entrada: a árvore t
saida: void
--------------------------------------------------*/
void inicializaSBB(ArvoreSBB** raiz);
/*--------------FUNCOES DE IMPRESSÃO-----------------
funcao: recebe a raiz da árvore e a percorre recursivamente
para imprimir o registro de um nó de cada vez em ordem central
prototipo: void imprimeSBB(ArvoreSBB** t)
entrada: a árvore t
saida: void
--------------------------------------------------*/
void imprimeSBB(ArvoreSBB* t, FILE* fp);
/*--------------FUNCOES DE DESALOCAÇÃO-----------------
funcao: recebe a raiz da árvore e a percorre para desalocar
um nó de cada vez e seus registros em ordem central.
prototipo: void apagaSBB(ArvoreSBB** t)
entrada: a árvore t
saida: void
--------------------------------------------------*/
void apagaSBB(ArvoreSBB* t);
/*--------------FUNCOES DE INSERÇÃO-----------------
funcao: inicia a variavel fim e define a inclinação
como vertical para ser usada nas funções auxiliares
insereaux1 e insereaux2
prototipo: void insereSBB(ArvoreSBB** t, Elemento* n)
entrada: a árvore ptr, o elemento a ser inserido
saida: void
--------------------------------------------------*/
void insereSBB(ArvoreSBB** t, Elemento* n);
/*--------------FUNCOES DE INSERÇÃO-----------------
funcao: recebe a raiz da árvore, a inclinação atual e o fim
 e a percorre para achar um lugar para o novo elemento.
também chama as funções que realizam as rotações
necessárias para manter o equilíbrio da árvore.
prototipo: void insereaux1(ArvoreSBB** ptr, Elemento* n, int *incli, int *fim)
entrada: a árvore ptr, o elemento a ser inserido n, a
inclinação, e o fim
saida: void
--------------------------------------------------*/
void insereaux1(ArvoreSBB** ptr, Elemento* n, int *incli, int *fim);
/*--------------FUNCOES DE INSERÇÃO-----------------
funcao: aloca um novo nó e insere os dados do elemento no
nó. muda os valores da inclinação e do fim.
prototipo: void insereaux2(ArvoreSBB** ptr, Elemento* n, int *incli, int *fim)
entrada: a árvore ptr, o elemento a ser inserido n, a
inclinação, e o fim
saida: void
--------------------------------------------------*/
void insereaux2(ArvoreSBB** ptr, Elemento* n, int *incli, int *fim);
/*--------------FUNCOES DE ROTAÇÃO-----------------
funcao: rotaciona a árvore para a esquerda, mudando
os nós de lugar, no caso de houver uma sequência de três ponteiros
seguidos para a direita
prototipo: void dd(ArvoreSBB* ptr)
entrada: a árvore ptr
saida: void
--------------------------------------------------*/
void ee(ArvoreSBB** ptr);
/*--------------FUNCOES DE ROTAÇÃO-----------------
funcao: rotaciona a árvore para a esquerda, mudando
os nós de lugar no caso de houver dois nós ocupando o mesmo
espaço em um nível horizontal
prototipo: void dd(ArvoreSBB* ptr)
entrada: a árvore ptr
saida: void
--------------------------------------------------*/
void ed(ArvoreSBB** ptr);
/*--------------FUNCOES DE ROTAÇÃO-----------------
funcao: rotaciona a árvore para a direita, mudando
os nós de lugar, no caso de houver uma sequência de três ponteiros
seguidos para a direita
prototipo: void dd(ArvoreSBB* ptr)
entrada: a árvore ptr
saida: void
--------------------------------------------------*/
void dd(ArvoreSBB** ptr);
/*--------------FUNCOES DE ROTAÇÃO-----------------
funcao: rotaciona a árvore para a direita, mudando
os nós de lugar no caso de houver dois nós ocupando o mesmo
espaço em um nível horizontal
prototipo: void dd(ArvoreSBB* ptr)
entrada: a árvore ptr
saida: void
--------------------------------------------------*/
void de(ArvoreSBB** ptr);
