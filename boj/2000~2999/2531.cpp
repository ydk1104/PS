#include<stdio.h>
#define max(a,b) (a>b) ? a : b

int N, d, k, c;
int sushi[30000];
int check[30001];

int buy(int n){
	check[sushi[n-1]]--;
	if(check[sushi[n-1]] == 0 && sushi[n-1] !=c ){
		check[0]--;
	}
	if(check[sushi[(n+k-1)%N]] == 0 && sushi[(n+k-1)%N] != c){
		check[0]++;
	}
	check[sushi[(n+k-1)%N]]++;
	return check[0];
}

int main(void){
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for(int i=0; i<N; i++){
		scanf("%d", &sushi[i]);
	}
	int ans = 0;
	for(int i=0; i<k; i++){
		if(check[sushi[i]] == 0 && sushi[i] != c ){
			check[0]++;
		}
		check[sushi[i]]++;
	}
	ans = check[0];
	for(int i=1; i<N; i++){
		int temp = buy(i);
		ans = max(ans, temp);
	}
	printf("%d", ans+1);
}
