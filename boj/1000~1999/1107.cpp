#include<stdio.h>

int er[11];
int ermin = 10;
int ermax = -1;
int Ncnt;

int min(int a, int b){
	if(a<b) return a;
	return b;
}

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int abs(int N){
	if(N>=0) return N;
	return -N;
}

int count(int N){
	if(N==0) return 1;
	int cnt = 0;
	while(N>0){
		cnt++;
		N /= 10;
	}
	return cnt;
}

int check(int N){
	if(N==0){
		if(er[N] == 0){
			return 1;
		}
		return 0;
	}
	while(N>0){
		if(er[N%10] == 1){
			return 0;
		}
		N/=10;
	}
	return 1;
}

int find(int N){
	int a[10];
	int cnt = 0;
	for(int i=N; i>0; i/=10){
		a[cnt] = i%10;
		cnt++;
	}
	cnt--;
	int temp = 0;
	if(cnt==-1){
		return Ncnt; // 망가진 버튼이 없어 모두 누를 수 있을때 
	}
	int ans = 10000000;
	for(int i=0; i<=1000000; i++){
		if(check(i)){
			ans = min(ans, count(i)+abs(i-N));
		}
	}
	return ans;
}

int main(void){
	int N;
	scanf("%d", &N);
	int ans = abs(N - 100);
	int K;
	scanf("%d", &K);
	for(int i=1; i<=K; i++){
		int temp;
		scanf("%d", &temp);
		er[temp] = 1;
	}
	if(K==10){
		printf("%d", ans);
		return 0;
	}
	if(K==9 && er[0]==0){
		printf("%d", min(ans, 1+N));
		return 0;
	}
	for(int i=0; i<=9; i++){
		if(er[i]==0){
			ermin = min(i, ermin);
			ermax = max(i, ermax);
		}
	}
	if(N==0){
		printf("%d", ermin+1);
		return 0;
	}
	Ncnt = count(N);
	int ansmax = 0;
	for(int i=1; i<Ncnt; i++){
		ansmax *= 10;
		ansmax += ermax;
	}
	int ansmaxcnt = count(ansmax);
	ansmax = abs(N - ansmax);
	ansmax += ansmaxcnt;
	if(Ncnt == 1){
		ansmax = 100;
	}
	int ansmin = ermin;
	if(ansmin==0){
		for(int i=1; i<=9; i++){
			if(er[i] == 0){
				ansmin = i;
				break;
			}
		}
	}
	if(ansmin == 0){
		ansmin = N+1;
	}
	else{
		for(int i=1; i<=Ncnt; i++){
			ansmin *= 10;
			ansmin += ermin;
		}
		int ansmincnt = count(ansmin);
		ansmin = abs(N-ansmin);
		ansmin += ansmincnt;
	}
	ans = min(ans, ansmax);
	ans = min(ans, ansmin);
	ans = min(ans, find(N));
	printf("%d\n", ans);
	return 0;
}
