#include "hash.h"
Hash* funcaoHash(int size, int type, FILE* fp){
  Hash *h = NULL;
  h = criaHash(size, type);
  char *n = (char*)calloc(200, sizeof(char));
  int mat;
  Aluno* a;
  while((fscanf(fp, "%d %[^\n]s", &mat, n)) != EOF){
    a = criaAluno(n, mat);
    n = (char*)calloc(200, sizeof(char));
    insereNaHash(h, a, type);
    //break;
  }
  free(n);
  return h;
}
Hash* criaHash(int t, int type){
  int i;
  Hash *h = NULL;
  h = (Hash*)calloc(1, sizeof(Hash)*t);
  h->tam = t;

  if(type == 0){
    h->hash = (Arvore**)calloc(t, sizeof(Arvore*));
    for(i = 0; i < t; i++){
      h->hash[i] = NULL;
    }
  } else if(type == 1){
    if (h->hashSBB == NULL){
      h->hashSBB = (ArvoreSBB**)calloc(t, sizeof(ArvoreSBB*));
      for(i = 0; i < t; i++){
        inicializaSBB(&h->hashSBB[i]);
      }
    }
  }

  return h;
}

//Hash* criaHash()
void insereNaHash(Hash* h, Elemento* x, int type){
  int index = x->matricula % h->tam;
  if(type == 0){
    if(h->hash[index] == NULL){
      h->hash[index] = criaArvore(x);
    }
    else insereElemento(h->hash[index], x);
  }
  if(type == 1){
    if(h->hashSBB == NULL){
      fprintf(stderr, "h->hashSBB is null\n");
    }
    if(h->hashSBB[index] == NULL) {
      h->hashSBB[index] = criaArvoreSBB(x);
    } else insereSBB(&(h->hashSBB[index]), x);
  }
}
void imprime(Hash* h, FILE* fp, int type){
  int i;
  if(type == 0){
    for(i = 0; i<h->tam; i++){
      fprintf(fp, "%d:\n", i);
      imprimeArvore(h->hash[i], fp);
    }
  }
  if(type == 1){
    for(i = 0; i<h->tam; i++){
    fprintf(fp, "%d:\n", i);
      imprimeSBB(h->hashSBB[i], fp);
    }
  }
}
void apagaHash(Hash* h, int type){
  int i;
  if(type == 0){
    for(i=0; i<h->tam;i++){
      apagaArvore(h->hash[i]);
    }
    free(h->hash);
  }
  if(type == 1){
    for(i=0; i<h->tam;i++){
      apagaSBB(h->hashSBB[i]);
    }
    free(h->hashSBB);
  }
  free(h);
}
