#include<stdio.h>

int v[200020];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x]++;
		v[y]++;
	}
	int ans=1;
	for(int i=0; i<N; i++){
		if(v[i] == 1) ans++;
	}
	printf("%d",ans/2);
}
