#include <stdio.h>

void hanoi(int n, char from, char tmp, char to){
	if (n == 1)
		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
	else {
		hanoi(n-1, from, to, tmp);
		printf("원판 %d을 %c에서 %c로 옮긴다.\n\n", n, from, to);
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