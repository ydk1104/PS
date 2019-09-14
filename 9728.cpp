#include<stdio.h>
#include<algorithm>

int a[20001];

int main(void){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++){
			scanf("%d", &a[i]);
		}
		int left=0, right=N-1, ans=0;
		while(left < right){
			if(a[left] + a[right] == M){
				ans++;
				left++;
				right--;
			}
			else if(a[left] + a[right] > M){
				right--;
			}
			else{
				left ++;
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
}
