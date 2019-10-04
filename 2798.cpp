#include<stdio.h>

int arr[101];

int main(void){
	int N, M, ans=0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	for(int i=0; i<N; i++){
		int sum1 = arr[i];
		for(int j=i+1; j<N; j++){
			int sum2 = sum1+arr[j];
			for(int k=j+1; k<N; k++){
				int sum3 = sum2+arr[k];
				if(sum3 > ans && sum3 <= M) ans = sum3;
			}
		}
	}
	printf("%d",ans);
}
