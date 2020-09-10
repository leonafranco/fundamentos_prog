#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_TRABALHOS 20

struct trabalhos{
    int peso;
    float notas;
    int contador;
    int ativo;
};



typedef struct aluno{
    int num_aluno;
    char nome[50];
    int notas[4];
    int ativo;
    struct trabalhos trab_pratico[MAX_TRABALHOS];

} Aluno;

Aluno alunos [MAX_ALUNOS];

void escolha_menu_principal(int escolha);
void inserir_trabalhos_praticos();
void criar_novo_aluno();
void menu_principal();
void ajuda();
void sair();
void error();
void vernotas();

int main() {


    menu_principal();
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
                alunos[i].ativo = 1;
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
        printf("%f %d", nota, peso );

        for (int i = 0; i < MAX_ALUNOS; i++)  {
            if (alunos[i].num_aluno == num_aluno) {
                for(int f = 0; f < MAX_TRABALHOS; f++) {
                    if(alunos[i].trab_pratico[f].ativo == 0) {
                        alunos[i].trab_pratico[f].notas = nota;
                        alunos[i].trab_pratico[f].peso = peso;
                        alunos[i].trab_pratico[f].ativo = 1;
                        alunos[i].trab_pratico[f].contador = f++;
                        break;
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

void alterar_info() {

    int num_aluno;
    float peso;
    float num;
    char nome[50];
    int op;

    printf("Deseja altera nome ou peso da nota? \n1- nome 2- peso");
    scanf("%d", &op);

    printf("Qual o número do aluno?");
    scanf("%d", &num_aluno);

    if(op == 1) {
        printf("Qual o nome para qual deve alterar?");
        fgets(nome, sizeof(nome), stdin);
        
        for (int i = 0; i < MAX_ALUNOS; i++)  {
            if (alunos[i].num_aluno == num_aluno) {
                strcpy(alunos[i].nome, nome);
            }
        }
    }else if (op == 2) {
        printf("Qual o numero da prova que deseja alterar?");
        scanf("%f", &num);
        printf("Qual o peso que irá ter?");
        scanf("%f", &peso);

        for( int i = 0; i< MAX_ALUNOS; i++) {
            if(alunos[i].num_aluno == num_aluno) {

            }
        }
    }
    
}



//! Remover e) alunos ou notas 
void remover() {
    int num_aluno;
    int num_trabalho;

    printf("Qual o num do aluno que deseja remover?");
    scanf("%d", &num_aluno);

    for(int i = 0; i < MAX_ALUNOS; i++) {
        if(alunos[i].num_aluno == num_aluno) {
            alunos[i].ativo = 0;
        }
    } 
}

void escolha_menu_principal(int escolha) {
    
    switch(escolha) {
        case 1:
            criar_novo_aluno();
            break;

        case 2:
            inserir_trabalhos_praticos();
            break;

        case 3:
            vernotas();
            break;

        case 4:
            ajuda();
            break;

        default:
            error();
            break;
    }
}

void vernotas() {
    
    printf("Cabeçalho alunos\n\n");

    for(int i = 0; i< MAX_ALUNOS; i++) {
        if(alunos[i].ativo == 1) {
            for(int f = 0; f < 10; f++){
                if(alunos[i].trab_pratico[f].ativo == 1){
                    printf("%s %d %d %0.2f %d ",alunos[i].nome, alunos[i].num_aluno, alunos[i].trab_pratico[f].peso, alunos[i].trab_pratico[f].notas, alunos[i].trab_pratico[f].contador);
                }
            }
        }
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