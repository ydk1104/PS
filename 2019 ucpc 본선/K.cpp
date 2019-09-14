#include<stdio.h>
#include<algorithm>

int N, a[100001];

bool go(int t){
	int sum=1, cnt=0;
	for(int i=0; i<N; i++){
		int now = (a[i]-1)/t;
		if(now == 0) cnt++;
		if(now >= 2) sum += now-1;
	}
	return sum <= cnt;
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	int left=1, right=1e9;
	while(left<right){
		int mid = (left+right)/2;
		if(go(mid)) right=mid;
		else left=mid+1;
	}
	printf("%d", left);
}
