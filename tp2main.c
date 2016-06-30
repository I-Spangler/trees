#include "hash.h"
#include <string.h>

int main(int argc, char *argv[]){
  FILE *fp, *list;
  Hash* h = NULL;
  list = fopen(argv[1], "r");
  fp = fopen(argv[2], "w");
  int x = atoi(argv[3]);
  if(strcmp(argv[4],"0") == 0){
    h = funcaoHash(x, 0, list);
    imprime(h, fp, 0);
    apagaHash(h, 0);
  }
  else if(strcmp(argv[4],"1") == 0){
    h = funcaoHash(x, 1, list);
    imprime(h, fp, 1);
    apagaHash(h, 1);
  }
  fclose(fp);
  fclose(list);
  return 0;
}
