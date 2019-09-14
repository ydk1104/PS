#include<stdio.h>

int a[300001];
int max, left, right;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		if(a[i]==N) max=i;
	}
	int left=max-1, right=max+1;
	while(N>1){
		if(a[left]==N-1) left--;
		else if(a[right]==N-1) right++;
		else{
			printf("NO");
			return 0;
		}
		N--;
	}
	printf("YES");
}
