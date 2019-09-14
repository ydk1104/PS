#include<stdio.h>
#include<algorithm>

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		printf("Class %d\n", t);
		int N;
		scanf("%d", &N);
		int a[51];
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		std::sort(a,a+N);
		int gap=0;
		for(int i=0; i<N-1; i++){
			if(gap<a[i+1]-a[i]) gap=a[i+1]-a[i];
		}
		printf("Max %d, Min %d, Largest gap %d\n", a[N-1], a[0], gap);
	}
}
