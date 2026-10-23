#ifndef PILHA_H
#define PILHA_H

#include "Lista_circular.h"

//Dados
typedef struct {
  No_m *L;
} Pilha;
 
//Funções
Pilha* pilha_criar();

void pilha_destruir(Pilha **P);

void pilha_adicionar(Pilha **P,int x);

int pilha_topo(Pilha *P);

void pilha_remover(Pilha **P);

int pilha_tamanho(Pilha *P);

#endif