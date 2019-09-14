#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int ans=0;
	int a[5001];
	int check[400001] = {0,};
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		for(int j=0; j<i; j++){
			if(check[a[i]-a[j]+200000]){
				ans++;
				break;
			}
		}
		for(int j=0; j<=i; j++){
			check[a[i]+a[j]+200000]++;
		}
	}
	printf("%d",ans);
}
