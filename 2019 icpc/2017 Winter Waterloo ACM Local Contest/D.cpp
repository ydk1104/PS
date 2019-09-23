#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

//std::map<int, long long> dp[31];
long long arr[31][901];

int find(std::vector<int> v){
	if(v.size() == 0) return 0;
	int pivot = v[0];
	int count = v.size();
	std::vector<int> v1, v2;
	for(int i=1; i<v.size(); i++){
		if(v[i] < pivot) v1.push_back(v[i]);
		else v2.push_back(v[i]);
	}
	return count + find(v1) + find(v2);
}

int permutation(int N){
	if(!N) return 0;
	std::vector<int> arr(N);
	for(int i=0; i<N; i++){
		arr[i] = i;
	}
	int cnt[900] = {0,};
	do{
		cnt[find(arr)]++;
	}while(std::next_permutation(arr.begin(), arr.end()));
	for(int i=0; i<900; i++){
		if(cnt[i]) printf("%d %d %d\n", N, i, cnt[i]);
	}
	return permutation(N-1);
}

long long fac(int N){
	return N<=1 ? 1 : N * fac(N-1);
}

long long nCr[31][31];
long long mod = 1e9+7;
long long C(int n, int r){
	if(nCr[n][r]) return nCr[n][r];
	if(r==1 || r==n-1) return nCr[n][r] = n;
	if(r==0 || r==n) return nCr[n][r] = 1;
	return nCr[n][r] = (C(n-1, r-1) + C(n-1, r)) % mod;
}

int main(void){
//	permutation(7);
	int N, K;
	scanf("%d %d", &N, &K);
	if(K > N*(N+1)/2){
		printf("0");
		return 0;
	}
//	dp[0][0] = 1;
//	dp[1][1] = 1;
	arr[1][1] = 1;
	int fi[] = {1,1,2,3,5,8,13,};
	for(int i=2; i<=N; i++){
		for(int j=0; j<=K; j++){
/*			for(auto &k : dp[j]){
				for(auto &l : dp[i-j-1]){
					printf("%d %d %d %d\n", k.first, k.second, l.first, l.second);
					if(k.first+l.first+i > K) continue;
					dp[i][k.first+l.first+i] += k.second*l.second*(1+(j+j==i-1));
					dp[i][k.first+l.first+i] %= mod;
				}
			} */
			for(int k=0; k<i; k++){
				if(k==0 || k==i-1){
					arr[i][j] += arr[i-1][j-i];
					if(arr[i][j] > mod) arr[i][j] -= mod;
					continue;
				}
				for(int l=1; l<=j-i-1; l++){
//					printf("%d %d %d %d\n", i, j, k, l);
					long long temp = arr[k][l] * arr[i-k-1][j-i-l];
					temp %= mod;
					temp *= C(i-1, k);
					temp %= mod;
					arr[i][j] += temp;
					if(arr[i][j] > mod) arr[i][j] -= mod;
				}
			}
		}
//		printf("---------------\n");
	}
	for(int i=0; i<=N; i++){
		for(int j=0; j<=K; j++){
//			if(arr[i][j]) printf("%d %d %d\n", i, j, arr[i][j]);
		}
	}
	printf("%d\n", arr[N][K]);
// */
}

/*
1 => 1
2 => 1,2 == 3, 2,1 == 3
3 =>
1,2,3 => 3+3=6
1,3,2 => 6
2,1,3 => 3+1+1 = 5
2,3,1 => 5
3,1,2 => 6
3,2,1 => 6
4 =>
1,2,3,4 => 4+6 => 10
1,2,4,3 => 4+6 => 10
1,3,2,4 => 4+5 => 9
1, => 9
1, => 10 10
2, => {1,3,4} => 어떻게 배열해도 4+1+3, 8
따라서
dp[1][1] = 1;
dp[2][3] = 2;
dp[3][5] = 2, dp [3][6] = 4;
dp[4][8] = 12, dp[4][9] = 4, dp[4][10] = 8;
dp[5][
*/
