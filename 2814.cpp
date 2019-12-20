#include<stdio.h>
#include<vector>
#include<algorithm>

int MAX = 1e9;

inline int f(long long x){return x>MAX?0:x;}

int main(void){
	long long N, P;
	scanf("%lld %lld", &N, &P);
	if(P==2) printf("%d", f(N*2));
	else if(N==1) printf("%d", P);
	else if(N*P>MAX || P*P>MAX) printf("0");
	else{
		bool IsNotPrime[40001];
		int PRIMEMAX = P-1;
		std::vector<int> Prime(1,2);
		for(int i=3; i<=PRIMEMAX; i+=2){
			if(IsNotPrime[i]) continue;
			for(int j=i; j<=PRIMEMAX; j+=i*2){
				IsNotPrime[j] = true;
			}
			Prime.push_back(i);
//			printf("%d ", i);
		}
		long long temp = 1, cycle = 1;
		for(const auto& i : Prime){
			temp *= (i-1);
			cycle *= i;
			if(temp > MAX) break;
		}
		if(1){
			int CanCycle = std::min(cycle, MAX/P);
			std::vector<int> ans(CanCycle, 0);
			for(const auto& i : Prime){
				if(i==2) continue;
				ans[i] = 1;
				for(int j=i*i; j<=CanCycle; j+=i*2) ans[j] = 1;
			}
			std::vector<int> loop(1, 1);
			for(int i=3; i<=CanCycle; i+=2) if(!ans[i]) loop.push_back(i);
			cycle *= (N-1)/temp;
			long long answer = 0;
			if(loop.size() > (N-1)%temp) answer = P*(cycle+loop[(N-1)%temp]);
			printf("%d\n", f(answer));
		}
		else{
			printf("Error : %d\n", Prime.size());
			for(const auto& i : Prime) printf("%d ", i);
			printf("\n%lld %lld\n",temp, cycle);
		}
	}
}
