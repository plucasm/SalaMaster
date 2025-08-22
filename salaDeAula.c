#include <stdio.h>
#include <math.h>
#define MAX 50
#define TRUE 1
#define FALSE 0

int main() {
    int totalSalas = 0;
    int sala;
    int escolha = 10;
    int salaDeAula[MAX];
    int capacidade[MAX];
    int totalAlunos[MAX];
    int disponivel[MAX];
    int novaCapacidade;
    int alunos;

    //inicializa todas salas disponiveis
    for(int i=0; i< MAX; i++) {
        disponivel[i] = TRUE;
        salaDeAula[i] = 0;
        capacidade[i] = 0;
        totalAlunos[i] = 0;
    }

    while(escolha != 0) {
        printf("                MENU      \n-----------------------------------\n1. Adicionar sala de aula\n2. Adicionar capacidade\n3. Adicionar número de alunos matriculados\n4. Consultar capacidade de uma sala específica\n5. Consultar alunos matriculados em uma sala específica\n6. Consultar todos detalhes de uma sala\n0. SAIR\n----------------------------------\nOpção: ");
        scanf("%d", &escolha);

        if(escolha == 1) {
            printf("Número da sala: ");
            scanf("%d", &sala);

            int salaExiste = FALSE;
            for(int i =0; i<= MAX; i++){
                if(sala == salaDeAula[i]) {
                    salaExiste = TRUE;
                    break;
                } 
            }

            if(salaExiste) {
                printf("Essa sala já está cadastrada\n");
            } else {
                if(totalSalas < MAX) {
                    salaDeAula[totalSalas] = sala;
                    disponivel[totalSalas] = FALSE;
                    totalSalas++;
                }
            }
        }

        if(escolha == 2){
            printf("Deseja adicionar capacidade para qual sala?");
            scanf("%d", &sala);

            int salaEncontrada = FALSE;

            for(int i = 0; i< totalSalas; i++) {
                if(salaDeAula[i] == sala){
                    salaEncontrada = TRUE;

                    if(capacidade[i] > 0) {
                        printf("Capacidade já definida para esta sala: %d\n", capacidade[i]);
                    } else {
                        printf("Capacidade da sala: ");
                        scanf("%d", &novaCapacidade); 
                        capacidade[i] = novaCapacidade; 
                        printf("Capacidade da sala %d definida para %d\n", sala, capacidade[i]);
                    }
                    break;
                }
            }

            if(!salaEncontrada) {
                printf("Sala não encontrada!\n");
            }
        }
        
        if(escolha == 3) {
            printf("Sala que deseja adicionar alunos: ");
            scanf("%d", &sala);

            int salaEncontrada = FALSE;

            for(int i=0; i < totalSalas; i++) {
                if(salaDeAula[i] == sala) {
                    salaEncontrada = TRUE;
                    printf("Quantidade de alunos para a sala: ");
                    scanf("%d", &alunos);

                    if(alunos > capacidade[i]) {
                        printf("Quantidade excede a capacidade da sala!\n");
                    } else if (capacidade[i] == 0) {
                        printf("Não foi determinada uma capacidade para a sala %d, volte e adicione uma capacidade antes de adicionar alunos matriculados\n", sala);
                        break;
                    } else {
                        totalAlunos[i] = alunos;

                        int disponibilidade;

                        disponibilidade = capacidade[i] - alunos;
                        printf("Disponibilidade da sala: %d\n", disponibilidade);
                    } 
                }
            }

            if(!salaEncontrada) {
                printf("Essa sala não está cadastrada!\n");
            }
        }
    
        if(escolha ==4) {
            printf("Qual sala deseja consultar: ");
            scanf("%d", &sala);

            int salaExiste = FALSE;
            for(int i = 0; i < totalSalas; i++) {
                if(salaDeAula[i] == sala) {
                    salaExiste = TRUE;

                    if(capacidade[i] == 0){
                        printf("Capacidade da sala %d ainda não foi definida!\n", sala);
                    } else {
                        printf("Capacidade da sala %d = %d\n", sala, capacidade[i]);
                    }
                }
            }

            if(!salaExiste) {
                printf("Sala não existe!\n");
            }
        }
    
        if(escolha == 5) {
            printf("Qual sala deseja consultar: ");
            scanf("%d", &sala);

            int salaExiste = FALSE;
            for(int i = 0; i < totalSalas; i++) {
                if(salaDeAula[i] == sala) {
                    salaExiste = TRUE;

                    if(totalAlunos[i] == 0) {
                        printf("Nenhum aluno matriculado!\n");
                    } else {
                        printf("Total de alunos matriculados na sala %d = %d\n", sala, totalAlunos[i]);
                    }
                }
            }

            if(!salaExiste) {
                printf("Sala não está cadastrada!\n");
            }
        }
    
        if(escolha == 6) {
            printf("Qual sala deseja consultar: ");
            scanf("%d", &sala);

            int salaExiste = FALSE;
            for(int i = 0; i < totalSalas; i++) {
                if(salaDeAula[i] == sala) {
                    salaExiste = TRUE;

                    printf("Sala nº: %d\nCapacidade: %d\nAlunos matriculados: %d\n", salaDeAula[i], capacidade[i], totalAlunos[i]);
                }
            }    

            if(!salaExiste) {
                printf("Sala não está cadastrada!\n");
            }
        }
    }
}

