#include<stdio.h>
#include<queue>

int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	int N;
	scanf("%d", &N);
	std::deque<int> v,w;
	int now=1, sum=0;
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		v.push_front(x);
	}
	for(auto i:v){
		sum += i*now;
		now *= a;
	}
	while(sum){
		w.push_front(sum%b);
		sum /= b;
	}
	for(auto i:w) printf("%d ",i);
}
