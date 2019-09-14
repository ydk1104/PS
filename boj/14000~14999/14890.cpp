#include<stdio.h>

int map[101][101];
int road[201][101];
int N, L;

int abs(int x){
	if(x>0) return x;
	return -x;
}

int check(int now){
	int row = 1;
	for(int i=0; i<N-1; i++){
		int dis = abs(road[now][i] - road[now][i+1]);
		if(dis>=2) return 0;
		if(dis==0){
			if(road[now][i] == road[now][i+1]) row++;
			else row=1;
		}
		else{
			if(road[now][i]>road[now][i+1]){
				for(int j=i+1; j<=i+L; j++){
					if(j>=N) return 0;
					if(road[now][j] != road[now][i+1]) return 0;
				}
				i += L-1;
				row = 0;
			}
			else{
				if(row<L) return 0;
				row=1;
			}
		}
	}
	return 1;
}

int solve(){
	int ans = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			road[i*2][j] = map[i][j];
			road[i*2+1][j] = map[j][i];
		}
	}
	for(int i=0; i<2*N; i++) ans+=check(i);
	printf("%d", ans);
}

int main(void){
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	solve();
}
