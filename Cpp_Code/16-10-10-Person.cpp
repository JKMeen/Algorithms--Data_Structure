#include <stdio.h>

typedef struct person {
	char name[10];
	int age;
	float pay;
	struct {
		int year;
		int month;
		int day;
	};
} company;

void main(){
	int n;
	int maxage, max=0, num=0;
	printf("��� �� �Է� >> ");
	scanf("%d", &n);
	company p[50];

	for (int i = 0; i < n; i++){
		printf("%i ��° �̸�, ����, ����, ��, ��, ���� ������� �Է� >> \n", i+1);
		scanf("%s %d %f %d %d %d", &p[i].name, &p[i].age, &p[i].pay, &p[i].year, &p[i].month, &p[i].day);
		num += p[i].age;
	}
	maxage = p[0].age;

	for (int i = 0; i < n; i++){
		if (maxage <= p[i].age){
			maxage = p[i].age;
			max = i;
			printf("maxage : %d, p[i].age : %d \n", maxage, p[i].age);
		}
	}
	printf("���̰� ���� ���� ��� >> %s %d�� %.1f�� %d�� %d�� %d�� >> \n", p[max].name, p[max].age, p[max].pay, p[max].year, p[max].month, p[max].day);
	printf("���� ��� >> %d �� \n", num / n);
}