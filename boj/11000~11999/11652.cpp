#include<stdio.h>
#include<algorithm>

long long int a[1000001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	std::sort(a, a+N);
	long long int max=0, maxcnt=0, cnt=0;
	for(int i=0; i<N; i++){
		cnt=1;
		while(a[i] == a[i+1]) i++, cnt++;
		if(cnt>maxcnt){
			maxcnt=cnt;
			max=a[i];
		}
	}
	printf("%lld",max);
}
