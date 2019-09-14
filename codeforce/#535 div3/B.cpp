#include<stdio.h>
#include<algorithm>

using namespace std;

int compare(int a, int b){
	return a>b;
}

int a[10001];

int findmax(void){
	int i = 10000;
	while(a[i] == 0) i--;
	return i;
}

void remove(int x){
	for(int i=10000; i>0; i--){
		if(x%i==0) a[i]--;
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	int max = findmax();
	printf("%d ", max);
	remove(max);
	printf("%d", findmax());
}
