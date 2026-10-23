#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

//Dados
typedef struct no {
  int dado; // ID do Medico
  struct no *prox;
} No_m; //"nó medico"

//Funções
No_m* criar_lista();
void destruir_lista(No_m **L);

void imprimir_lista(No_m *L);

void adicionar_inicio(No_m **L, int x);
void adicionar_final(No_m **L, int x);

void remover_inicio(No_m **L);
void remover_final(No_m **L);

void remover_valor(No_m **L, int x);

int buscar_valor(No_m *L, int x);

int tamanho_lista(No_m *L);

int acessar_primeiro(No_m *L);

void avancar_plantonista(No_m **L);

#endif