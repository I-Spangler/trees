#include"sbb.h"

#define vertical 1
#define horizontal 0
#define TRUE 1
#define FALSE 0

ArvoreSBB* criaArvoreSBB(Elemento* r){
  ArvoreSBB *nova = (ArvoreSBB*)malloc(sizeof(ArvoreSBB));
  nova->dir = NULL;
  nova->esq = NULL;
  nova->reg = r;
  nova->esqtipo = vertical;
  nova->dirtipo = vertical;
  return nova;
}
//Elemento* pesquisaSBB(ArvoreSBB* a, Chave v);
void inicializaSBB(ArvoreSBB** raiz){
  raiz = NULL;
}
void imprimeSBB(ArvoreSBB* t, FILE* fp){
  if (t == NULL) {
    return;
  }
  if(t->esq != NULL){
    imprimeSBB(t->esq, fp);
  }
  imprimeAluno(t->reg, fp);
  if(t->dir != NULL){
    imprimeSBB(t->dir, fp);
  }
}
void apagaSBB(ArvoreSBB* t){
  if(!(t)) return;
  if(t->esq != NULL){
    apagaSBB(t->esq);
  }
  if(t->dir != NULL){
    apagaSBB(t->dir);
  }
  apagaAluno(t->reg);
  free(t);
}
void insereSBB(ArvoreSBB** t, Elemento* n){
  int fim = FALSE;
  int inclinacao = vertical;
  insereaux1(t, n, &inclinacao, &fim);
}
void insereaux1(ArvoreSBB** ptr, Elemento* n, int *incli, int *fim){
  if(!(*ptr)){
    insereaux2(ptr, n, incli, fim);
  }
  else if(n->matricula < (*ptr)->reg->matricula){
    insereaux1(&(*ptr)->esq, n, &(*ptr)->esqtipo, fim);
    if(*fim == TRUE)
      return;
    if((*ptr)->esqtipo == vertical){
      *fim = TRUE;
    }
    else if((*ptr)->esq->esqtipo == horizontal){
      ee(ptr);
      *incli = horizontal;
    }
    else if((*ptr)->esq->dirtipo == horizontal){
      ed(ptr);
      *incli = horizontal;
    }
  }
  else if(n->matricula > (*ptr)->reg->matricula){
    insereaux1(&(*ptr)->dir, n, &(*ptr)->dirtipo, fim);
    if(*fim == TRUE) return;
    if((*ptr)->dirtipo == vertical){
      *fim = TRUE;
    }
    else if((*ptr)->dir->dirtipo == horizontal){
      dd(ptr);
      incli = horizontal;
    }
    else if((*ptr)->dir->esqtipo == horizontal){
      de(ptr);
      incli = horizontal;
    }
  }
}
void insereaux2(ArvoreSBB** ptr, Elemento* n, int *incli, int *fim){
  ArvoreSBB *nova = (ArvoreSBB*)calloc(1, sizeof(ArvoreSBB));
  nova->dir = NULL;
  nova->esq = NULL;
  nova->reg = n;
  nova->esqtipo = vertical;
  nova->dirtipo = vertical;
  *ptr = nova;
  *incli = horizontal;
  *fim = FALSE;
}
void ee(ArvoreSBB** ptr){
  ArvoreSBB* nova = *ptr;
  ArvoreSBB* esq = nova->esq;
  nova->esq = esq->dir;
  esq->dir = nova;
  esq->esqtipo = vertical;
  nova->esqtipo = vertical;
  *ptr = esq;
}
void ed(ArvoreSBB** ptr){
  ArvoreSBB* nova = *ptr;
  ArvoreSBB* esq = nova->esq;
  ArvoreSBB* dir = esq->dir;
  esq->dir = dir->esq;
  dir->esq = esq;
  nova->esq = dir->dir;
  dir->dir = nova;
  esq->dirtipo = vertical;
  nova->esqtipo = vertical;
  *ptr = dir;
}
void de(ArvoreSBB** ptr){
  ArvoreSBB* nova = *ptr;
  ArvoreSBB* dir = nova->dir;
  ArvoreSBB* esq = dir->esq;
  dir->esq = esq->dir;
  esq->dir = dir;
  nova->dir = esq->esq;
  esq->esq = nova;
  dir->esqtipo = vertical;
  nova->dirtipo = vertical;
  *ptr = esq;
}
void dd(ArvoreSBB** ptr){
    ArvoreSBB* nova = *ptr;
    ArvoreSBB* dir = nova->dir;
    nova->dir = dir->esq;
    dir->esq = nova;
    dir->dirtipo = vertical;
    nova->dirtipo = vertical;
    *ptr = dir;
  }
