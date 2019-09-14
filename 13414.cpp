#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

map<int, int> M1;
map<int, int> M2;

int main(void){
	int K, L;
	scanf("%d %d", &K, &L);
	for(int i=0; i<L; i++){
		int x;
		cin >> x;
		if(M1.find(x) != M1.end()){
			M2[M1[x]] = -1;
		}
		M1[x] = i;
		M2[i] = x;
	}
	for(int i=0, cnt=0; i<L && cnt<K; i++){
		if(M2[i] == -1) continue;
		printf("%08d\n", M2[i]);
		cnt++;
	}
}
