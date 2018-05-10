#include<stdio.h>
#include<stdlib.h>

//Caracterização de um JOB
typedef struct registro{
  int duracao;
  int deadline;
  struct registro *prox;
}registro;

typedef struct listaJobs{
  int quantidade;
  registro *inicio;
}

//Declaração de funções
void sortJobs(registro *reg);
void minimizeLateness(listaJobs *reg);
void imprimeJobs(registro *reg);
void alocaJob(registro *reg);
int menu();

int main(){
  int lateness, opcao;
  registro *jobs;

  opcao = menu();

  switch (opcao) {
    case 1:
      sortJobs(jobs);
      minimizeLateness(jobs);
      printf("\nEventos estão sendo escalados\n");
    break;
    case 2:
      printf("\nInserção de Elemento\n");
    break;
    case 3:
      printf("\n ------------- Lista de Jobs -------------\n\n");
      imprimeJobs(jobs);
    break;
    case 0:
    break;
    default:
      printf("\nOpcao nao encontrada!!!!\n");
  }

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

//FUNÇÕES

void sortJobs(registro *reg){
  //Ordenar Jobs por deadline (Crescente)
}

void minimizeLateness(listaJobs *reg){
  //Escalar Jobs
  int tempoInicial = 0;
  registro *atual = reg->inicio;

  /*for(int j = 0; j<= reg->quantidade; j++){
    alocaJob(atual, tempoInicial , tempoInicial + atual->duracao);
    atual->duracao = tempoInicial;
    tempoFinal = tempoInicial + duracao;
    tempoInicial = tempoInicial + duracao;
  }
  */  
}

void imprimeJobs(registro *reg){
  //Imprime lista de Jobs
}
