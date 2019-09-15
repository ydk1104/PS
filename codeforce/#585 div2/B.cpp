#include<stdio.h>

int a[200001];
int cnt[200001];
int sum[200001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		if(x>0) a[i] = 1, cnt[i]++;
		else a[i] = -1;
	}
	for(int i=0; i<N; i++){
		sum[i+1] = sum[i]+cnt[i];
	}
	long long ans=0, temp=0;
	for(int i=0; i<N; i++){
		int chk = 1, tmp = 0;
		if(i==0){
			for(int j=i; j<N; j++){
				chk *= a[j];
				if(chk==1) tmp++;
			}
		}
		if(i==0) temp = tmp;
		else temp = a[i-1]==1 ? temp-1 : (N-i)-temp;
		ans += temp;
	}
	printf("%lld %lld", (long long)N * (N-1) / 2 + N - ans, ans);
}
