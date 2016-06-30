#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Aluno* criaAluno(char *n, Chave mat){
  Aluno* a = (Aluno*)malloc(sizeof(Aluno));
  a->nome = n;
  a->matricula = mat;
  return a;
}
Arvore* criaArvore(Elemento* r){
  Arvore *nova = (Arvore*)malloc(sizeof(Arvore));
  nova->dir = NULL;
  nova->esq = NULL;
  nova->reg = r;
  return nova;
}
void insereElemento(Arvore *t, Elemento *n){
  if(n->matricula < t->reg->matricula){
    if(!(t->esq)){
      Arvore* novoNo = criaArvore(n);
      t->esq = novoNo;
    }
    else insereElemento(t->esq, n);
  }
  if(n->matricula > t->reg->matricula){
    if(!(t->dir)){
      Arvore* novoNo = criaArvore(n);
      t->dir = novoNo;
    }
    else insereElemento(t->dir, n);
  }
}
void imprimeArvore(Arvore *t, FILE* fp){
  if (t == NULL) {
    return;
  }
  if(t->esq != NULL){
    imprimeArvore(t->esq, fp);
  }
  imprimeAluno(t->reg, fp);
  if(t->dir != NULL){
    imprimeArvore(t->dir, fp);
  }
}
void imprimeAluno(Aluno *a, FILE* fp){
  fprintf(fp, "(%d) %s\n", a->matricula, a->nome);
}
void apagaArvore(Arvore *t){
  if(!(t)) return;
  if(t->esq != NULL){
    apagaArvore(t->esq);
  }
  if(t->dir != NULL){
    apagaArvore(t->dir);
  }
  apagaAluno(t->reg);
  free(t);
}
void apagaAluno(Aluno *a){
  free(a->nome);
  free(a);
}
