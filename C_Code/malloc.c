#include <stdio.h>

typedef struct Example{
	int number;
	char name[10];
}exam;

void main(){
	exam *p;
	p=(exam*)malloc(sizeof(exam));
	if (p==NULL){
		printf(stderr,"can`t alloc atc memory\n");
		exir(1);
	}
	p->number=1;
	strcpy(p->name,"Park");
	(p+1)->number=2;
	strcpy((p+1)->name,"Kim");
	free(p);
}