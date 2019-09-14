#include<stdio.h>

int N, M;

int min(int a, int b){
	if(a>b) return b;
	return a;
}

int left(int point, int target, int b[]){
	int cnt = 0;
	while(point != target){
		point--;
		if(point==0){
			point = N;
		}
		while(b[point] == 0){
			point--;
			if(point==0){
				point = N;
			}
		}
		cnt++;
	}
	return cnt;
}

int right(int point, int target, int b[]){
	int cnt = 0;
	while(point != target){
		point++;
		if(point == N+1){
			point = 1;
		}
		while(b[point] == 0){
			point++;
			if(point == N+1){
				point = 1;
			}
		}
		cnt++;
	}
	return cnt;
}

int main(void){
	scanf("%d %d", &N, &M);
	int a[51];
	int b[51];
	for (int i=1; i<=N; i++){
		b[i] = 1;
	}
	for (int i=1; i<=M; i++){
		scanf("%d", &a[i]);
	}
	int k=1;
	int i=1;
	int cnt = 0;
	while(i<=M){
		while(b[k] == 0){
			k++;
			if(k>N) k -= N;
		}
		
		if(a[i] == k){
			i++;
			b[k] = 0;
		}
		else{
			cnt += min(left(k, a[i], b), right(k, a[i], b));
			k = a[i];
			i++;
			b[k] = 0;
		}
	}
	printf("%d", cnt);
}
