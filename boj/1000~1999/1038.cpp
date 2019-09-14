#include<stdio.h>

int find(int N, int now, int a[]){
	int i=0;
	if(N==now) return a[];
	while(a[i]==0 && i<10){
		i++;
	}
	if(a[i]==0){
		a[i]=1;
		now++;
		return find(N,now,a[]);
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	int a[10] = {0, };
	int ans[] = find(N, 1, a);
	for (int i=0; i<10; i++){
		if(ans[i] != 0){
			printf("%d", ans[i]);
		}
	}
}
