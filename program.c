#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_TRABALHOS 20
char alunos_db[] = {"alunos_db.txt"};
struct trabalhos{
    float peso;
    float notas;
    int contador;
    int ativo;
};

typedef struct aluno{
    int num_aluno;
    char nome[50];
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
void guarda_dados();
void carrega_dados();

int main() {
    carrega_dados();
    menu_principal();
    return 0;
}

void menu_principal() {

    while (1) {
        printf("-----------------------------------------------------\n");
        printf("| 1 - Criar um novo Alunos                          |\n");
        printf("| 2 - Inserir trabalhos práticos                    |\n");
        printf("| 3 - alterar info                                  |\n");
        printf("| 4 - Remover aluno                                 |\n");
        printf("| 5 - Apresentar as notas de todos os alunos        |\n");
        printf("| 6 - ver media                                     |\n");
        printf("| 7 - Ajuda                                         |\n");
        printf("| 8 - Sair                                          |\n");
        printf("-----------------------------------------------------\n");
        int opcao;
        scanf(" %d", &opcao);
        if (opcao == 8)
            break;
        escolha_menu_principal(opcao);
    }
    sair();
}


//! alinea a) criar um novo aluno 1-
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

//! alinea b) e c) 2-
void inserir_trabalhos_praticos() {
    int num_aluno;
    int num_nota;
    float nota;
    float peso;
    float trabalho_pratico[2][MAX_ALUNOS];
    int count;
    int op;
    int inserir_alterar;

    while(1) {

        count = 1;

        getchar();
        printf("Deseja Inserir ou alterar notas?");
        scanf("%d", &inserir_alterar);
        

        printf("Qual é o numero do Aluno?\n");
        scanf("%d", &num_aluno);

        while(1) {
            printf("Qual o valor da nota? 0-20\n");
            scanf("%f", &nota);
            if (nota >= 0.0 && nota <= 20.0)
                break;
        }

        while(1) {
            printf("Quanto vale a nota? 0-100\n");
            scanf("%f", &peso);
            if (peso >= 0 && peso <= 100)
                break;
        }

        switch (inserir_alterar) {
            case 1:
                for (int i = 0; i < MAX_ALUNOS; i++)  {
                    if (alunos[i].num_aluno == num_aluno) {
                        for(int f = 0; f < MAX_TRABALHOS; f++) {
                            if(alunos[i].trab_pratico[f].ativo == 0) {
                                alunos[i].trab_pratico[f].notas = nota;
                                alunos[i].trab_pratico[f].peso = peso;
                                alunos[i].trab_pratico[f].ativo = 1;
                                count += f;
                                alunos[i].trab_pratico[f].contador = count;
                                break;
                            }
                        }
                    }
                }
            break;

            case 2:
                printf("Qual o número da nota:\n");
                scanf("%d", &num_nota);
                for (int i = 0; i < MAX_ALUNOS; i++)  {
                    if (alunos[i].num_aluno == num_aluno) {
                        for(int f = 0; f < MAX_TRABALHOS; f++) {
                            if(alunos[i].trab_pratico[f].contador == num_nota) {
                                alunos[i].trab_pratico[f].notas = nota;
                                alunos[i].trab_pratico[f].peso = peso;
                                break;
                            }
                        }
                    }
                }
        
        
            default:
                printf("insira uma opção valida");
                break;
        }


        printf("\n\nDeseja adicionar mais algum aluno?\n\n Sim - 1 \n Não - 2 \n\n");
        scanf("%d", &op);

        if(op == 2)
            break;
    }
}

//! alinea d) alterar nome e trabalho pratico 3-
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
        getchar();
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

        for(int i = 0; i < MAX_ALUNOS; i++ ) {
            if(alunos[i].num_aluno == num_aluno) {
                for(int f = 0; f < MAX_TRABALHOS; f++) {
                    if(alunos[i].trab_pratico[f].contador == num) {
                        alunos[i].trab_pratico[f].peso = peso;
                    }
                }
            }
        }
    }
    
    
}

//! Remover e) alunos ou notas 4-
void remover() {
    int num_aluno;
    int num_trabalho;
    int op;

    printf("Deseja alterar alunos ou notas de alunos?  \n1- Aluno 2- Notas");
    scanf("%d", &op);

    printf("Qual o num do aluno que deseja remover?");
    scanf("%d", &num_aluno);

    if(op == 1) {
        for(int i = 0; i < MAX_ALUNOS; i++) {
            if(alunos[i].num_aluno == num_aluno) {
                alunos[i].ativo = 0;
            }
        } 
    }else if (op == 2){  
        printf("Qual o número do trabalho que seja remover?");
        scanf("%d", &num_trabalho);     
        for(int i = 0; i < MAX_ALUNOS; i++) {
            if(alunos[i].num_aluno == num_aluno) {
                for(int f = 0; f < MAX_TRABALHOS; f++) {
                    if(alunos[i].trab_pratico[f].contador == num_trabalho) {
                        alunos[i].trab_pratico[f].ativo = 0;
                    }
                }
            }
        }

    }
    
}

//! f) apresentar as notas de todos os alunos 5-
void ver_notas() {
    
    printf("\n\nCabeçalho aluno\n\n");

    for(int i = 0; i< MAX_ALUNOS; i++) {
        if(alunos[i].ativo == 1) {
            printf("Aluno: %s Número %d \n", alunos[i].nome, alunos[i].num_aluno);
            for(int f = 0; f < MAX_TRABALHOS; f++){
                if(alunos[i].trab_pratico[f].ativo == 1){
                    printf("Peso: %.0f Nota: %0.2f Número: %d \n",alunos[i].trab_pratico[f].peso, alunos[i].trab_pratico[f].notas, alunos[i].trab_pratico[f].contador);
                }
            }
            printf("\n");
        }
    }
}

//! g) ver media de todos os alunos  6-
void media_aluno() {

    float media_alunos;
    float media_total;
    float count_trabalhos = 0;

    printf("\n\n");

    for(int i = 0; i< MAX_ALUNOS; i++) {
        if(alunos[i].ativo == 1) {
            printf("Aluno: %s Número de aluno:%d \n", alunos[i].nome, alunos[i].num_aluno);
            for(int f = 0; f < MAX_TRABALHOS; f++){
                if(alunos[i].trab_pratico[f].ativo == 1){
                    media_alunos = (alunos[i].trab_pratico[f].peso/100 * alunos[i].trab_pratico[f].notas);
                    media_total += media_alunos;
                    count_trabalhos++;
                }
            }
        }
    }
    media_total = media_total/count_trabalhos;
    printf("Média de todos os alunos: %.2f \n\n ", media_total);
}

//! Alinea h) aprensetar media e notas do aluno com base do seu numero 7-
void media_num_aluno() {

    int num_aluno;
    float media_aluno;
    float contador = 0;

    printf("Qual o número do aluno?\n");
    scanf("%d", &num_aluno);


    for(int i = 0; i < MAX_ALUNOS; i++) {
        if(alunos[i].num_aluno == num_aluno) {
            printf("Nome: %s \n Número: %d \n Notas:\n", alunos[i].nome, num_aluno);
            for(int f = 0; f < MAX_TRABALHOS; f++){
                if(alunos[i].trab_pratico[f].ativo == 1){
                    printf("Peso: %.0f Nota: %0.2f Número: %d \n",alunos[i].trab_pratico[f].peso, alunos[i].trab_pratico[f].notas, alunos[i].trab_pratico[f].contador);
                    media_aluno += alunos[i].trab_pratico[f].notas * (alunos[i].trab_pratico[f].peso/100);
                    contador++;
                }
            }
        }
    }
    media_aluno = media_aluno/contador;
    printf("A Média do aluno é %.2f", media_aluno);

}

//! Alinea i) apresentar media e notas 
//* fala colocar + de 1
void media_nome_aluno() {

    char nome[50];
    float media_aluno;
    int contador;

    getchar();

    printf("Qual o nome do aluno?\n");
    fgets(nome, sizeof(nome), stdin);

    for(int i = 0; i < MAX_ALUNOS; i++) {
        if(strcasecmp(nome, alunos[i].nome) >= 0) { 
            printf("Nome: %s \n Número: %d \n Notas:\n", nome, alunos[i].num_aluno);
            for(int f = 0; f < MAX_TRABALHOS; f++){
                if(alunos[i].trab_pratico[f].ativo == 1){
                    printf("%.2f \n", alunos[i].trab_pratico[f].notas);
                    media_aluno += alunos[i].trab_pratico[f].notas * (alunos[i].trab_pratico[f].peso/100);
                    contador++;
                }
            }
        }
    }

    printf("A Média do aluno é %.2f", media_aluno);

}

//! alinea J) apresentar o pesos e medias do trabalhos praticos 
void media_trabalho() {

    float media_alunos;
    float media_total;
    float count_alunos = 0;
    float notas[MAX_TRABALHOS];
    int num_trabalho = 1;



    for(int i = 0; i< MAX_ALUNOS; i++) {
        if(alunos[i].ativo == 1) {
            count_alunos++;
            for(int f = 0; f < MAX_TRABALHOS; f++){
                if(alunos[i].trab_pratico[f].ativo == 1){
                    notas[f] = (alunos[i].trab_pratico[f].peso/100 * alunos[i].trab_pratico[f].notas);
                }
            }
        }
    }
    for (int i = 0; i < MAX_TRABALHOS; i++) {
        notas[i] = notas[i]/count_alunos;
        num_trabalho += i;
        printf("Média trabalho nº %d: %.2f \n ",num_trabalho, notas[i]);
    }
    
}

//! alinea K) apresentar a media da turma
void media_turma() {

    int num_total_alunos;
    float media_alunos;
    int contador;
    float media_total;


    for(int i = 0; i< MAX_ALUNOS; i++) {
        if(alunos[i].ativo == 1) {
            printf("Aluno: %s %d \n", alunos[i].nome, alunos[i].num_aluno);
            for(int f = 0; f < 10; f++){
                if(alunos[i].trab_pratico[f].ativo == 1){
                    media_alunos += alunos[i].trab_pratico[f].notas * (alunos[i].trab_pratico[f].peso/100);
                    contador++;
                }
            }
            media_alunos = media_alunos/contador;
            media_total += media_alunos;
            num_total_alunos++;
        }
    }

    printf("Média de todos os alunos: %.2f ", media_alunos);
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
            alterar_info();
            break;

        case 4:
            remover();
            break;
        
        case 5:
            ver_notas();
            break;

        case 6:
            media_aluno();
            break;

        case 7:
            remover();
            break;

        case 8:
            ajuda();
            break;

        default:
            error();
            break;
    }
}


void sair() {
    guarda_dados();
    printf("\n\nEste trabalho foi realizado por Leonardo Menezes Franco\n");
    printf("Muito Obrigado por utilizar\n\n");
}

void error() {
    printf("\n\n introduza um numero correto \n\n");
}

void ajuda() {
    printf("\n\n utilize o teclado para navegar dentro dos menus! \n\n");
}

void guarda_dados() {
    FILE *g;

    g = fopen(alunos_db, "w");
    if (g == NULL) {
        printf("Erro ao guardar dados.\n");
        fclose(g);
    }
    else {
        for(int i = 0; i < MAX_ALUNOS; i ++) {
            if (alunos[i].ativo == 1) {
                fprintf(g, "%s %d %d ", alunos[i].nome, alunos[i].ativo, alunos[i].num_aluno);
                for(int f = 0; f < MAX_TRABALHOS; f++) {
                    fprintf(g, "%f %f %d %d ", alunos[i].trab_pratico[f].peso, alunos[i].trab_pratico[f].notas, alunos[i].trab_pratico[f].ativo, alunos[i].trab_pratico[f].contador);
                }
            }
        }
        fclose(g);
    }
}

void carrega_dados() {
    FILE *g;

    g = fopen(alunos_db, "r");
    if (g == NULL) {
        printf("Erro ao carregar dados.\n");
        fclose(g);
    }
    else {
        char nome[50];
        int num_aluno;
        int ativo;
        float nota[MAX_TRABALHOS];
        float peso[MAX_TRABALHOS];
        int contador[MAX_TRABALHOS];
        int ativo_trab[MAX_TRABALHOS];
        int i = 0;

        while (1)
        {   //!isto é o pedaço de codigo mais nojento que alguma vez vou escrever na minha vida

            fscanf(g, "%s %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d %f %f %d %d", nome, &ativo, &num_aluno, &peso[0], &nota[0], &ativo_trab[0], &contador[0] , &peso[1], &nota[1], &ativo_trab[1], &contador[1] , &peso[2], &nota[2], &ativo_trab[2], &contador[2], &peso[3], &nota[3], &ativo_trab[3], &contador[3] , &peso[4], &nota[4], &ativo_trab[4], &contador[4] , &peso[5], &nota[5], &ativo_trab[5], &contador[5], &peso[6], &nota[6], &ativo_trab[6], &contador[6] , &peso[7], &nota[7], &ativo_trab[7], &contador[7] , &peso[8], &nota[8], &ativo_trab[8], &contador[8], &peso[9], &nota[9], &ativo_trab[9], &contador[9] , &peso[10], &nota[10], &ativo_trab[10], &contador[10] , &peso[11], &nota[11], &ativo_trab[11], &contador[11], &peso[12], &nota[12], &ativo_trab[12], &contador[12] , &peso[13], &nota[13], &ativo_trab[13], &contador[13] , &peso[14], &nota[14], &ativo_trab[14], &contador[14], &peso[15], &nota[15], &ativo_trab[15], &contador[15] , &peso[16], &nota[16], &ativo_trab[16], &contador[16] , &peso[16], &nota[17], &ativo_trab[17], &contador[17], &peso[18], &nota[18], &ativo_trab[18], &contador[18] , &peso[19], &nota[19], &ativo_trab[19], &contador[19]);
            if (feof(g))
                break;

            
                strcpy(alunos[i].nome, nome);
                alunos[i].ativo = ativo;
                alunos[i].num_aluno = num_aluno;
                for(int f = 0; f < MAX_TRABALHOS; f++) {
                    alunos[i].trab_pratico[f].peso = peso[f];
                    alunos[i].trab_pratico[f].notas = nota[f];
                    alunos[i].trab_pratico[f].ativo = ativo_trab[f];
                    alunos[i].trab_pratico[f].contador = contador[f];
                }
            
            i++;
            
        }
        fclose(g);
    }
}


