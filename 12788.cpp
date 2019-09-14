#include<stdio.h>
#include<algorithm>
#include<functional>

int main(void){
	int N,a,b,arr[1001];
	scanf("%d %d %d", &N, &a, &b);
	a*=b;
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	std::sort(arr,arr+N, std::greater<int>());
	int check=0;
	for(int i=0; i<N; i++){
		a-=arr[i];
		if(a<=0){printf("%d", i+1);check=1;break;}
	}
	if(!check) printf("STRESS");
}
