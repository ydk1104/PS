#include<stdio.h>
#include<vector>

int isNotPrime[4000001];

int main(void){
	int N;
	scanf("%d", &N);
	std::vector<int> Prime;
	Prime.push_back(2);
	for(int i=3; i<=N; i+=2){
		if(isNotPrime[i]) continue;
		Prime.push_back(i);
		for(int j=i; i*j<=N && i*j>0; j+=2){
			isNotPrime[i*j] = 1;
		}
	}
	int ans=0, sum=0;
	for(int i=0, j=0; i<=Prime.size(); i++){
		while(j<=Prime.size() && sum<N) sum+=Prime[j++];
		if(sum==N) ans++;
		sum-=Prime[i];
	}
	printf("%d", ans);
}
