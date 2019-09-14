#include<stdio.h>
#include<algorithm>

int main(void){
	#define int long long
	int N, a[6], m1=51, m2=101, m3, M=0, sum=0;
	scanf("%lld", &N);
	for(int i=0; i<6; i++) scanf("%lld", &a[i]);
	for(int i=0; i<6; i++){
		sum += a[i];
		m1 = std::min(m1, a[i]);
		M = std::max(M, a[i]);
	}
	if(N==1){
		printf("%lld", sum-M);
		return 0;
	}
	for(int i=0; i<5; i++){
		for(int j=i+1; j<6; j++){
			if(i+j==5) continue;
			m2 = std::min(m2, a[i]+a[j]);
		}
	}
	int temp = 101, t[5] = {4,0,1,5,4};
	for(int i=0; i<4; i++){
		temp = std::min(temp, a[t[i]]+a[t[i+1]]);
	}
	m3 = std::min(a[2], a[3]) + temp;
	printf("%lld", m1 * ((N-2)*(N-2) + (N-1) * (N-2) * 4) + m2 * ((N-2) * 4 + (N-1) * 4) + m3 * 4);
}
