#include "arvore.h"
#include "sbb.h"

typedef struct Hash{
  Arvore** hash;
  ArvoreSBB** hashSBB;
  int tam;
  int nElem;
}Hash;

/*------------------FUNCAO HASH---------------------
funcao: cria a hash, lê todos os dados do arquivo em
loop e chama as funções para inserir todos os
elementos na tabela hash
prototipo: Hash* funcaoHash(int size, int type, FILE* fp)
entrada: o tamanho da tabela, o tipo de árvore e o
arquivo com os dados
saida: a tabela hash pronta
--------------------------------------------------*/
Hash* funcaoHash();
Hash* criaHash();
/*--------------FUNCOES DE ALOCACÃO-----------------
funcao: cria uma tabela hash vazia, alocando o espaço
necessário para o vetor e todas as suas árvores
prototipo: Hash* criaHash(int t, int type)
entrada: o tamanho e o tipo da árvore
saida: uma tabela hash vazia do tamanho apropriado
--------------------------------------------------*/
Hash* criaHash(int t, int type);
/*--------------FUNCOES DE DESALOCACAO-----------------
funcao: chama a função de apagar as árvores uma por uma
e depois apaga a estrutura hash
prototipo: void apagaHash(Hash* h)
entrada: a tabela h
saida: void
--------------------------------------------------*/
void apagaHash(Hash* h, int type);
/*--------------FUNCOES DE INSERCÃO-----------------
funcao: insere um elemento na tabela, se já existir um
elemento na posição atual da tabela, chama a função
de inserir na árvore. se não existe, cria uma nova árvore.
prototipo: void insereNaHash(Hash* h, Elemento* x)
entrada: a tabela hash e o elemento
saida: void
--------------------------------------------------*/
void insereNaHash(Hash* h, Elemento* x, int type);
/*--------------FUNCOES DE IMPRESSÃO-----------------
funcao: imprime no arquivo de saída o número da árvore
atual, e chama a função de imprimir todos os elementos
da árvore. repete em loop até que não haja mais posições
na tabela.
prototipo: void imprime(Hash* h, FILE* fp)
entrada: uma tabela hash h e o arquivo de saída
saida: void
--------------------------------------------------*/
void imprime(Hash* h, FILE* fp, int type);
Elemento* obtemDaHash(Hash* h, Chave c);
int obtemNumElem(Hash* h);
