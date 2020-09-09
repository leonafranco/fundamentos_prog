#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50

typedef struct {
    int num_aluno;
    char nome[50];
    float trabalho_pratico[MAX_ALUNOS];
    int notas[4];
    int ativo;

} Aluno;

Aluno alunos [MAX_ALUNOS];

void escolha_menu_principal(int escolha);
void inserir_trabalhos_praticos();
void criar_novo_aluno();
void menu_principal();
void ajuda();
void sair();
void error();

int main() {


    //menu_principal();
    return 0;
}

void menu_principal() {

    while (1) {
        printf("-----------------------------------------------------\n");
        printf("| 1 - Criar um novo Alunos                          |\n");
        printf("| 2 - Inserir trabalhos práticos                    |\n");
        printf("| 3 - Exportar objetos para arduino                 |\n");
        printf("| 4 - Ajuda                                         |\n");
        printf("| 5 - Sair                                          |\n");
        printf("-----------------------------------------------------\n");
        int opcao;
        scanf(" %d", &opcao);
        if (opcao == 5)
            break;
        escolha_menu_principal(opcao);
    }
    sair();
}


//! alinea a) criar um novo aluno
void criar_novo_aluno() {
    int num_aluno;
    char nome[50];
    int op;

    while(1) {

        getchar();

        printf("Qual é o nome do Aluno?\n");
        fgets(nome, sizeof(nome), stdin);
        
        printf("Qual o número do Aluno?\n");
        scanf("%d", &num_aluno);

                for (int i = 0; i < MAX_ALUNOS; i++)  {
            if (alunos[i].ativo == 0) {
                alunos[i].num_aluno = num_aluno;
                strcpy(alunos[i].nome, nome);
                break; //sair do ciclo if 
            }
        }

        printf("Deseja adicionar mais algum aluno?\n\n Sim - 1 \n Não - 2 \n\n");
        scanf("%d", &op);


        

        if(op == 2)
            break;
    }
}

void inserir_trabalhos_praticos() {
    int num_aluno;
    int num_nota;
    float nota;
    int peso;
    float trabalho_pratico[2][MAX_ALUNOS];
    int count = 1;
    int op;

    while(1) {

        getchar();
        printf("Deseja Inserir ou alterar notas?");

        printf("Qual é o numero do Aluno?\n");
        scanf("%d", &num_aluno);

        while(1) {
            printf("Qual o valor da nota? 0-20");
            scanf("%f", &nota);
            if (nota >= 0.0 && nota <= 20.0)
                break;
        }

        while(1) {
            printf("Quanto vale a nota? 0-100");
            scanf("%d", &peso);
            if (peso >= 0 && peso <= 100)
                break;
        }


        for (int i = 0; i < MAX_ALUNOS; i++)  {
            if (alunos[i].num_aluno == num_aluno) {
                for(int f = 1; f < MAX_ALUNOS; i++) {
                    if(alunos[i].trabalho_pratico[f] == 0.0) {

                    } 
                }

            }
        }

        printf("Deseja adicionar mais algum aluno?\n\n Sim - 1 \n Não - 2 \n\n");
        scanf("%d", &op);


        

        if(op == 2)
            break;
    }
}




void escolha_menu_principal(int escolha) {
    
    switch(escolha) {
        case 1:
            criar_novo_aluno();
            break;

        case 4:
            ajuda();
            break;

        default:
            error();
            break;
    }
}


void sair() {
    printf("\n\nEste trabalho foi realizado por Leonardo Menezes Franco\n");
    printf("Muito Obrigado por utilizar\n\n");
}


void error() {
    printf("\n\n introduza um numero correto \n\n");
}

void ajuda() {
    printf("\n\n utilize o teclado para navegar dentro dos menus! \n\n");
}