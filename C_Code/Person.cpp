#include <stdio.h>

typedef struct person{
		char name[10];
		int age;
		float height;
}Person;

void main(){
	int num, max, arange=0;

	Person a[50];

	printf("Input Person num >>");
	scanf("%d", &num);

	for(int i=0; i<num; i++){
		printf("%d��° �̸�, ����, Ű ������� �Է� >>>", i+1);
		scanf("%s %d %f", &a[i].name, &a[i].age, &a[i].height);
		arange+=a[i].age;
	}
	max = a[0].age;
	for(int i=0; i<num; i++){
		if (max <= a[i].age)
			max = a[i].age;
	}

	printf("Max Age >>> %d\n", max);

	printf("���� ��� >> %d ��\n", arange/num);
}