#include "Lista_enc_simples.h"
#include <stdio.h>
#include <stdlib.h>

No_p* criar_lista_simples() {
    return NULL;
}

void destruir_lista_simples(No_p **p) {
    if(*p == NULL) return;

    No_p *q = *p, *aux;

    while (q != NULL) {
        aux = q;
        q = q->prox;
        free(aux);
    }
    *p = NULL;
}

void inserir_paciente(No_p **p, int id) {
    No_p *q = (No_p*) malloc(sizeof(No_p));

    q->id = id;
    q->prox = *p;
    
    *p = q;
}

int buscar_paciente(No_p *p, int id) {
    No_p *q = p;

    while (q != NULL) {
        if (q->id == id) return 1; //achou o paciente
        q = q->prox;
    }

    return 0; // Não achou
}

void remover_paciente(No_p **p, int id) {
    if (*p == NULL) return;
    
    No_p *q = *p;
    No_p *ant = NULL;
    
    while (q != NULL && q->id != id) {
        ant = q;
        q = q->prox;
    }
    
    if (q == NULL) return;
    
    if (ant == NULL) {
        *p = q->prox;
    } else {
        ant->prox = q->prox;
    }
    free(q);
}

void listar_pacientes(No_p *p) {
    No_p *q = p;

    printf("\nLista de Pacientes Cadastrados (IDs): ");

    while (q != NULL) {
        printf("%d - ", q->id);
        q = q->prox;
    }

    printf("NULL\n"); //Final da lista
}