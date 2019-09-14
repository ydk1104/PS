#include<stdio.h>
#include<set>

int N, Q, a[100001];
int odd(int x, int y){
	std::set<int> s;
	for(int i=x-1; i<y; i++){
		if(s.find(a[i])!=s.end()) s.erase(a[i]);
		else s.insert(a[i]);
	}
	return *s.begin();
}

int main(void){
	scanf("%d %d", &N, &Q);
	for(int i=0; i<N; i++) scanf("%d", a+i);
	for(int i=0; i<Q; i++){
		int type,x,y;
		scanf("%d %d %d", &type, &x, &y);
		if(type==1){
			a[x-1] = y;
		}
		else{
			printf("%d\n", odd(x,y));
		}
	}
}
