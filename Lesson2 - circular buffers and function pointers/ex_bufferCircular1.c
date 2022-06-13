#include <stdio.h>

//tamanho do buffer circular
#define BUFFER_SIZE 10

//ponteiro de função: atributo de process
typedef int (*ptrFunc)(void);

//definição da estrutura
typedef struct {
    char ProcessName;
    int Time;
    ptrFunc func;
}process;

//funções de manuseio do processo
void addProc(process);
void removeProc(void);
void execProc(void);

//funções que representam processos, nesse caso tarefas
void func1(void);
void func2(void);
void func3(void);

//buffer circular de armazenamento de processos
process circular_buffer[BUFFER_SIZE];

//indicadores de começo e de fim do buffer circular
unsigned int start=0, end=0;

void main (void){
  //criação de processos
  process p1 = {"name1",1,func1};
  process p2 = {"name2",2,func2};
  process p3 = {"name3",3,func3};

  printf("\nInicializacao de indicadores\n");
  start = 0;  end = 0;

  printf("\nAdicionando processos\n");
  addProc(p1);
  addProc(p2);
  addProc(p3);

  printf("\nExecutando e removendo processos\n");
  execProc();
  removeProc();
  execProc();
  removeProc();
  execProc();
  removeProc();
}

void addProc(process nProcess){

  //checagem de espaço disponível
  if ( ((end+1)%BUFFER_SIZE) != start){
    //Atualização da posição atual
    circular_buffer[end] = nProcess;
    //incremento da posição
    end = (end+1)%(BUFFER_SIZE);
  }

}

void removeProc (void){

  //checagem se existe alguem pra retirar
  if ( start != end){
    //incremento da posição
    start = (start +1)%(BUFFER_SIZE);
  }

}

void execProc(void){

  //checar se existe alguem para ser executado
  if (start != end){
    //execução da função
    circular_buffer[start].func();
  }

}

void func1(void){ printf("func1();\n"); }

void func2(void){ printf("func2();\n"); }

void func3(void){ printf("func3();\n"); }