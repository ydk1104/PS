#include<stdio.h>

int main(void){
	int M, x, y, a[4]={0, 1, 0, 0};
	scanf("%d", &M);
	while(M--){
		scanf("%d %d", &x, &y);
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}
	for(int i=1; i<=3; i++){
		if(a[i]) printf("%d", i);
	}
}
