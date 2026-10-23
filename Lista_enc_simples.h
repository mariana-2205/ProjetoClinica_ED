#ifndef LISTA_ENC_SIMPLES_H
#define LISTA_ENC_SIMPLES_H

// Dados
typedef struct no_p {
    int id; // ID do paciente
    struct no_p *prox;
} No_p; //"Nó paciente"

// Funções
No_p* criar_lista_simples();

void destruir_lista_simples(No_p **L);

void inserir_paciente(No_p **L, int id);

int buscar_paciente(No_p *L, int id);

void remover_paciente(No_p **L, int id);

void listar_pacientes(No_p *L);

#endif