#ifndef FILA_H
#define FILA_H

//Dados
typedef struct {
  int ini, fim, N, tamanho;
  int *dados;
} Fila;

#define MAX 100
 
//Funções
Fila* fila_criar();

void fila_destruir(Fila **F);

void fila_adicionar(Fila **F, int x);

int fila_topo(Fila *F);

void fila_remover(Fila **F);

int fila_tamanho(Fila *F);


#endif