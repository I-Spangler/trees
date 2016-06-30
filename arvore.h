#include <stdio.h>
#include <stdlib.h>

#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef int Chave;

typedef struct Aluno{
  char* nome;
  Chave matricula;
}Aluno;
/*--------------FUNCOES DE ALOCACAO-----------------
funcao: cria uma estrutura de dados aluno com o int
 matrícula e a string nome para ser inserida na arvore
prototipo: Aluno* criaAluno(char* n, Chave mat)
entrada: os dados do aluno. nome e matricula
saida: a estrutura Aluno
--------------------------------------------------*/
Aluno* criaAluno(char* n, Chave mat);
/*--------------FUNCOES DE DESALOCACAO-----------------
funcao: void apagaAluno(Aluno *a)
prototipo: desaloca a string do nome e a estrutura aluno
entrada: aluno
saida: void
--------------------------------------------------*/
void apagaAluno(Aluno *a);
/*--------------FUNCOES DE IMPRESSÃO-----------------
funcao: imprime a matrícula e o nome do aluno no
formato pedido na especificação
prototipo: void imprimeAluno(Aluno *a, FILE* fp)
entrada: a estrutura do aluno e o arquivo de saída
saida: void
--------------------------------------------------*/
void imprimeAluno(Aluno *a, FILE* fp);

typedef Aluno Elemento;

typedef struct Arvore{
  struct Arvore* esq;
  struct Arvore* dir;
  Elemento* reg;
}Arvore;
/*--------------FUNCOES DE ALOCACÃO-----------------
funcao: cria uma arvore nova para resolver a colisão dos
slots da hash
prototipo: Arvore* criaArvore(Elemento* r)
entrada: o elemento aluno que ficará na raiz
saida:a árvore com o registro da raiz
--------------------------------------------------*/
Arvore* criaArvore(Elemento* r);
Arvore* removeDaArvore(Arvore *t, Chave x);
Arvore* achaMenor(Arvore *t);
/*--------------FUNCOES DE INSERCÃO-----------------
funcao: insere um elemento na posição apropriada na
árvore
prototipo: void insereElemento(Arvore *t, Elemento *n)
entrada: a árvore e o elemento
saida: void
--------------------------------------------------*/
void insereElemento(Arvore *t, Elemento *n);
/*--------------FUNCOES DE IMPRESSÃO-----------------
funcao:  percorre a árvore na ordem central, e chama
recursivamente a função de imprimir cada aluno
prototipo: void imprimeArvore(Arvore *t, FILE* fp)
entrada: a árvore e o arquivo de saída
saida: void
--------------------------------------------------*/
void imprimeArvore(Arvore *t, FILE* fp);
/*--------------FUNCOES DE DESALOCACAO-----------------
funcao: apaga a estrutura da árvore, desalocando um nó
de cada vez na ordem central, a mesma da impressão
prototipo: void apagaArvore(Arvore *t)
entrada: a árvore
saida: void
--------------------------------------------------*/
void apagaArvore(Arvore *t);
Elemento* pesquisa(Arvore *t, Chave c);

#endif // ARVORE_H_INCLUDED
