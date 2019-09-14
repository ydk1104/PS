#include<stdio.h>

struct bigint{
	char x[1001];
	void operator +=(bigint x){
		for(int i=0; x.x[i]; i++){
			if(this->x[i]>='0') this->x[i]-='0';
			this->x[i]+=x.x[i];
		}
		for (int i=0; this->x[i]; i++){
			this->x[i+1] += (this->x[i]-'0')/10;
			if(this->x[i+1] > 0 && this->x[i+1]<'0') this->x[i+1]+='0';
			this->x[i] -= (this->x[i]-'0')/10*10;
		}
	}
	void print(){
		char temp[1001] = {0,};
		int i=0, cnt=0;
		while(this->x[i]) i++;
		for(i--; i>=0; i--){
			if(cnt==0 && this->x[i]=='0') continue;
			temp[cnt++]=this->x[i];
		}
		if(temp[0] == 0) printf("0");
		printf("%s\n",temp);
	}
}dp[40][40][3];

int main(void){
	int N=32;
	scanf("%d", &N);
	int map[40][40];
	for(int i=0; i<=N+1; i++){
		for(int j=0; j<=N+1; j++){
			map[i][j] = 1;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			map[i][j]=0;
			scanf("%d", &map[i][j]);
		}
	}
	dp[1][2][0].x[0] = '1';
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			int check[3];
			check[0]= !map[i][j+1];
			check[1]= !map[i+1][j];
			check[2]= (!map[i][j+1]) && (!map[i+1][j]) && (!map[i+1][j+1]);
			int dx[3] = {0, 1, 1}, dy[3] = {1, 0, 1};
			for(int k=0; k<=2; k++){
//				if(check[k]) dp[i+dx[k]][j+dy[k]] += dp[i][j][k];
			}
			if(check[0]) dp[i][j+1][0] += dp[i][j][0];
			if(check[2]) dp[i+1][j+1][2] += dp[i][j][0];
			if(check[1]) dp[i+1][j][1] += dp[i][j][1];
			if(check[2]) dp[i+1][j+1][2] += dp[i][j][1];
			if(check[0]) dp[i][j+1][0] += dp[i][j][2];
			if(check[1]) dp[i+1][j][1] += dp[i][j][2];
			if(check[2]) dp[i+1][j+1][2] += dp[i][j][2];
		}
	}
	dp[N][N][0]+=dp[N][N][1];
	dp[N][N][0]+=dp[N][N][2];
	dp[N][N][0].print();
}
