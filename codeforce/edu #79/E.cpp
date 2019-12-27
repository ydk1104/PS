#include<stdio.h>
#include<vector>
#include<algorithm>

inline void print(std::vector<int>& v){
	for(const auto& i : v) printf("%d ", i);
	printf("\n");
}

inline bool isValid(std::vector<int>& V){
	
	std::vector<int> v = V;
	std::vector<int> temp;
	for(int i=0; i<v.size(); i++){
		int now = v[i];
		temp.push_back(now);
		while(now != i){
			now = v[now];
			temp.push_back(now);
		}
		auto max = std::max_element(temp.begin(), temp.end());
		for(auto i = max; i != max-1; i++){
			if(i == temp.end()) i = temp.begin();
			
		}
	}
	
	return true;
}

long long dp[51][51]; // i, j·Î ½ÃÀÛ 

void setdp(){
	dp[0][0] = 1;
	for(int i=1; i<=50; i++){
		dp[i][i] = 1;
		for(int j=1; j<i; j++){
			for(int k=0; k<i; k++){
				dp[i][j] += dp[i-j][k];
			}
		}
	}
}

std::vector<int> list;

void print(int x){
	printf("%d ", list[x]);
	list.erase(list.begin()+x);
}

void print(int N, int K, int plus){
	if(N<1) return;
	if(N==1){
		print(0);
		return;
	}
	if(K==1){
		for(int i=0; i<N; i++) print(0);
		return;
	}
	int i=-1, sum = 0;
	while(sum+dp[N][i+1] < K && i<N-1) sum += dp[N][++i];
	i++;
	print(i-1);
//	print(i, dp[N][i], plus);
//	if(i>0) print(N-i, K-sum, plus+i);
	print(N-1, K-sum, plus);
}

void solve(int N, long long K){
	long long sum = 0, i = 0;
	while(sum < K && i <= N) sum += dp[N][i++];
	if(sum < K){
		printf("-1");
		return;
	}
	print(N, K, 1);
}

int main(void){
	setdp();
	int T;
	for(scanf("%d", &T); T--;){
		int N; long long K;
		scanf("%d %lld", &N, &K);
		for(int i=1; i<=N; i++) list.push_back(i);
		solve(N, K);
		puts("");
/*		std::vector<int> v(N);
		for(int i=0; i<N; i++) v[i] = i;
		do{
			print(v);
			if(isValid(v)) K--;
		}while(std::next_permutation(v.begin(), v.end()) && K); // */
		list.clear();
	}
}


/*
1 : 1
2 : 1 2, 2 1
3 : 1 2 3, 1 3 2 , 2 1 3, 3 1 2
4 :
1 2 3 4, 1 2 4 3, 1 3 2 4, 1 3 4 2, 1 4 2 3,
2 1 3 4, 2 1 4 3
3 1 2 4
4 3 2 1



*/
