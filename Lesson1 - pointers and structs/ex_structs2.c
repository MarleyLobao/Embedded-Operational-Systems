#include <stdio.h>

typedef struct{
   char nome[20];
   int idade;
   int *p_dado;
}t_aluno;

void main(void){
	int dado = 10;
	t_aluno aluno = {"Nome",17,&dado};
	t_aluno *a1;
	a1 = &aluno;

	(*a1).idade = 18;
	printf("Age:   %d\n", (*a1).idade);
	a1->idade = 19;
	printf("Age:   %d\n", a1->idade);

	*(aluno.p_dado) = 11;
	printf("dado:   %d\n", dado);

	//erro: aluno não é apontador do tipo t_aluno!
	//aluno->p_dado = 12;
	//printf("dado:   %d\n", dado);

	*((*a1).p_dado) = 12;
	printf("dado:   %d\n", dado);
	*(a1->p_dado) = 13;
	printf("dado:   %d\n", dado);
}
