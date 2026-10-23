#include <stdio.h>
#include <stdlib.h>
#include "Lista_enc_simples.h"
#include "Lista_circular.h"
#include "Fila.h"
#include "Pilha.h"

int main() {
    No_p *pacientes = criar_lista_simples(); // Lista encadeada simples
    No_m *medicos = criar_lista(); // Lista circular
    Fila *espera = fila_criar(); // Fila
    Pilha *historico = pilha_criar(); // Pilha

    int opcao, id;

    do {
        printf("\n==================================\n");
        printf("       CLÍNICA VIDA SAUDÁVEL\n");
        printf("==================================\n");
        printf("1. Cadastrar Paciente (ID)\n");
        printf("2. Listar Pacientes Cadastrados\n");
        printf("3. Adicionar Médico a Escala (ID)\n");
        printf("4. Ver Escala de Médicos\n");
        printf("5. Colocar Paciente na Fila de Espera\n");
        printf("6. Atender Paciente (Realizar Consulta)\n");
        printf("7. Desfazer Último Atendimento\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o ID do paciente: ");
                scanf("%d", &id);
                inserir_paciente(&pacientes, id);
                printf("\nPaciente %d cadastrado!\n", id);
                break;

            case 2:
                listar_pacientes(pacientes);
                break;

            case 3:
                printf("Digite o ID do médico: ");
                scanf("%d", &id);
                adicionar_final(&medicos, id);
                printf("\nMédico %d adicionado na escala!\n", id);
                break;

            case 4:
                printf("\nEscala de Médicos: ");
                imprimir_lista(medicos);
                break;

            case 5:
                printf("Digite o ID do paciente para entrar na fila: ");
                scanf("%d", &id);
                if (buscar_paciente(pacientes, id)) {
                    fila_adicionar(&espera, id);
                    printf("\nPaciente %d entrou na fila de espera.\n", id);
                } else {
                    printf("\nErro: Paciente não cadastrado!\n");
                }
                break;

            case 6:
                if (fila_tamanho(espera) == 0) {
                    printf("\nFila de espera vazia!\n");
                } else if (medicos == NULL) {
                    printf("\nNenhum médico de plantão!\n");
                } else {
                    int id_paciente = fila_topo(espera);
                    fila_remover(&espera);

                    int id_medico = acessar_primeiro(medicos);

                    // Coloca no histórico (Pilha)
                    pilha_adicionar(&historico, id_paciente);

                    printf("\nPaciente ID %d foi atendido pelo médico %d\n", id_paciente, id_medico);

                    // Avanca o plantonista na lista circular
                    avancar_plantonista(&medicos);
                }
                break;

            case 7:
                if (pilha_tamanho(historico) == 0) {
                    printf("\nNenhum atendimento no histórico para desfazer!\n");
                } else {
                    int id_paciente = pilha_topo(historico);
                    pilha_remover(&historico);

                    // Volta o paciente para a fila
                    fila_adicionar(&espera, id_paciente);

                    printf("\nPaciente %d voltou para a fila de espera.\n", id_paciente);
                }
                break;

            case 0:
                printf("\nSaíndo...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while(opcao != 0);

    // Limpar memoria
    destruir_lista_simples(&pacientes);
    destruir_lista(&medicos);
    fila_destruir(&espera);
    pilha_destruir(&historico);

    return 0;
}