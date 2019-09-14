#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void){
	int A, B;
	scanf("%d %d", &A, &B);
	if(A>B){
		int temp = A;
		A = B;
		B = temp;
	}
	int K = B-A;
	if(!K){
		printf("0");
		return 0;
	}
	K = ((A-1)/K+1)*K;
	int temp = K;
	for(int i=1; i*i<=K; i++){
		if(K%i==0){
			int temp2 = i;
			if(temp2>=A) temp=min(temp,temp2);
			temp2 = K/i;
			if(temp2>=A) temp=min(temp,temp2);
		}
	}
	K=temp;
//	if(A!=B && (B%A)!=0) printf("%d", ((K)-(A%(K)))%(K));
//	else printf("0");
	printf("%d", K-A);
}
