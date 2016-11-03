#include <stdio.h>

int factorial(int n){
	if (n<=1) return(1);
	else return (n*factorial(n-1));
}

void main(){
	int n;

	while(1){
		printf("Input number >>> ");
		scanf("%d", &n);
		if (n == -1){
			break;
		} else {
			printf("Factorial >>> %d\n\n", factorial(n));
		}
	}
}