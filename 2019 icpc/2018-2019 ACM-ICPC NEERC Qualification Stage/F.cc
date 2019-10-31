#include<stdio.h>
#include<math.h>
#include<tuple>
 
struct A{
	int ans=0;
	int unlucky[28]={0,};
}arr[1000001];
 
int sum(int N){
	int temp = 0;
	while(N){
			temp += N%10;
			N/=10;
	}
	return temp;
}
 
int findUnLucky(int num){
	return abs(sum(num/1000) - sum(num%1000));
}
 
int main(void){
	for(int i=0; i<=1000000; i++){
		if(i) for(int j=0; j<28; j++) arr[i].unlucky[j] = arr[i-1].unlucky[j];
		int unlucky = findUnLucky(i);
		arr[i].unlucky[unlucky]++;
		for(int j=0; j<unlucky; j++){arr[i].ans += arr[i].unlucky[j];}
	}
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
			int x;
			scanf("%d", &x);
			printf("%d\n",arr[x].ans);
	}
}
