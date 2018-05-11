#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#ifdef WIN32
    #define LIMPA_TELA system("cls")
#else
    #define LIMPA_TELA system("clear")
#endif

//Caracterização de um JOB
typedef struct Jobs{
  char descricaoJob[25];
  int duracao;
  int deadline;
  struct Jobs *prox;
}Jobs;

typedef struct ListaJobs{
  int quantidade;
  Jobs *inicio;
}ListaJobs;

//Declaração de funções
void recebeDescricao(char *);
int recebeValor(char *);
void insereJobs(Jobs *, char *, int, int);
void imprimeJobs(Jobs *);
void alocaJob(Jobs *);
int menu();

int main(){
  int lateness, opcao, duracao, deadline;
  Jobs *jobs;
  char descricaoJob[25];
  char stringDuracao[8] = "duracao";
  char stringDeadline[9] = "deadline";

  do{
    opcao = menu();
    switch (opcao) {
      case 1:
        printf("\nEventos estão sendo escalados\n");
      break;
      case 2:
        recebeDescricao(descricaoJob);
        duracao = recebeValor(stringDuracao);
        deadline = recebeValor(stringDeadline);
        insereJobs(jobs, descricaoJob, duracao, deadline);
        // printf("%s\n", descricaoJob);
        // printf("%d\n", duracao);
        // printf("%d\n", deadline);
        // printf("\nInserção de Elemento\n");
      break;
      case 3:
        printf("\n ------------- Lista de Jobs -------------\n\n");
        imprimeJobs(jobs);
      break;
      case 0:
        LIMPA_TELA;
        printf("Programa finalizado!\n");
        exit(0);
        break;
      default:
        printf("\nOpcao nao encontrada!!!!\n");
        break;
    }
  }while(opcao != 0);
  return 0;
}

int menu(){
  int op;
  printf("\n\n----------- MINIMIZE MAXIMUM LATENESS -----------\n\n");
  printf("1 - Escalar Eventos\n");
  printf("2 - Inserir Evento\n");
  printf("3 - Imprimir Lista de Eventos\n");
  printf("0 - SAIR\n\n");
  scanf("%d",&op);
  return op;
}

//=============== SUBPROGRAMAS ==============

void recebeDescricao(char *descricaoJob){
   LIMPA_TELA;
   printf("Digite a descricao do Job que deseja inserir: ");
   scanf("%s", descricaoJob);
}

int recebeValor(char* tipo){
  int valor;
  LIMPA_TELA;
  printf("Digite o(a) %s do Job que deseja inserir: ", tipo);
  scanf("%d", &valor);
  return valor;
}

void insereJobs(Jobs *jobs , char *descricaoJob, int duracao, int deadline){
    Jobs *atual, *novo, *anterior;
    int num;

    novo = (Jobs *) malloc(sizeof(Jobs));

    atual = jobs;
    anterior = NULL;

    memset(novo->descricaoJob, '\0', sizeof(novo->descricaoJob));
    strcpy(novo->descricaoJob, descricaoJob);
    novo->duracao = duracao;
    novo->deadline = deadline;

    if(atual == NULL){
        novo->prox = NULL;
        jobs = novo;
    } else{
        while(atual != NULL && atual->deadline < num){
            anterior = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(anterior == NULL){
            jobs = novo;
        } else{
            anterior->prox = novo;
        }
    }
}

void imprimeJobs(Jobs *reg){
  //Imprime lista de Jobs
}
