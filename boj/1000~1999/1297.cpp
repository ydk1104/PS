#include<stdio.h>
#include<math.h>

int main(void){
	double cm, x, y;
	scanf("%lf %lf %lf", &cm, &x, &y);
	double p = sqrt(x*x+y*y);
	printf("%d %d", int(floor(x*cm/p)), int(floor(y*cm/p)));
}
