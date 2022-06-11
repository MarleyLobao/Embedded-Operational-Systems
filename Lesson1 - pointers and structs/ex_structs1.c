#include <stdio.h>

typedef struct{
	unsigned short int age;
	char name[51];
	float weight;
}people;

void main(void){
	people someone = {26, "Name", 70.5};

	someone.age = 27;

	//using each variable from the struct
	printf("Age:    %d\n", someone.age);
	printf("Name:   %s\n", someone.name);
	printf("Weight: %f\n", someone.weight);
}
