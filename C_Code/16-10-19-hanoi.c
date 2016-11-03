#include <stdio.h>

void hanoi(int n, char from, char tmp, char to){
	if (n == 1)
		printf("���� 1�� %c���� %c�� �ű��.\n", from, to);
	else {
		hanoi(n-1, from, to, tmp);
		printf("���� %d�� %c���� %c�� �ű��.\n\n", n, from, to);
		hanoi(n-1, tmp, from, to);
	}
}

void main(){
	int n;
	char from = 'a';
	char tmp = 'b';
	char to = 'c';

	printf("Input num >>>");
	scanf_s("%d", &n);

	hanoi(n, from, tmp, to);
}