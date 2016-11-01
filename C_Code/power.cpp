#include <stdio.h>

// 馆汗利牢 规过
double slow_power(double x, int n){
	double r=1.0;
	for(int i=0; i<n; i++)
		r *= x;
	return (r);
}

// 鉴券利牢 规过
double power(double x, int n){
	if (n==0) return 1;
	else if (n%2 == 0) return power(x*x, n/2);
	else return x*power(x*x, (n-1)/2);
}

void main(){
	double x;
	int n;
	while(1){
		printf("Input x & n >> ");
		scanf("%lf %d", &x, &n);
		if (n == -1){
			break;
		} else {
			printf("slow_power >>> %f\n",power(x, n));
		}
	}
}