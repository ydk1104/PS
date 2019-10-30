#include<stdio.h>
#include<set>
#include<algorithm>

std::multiset<int> s;
int a[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	s.insert(-2);
//	printf("%d\n", *s.rbegin());
	int start = 0, now = 0;
	for(int i=0; i<N; i++){
//		if(s.rbegin()/2 > )
		while(*s.rbegin() <= a[now%N]*2){
			
			if(s.size() > 2*N){
/*				printf("-1 ");
				s.clear();
				s.insert(-2);
				now = i+1;
				goto v; // */
				for(int j=i; j<N; j++) printf("-1 ");
				return 0;
			}
			
			s.insert(a[now%N]);
			now++;
//			if(now==N) now=0;
		}
		printf("%d ", (now-i));
		s.erase(s.find(a[i]));
		v:;
	}
}
