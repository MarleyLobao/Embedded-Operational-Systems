#include <stdio.h>

void inc(int);
void incptr(int*);

void div(int, int, int*, int*);

void main(void){
  int x = 10, y = 3;
  int div_r = 0, rest_r = 0;

  //passagem por valor
  inc(x);
  printf("x = %d\n",x);
  //passagem por referência
  incptr(&x);
  printf("x = %d\n",x);

  //retorno de mais de um valor por função
  div(x, y, &div_r, &rest_r);
  printf("\nretorno:\n div_r = %d - rest_r = %d\n",div_r,rest_r);
} 

void inc(int a){
  a += 1;
  return;
}

void incptr(int* a){
  (*a) += 1;
  return;
}

void div(int a, int b, int* d, int* r){
  (*d) = a / b;
  (*r) = a % b;
  return;
}