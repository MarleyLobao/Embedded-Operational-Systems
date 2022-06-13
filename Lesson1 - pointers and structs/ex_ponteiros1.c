#include <stdio.h>

void main(){
    int x=10;                           //variável inteira
    int *p1=&x;                         //ponteiro para um inteiro

    printf("x = %d\n\n", x);            //10
    *p1=20;                             //ou p1[0]=20;
    printf("p1 = 0x%X\n", p1);          //endereço para qual p1 aponta = endereço de x
    printf("x = %d\n", x);              //20
    printf("*p1 = %d\n", *p1);          //20
    printf("p1[0] = %d\n\n", p1[0]);    //20
}