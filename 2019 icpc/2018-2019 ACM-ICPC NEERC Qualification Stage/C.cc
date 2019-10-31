#include<stdio.h>
 
int gcd(int a, int b){
	return b?gcd(b,a%b):a;
}
 
int a[200001], cnt[101];
 
int main(void){
	int N;
	scanf("%d", &N);
	int d;
	int max = 0;
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		if(!i) d = a[0];
		else d = gcd(d, a[i]);
	}
	for(int i=0; i<N; i++){
		a[i] /= d;
		for(int j=0; j<=30; j++){
//			printf("Test : %d", 1<<j);
			if(a[i] == 1<<j){
				cnt[j]++;
				if(max<j) max=j;
				goto v;
			}
		}
		printf("-1");
		return 0;
		v:;
	}
	int ans=0;
	for(int i=0; i<=100; i++){
		if(cnt[i]==1 && max<=i) break;
		ans += cnt[i]%2;
		cnt[i+1] += cnt[i]/2+cnt[i]%2;
	}
	printf("%d", ans);
}
