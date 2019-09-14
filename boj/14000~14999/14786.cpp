#include<stdio.h>
#include<math.h>

double A, B, C;

int AxBsinxC(long double x){
	long double ans = A*x + B*sin(x) - C;
	if(ans>0) return 1;
	if(ans<0) return -1;
	return 0;
}

int main(void){
	scanf("%Lf %Lf %Lf", &A, &B, &C);
	double left=0, right=200000, mid;
	int now=1;
	do{
		mid = (left+right)/2;
		if(right<left) break;
		now = AxBsinxC(mid);
		if(!now) break;
		if(now==-1) left=mid+0.00000000001;
		else right=mid-0.00000000001;
	}while(now);
	printf("%.9lf", mid);
}
