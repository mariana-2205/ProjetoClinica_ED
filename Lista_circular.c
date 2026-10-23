#include "Lista_circular.h"
#include <stdlib.h>
#include <stdio.h>

No_m* criar_lista() {
  return NULL; 
} 

void destruir_lista(No_m **p) {//versão iterativa
  if(*p == NULL) return;// lista vazia
  No_m *q = (*p)->prox, *aux;
  while(q != *p){
    aux = q;
    q = q->prox;
    free(aux);
  }
  free(*p);
  *p = NULL;
}

//Inserção

void adicionar_inicio(No_m** p, int x){//p recebe &L
  No_m *q = (No_m*) malloc(sizeof(No_m));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q;
  }
  else{
    q->prox = (*p)->prox;
    (*p)->prox = q;
  }
}

void adicionar_final(No_m **p, int x) {// p recebe L
  No_m *q = (No_m*) malloc(sizeof(No_m));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q;
  }
  else{
    q->prox = (*p)->prox;
    (*p)->prox = q;
    *p = q;
  }
}

//Imprimir

void imprimir_lista(No_m *p) { // p recebe L
  No_m* q, *aux = p;
  if(p!=NULL){
    for (q = p->prox; q != aux; q = q->prox) printf("%d -> ", q->dado);
    printf("%d -> ", q->dado);
  }
  printf("NULL\n");
}

//Buscar
int buscar_valor(No_m *p, int x) {// q recebe L
  if(p==NULL) return -1; //lista vazia
  No_m *q = p;
  p = p->prox;
  while(p != q){
    if(p->dado == x) return 1; //true!
      p = p->prox;
  }
  if(p->dado == x) return 1; //true!
  return 0;//false == não encontrou
}

//Remoção

void remover_inicio(No_m **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  No_m* q = *p; 
  if(q->prox==q){//1 único nó
    free(q); *p = NULL;
    return;
  }    
  q = q->prox;  
  (*p)->prox = q->prox;
  free(q);
}
  
void remover_final(No_m **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  No_m* q = *p; 
  if(q->prox==q){//1 único nó
    free(q); *p = NULL;
    return;
  }    
  No_m *aux = q;
  while(q->prox != aux) q = q->prox;  
  q->prox = aux->prox;
  *p = q;
  free(aux);
}

void remover_valor(No_m **p, int x) {// p recebe &L
  if(*p==NULL) return; //lista vazia
  No_m *q = *p;
  if(q->prox == q && q->dado == x){//1 único nó
    free(q); *p = NULL;
    return;
  }
  while(q->prox != *p && (q->prox)->dado != x) q = q->prox;
  if((q->prox)->dado == x){//encontrou
    No_m *aux = q->prox;
    q->prox = aux->prox;
    if(*p == aux)//último elemento
      *p = q;
    free(aux);
  }
}

int tamanho_lista(No_m *p){
  if(p==NULL) return 0; //lista vazia
  No_m *q = p; 
  int tam=1;
  for(p = p->prox; p != q; p = p->prox) tam++;
return tam;
}

int acessar_primeiro(No_m *p){
  if(p==NULL) return -1; //lista vazia
  No_m *q = p->prox; 
return q->dado;
}

void avancar_plantonista(No_m **p) {
    if (*p != NULL) {
        *p = (*p)->prox; // Avanca o ponteiro da lista circular
    }
}