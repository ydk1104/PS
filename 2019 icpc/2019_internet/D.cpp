#include<stdio.h>
#include<algorithm>

double minx=2e9, miny=2e9, maxx= -2e9, maxy = -2e9;
double x[300001], y[300001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%lf %lf", &x[i], &y[i]);
		if(minx > x[i]) minx = x[i];
		if(maxx < x[i]) maxx = x[i];
		if(miny > y[i]) miny = y[i];
		if(maxy < y[i]) maxy = y[i];
//		printf("%lf %lf\n", minx, miny);
	}
	for(int i=0; i<N; i++){
		x[i] -= (minx + maxx)/2;
		y[i] -= (miny + maxy)/2;
	}
	minx=2e9, miny=2e9, maxx= -2e9, maxy = -2e9;
	for(int i=0; i<N; i++){
		if(abs(x[i]) > abs(y[i])){
			if(miny > y[i]) miny = y[i];
			if(maxy < y[i]) maxy = y[i];
		}
		else{
			if(minx > x[i]) minx = x[i];
			if(maxx < x[i]) maxx = x[i];
		}
	}
	printf("%lf %lf %lf %lf\n", minx, miny, maxx, maxy);
	printf("%lf", std::max(maxx-minx, maxy-miny)/2);
}
/*
10
0 2
3 0
-10 0
0 23
0 -162
0 11
-235 0
-213 0
32 0
0 732
*/
