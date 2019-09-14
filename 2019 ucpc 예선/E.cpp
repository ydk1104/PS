#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>

char s[300001];
int stack[300001];
int cnt;
int map[300001];

void find()

int main(void){
	int N, Q;
	scanf("%d %d", &N, &Q);
	scanf("%s", &s);
	for(int i=0; i<N; i++){
		if(s[i] == '('){
			stack[cnt++] = i;
		}
		if(s[i] == ')'){
			map[i] = stack[--cnt];
			map[stack[cnt]] = i;
		}
	}
	for(int i=0; i<N; i++) printf("%d ", map[i]);
	for(int i=0; i<Q; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		if(s>e){
			int temp=s;
			s=e;
			e=temp;
		}
		printf("%d\n", find(s,e));
	}
}
