#include<stdio.h>

int N;
int count[1001];
int matrix[21][21];

int update(int* x, int now){
	if(*x == 1){
		while(now <= N && count[now]%4 == 0) now++;
		if(now>N){
			*x = 0;
			now = 1;
		}
		else{
			return now;
		}
	}
	while(count[now] == 0) now++;
	return now;
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N*N; i++){
		int x;
		scanf("%d", &x);
		count[x]++;
	}
	if(N==1){
		for(int i=1; i<=1000; i++){
			if(count[i]) printf("YES\n%d", i);
		}
		return 0;
	}
	else if(N%2){
		int row=0;
		int temp;
		for(int i=1; i<=1000; i++){
			if(count[i]%2){
				row++;
				temp = i;
			}
		}
		if(row!=1){
			printf("NO");
			return 0;
		}
		matrix[N/2+1][N/2+1] = temp;
		count[temp]--;
		row = 0;
		for(int i=1; i<=1000; i++){
			if(count[i]%4){
				row++;
			}
		}
		if(row>(N/2)*2){
			printf("NO");
			return 0;
		}
		int now = 1;
		int check = 1;
		for(int i=1; i<=N/2; i++){
			now = update(&check, now);
			matrix[i][N/2+1] = now;
			matrix[N-i+1][N/2+1] = now;
			count[now] -= 2;
		}
		for(int i=1; i<=N/2; i++){
			now = update(&check, now);
			matrix[N/2+1][i] = now;
			matrix[N/2+1][N-i+1] = now;
			count[now] -= 2;
		}
		for(int i=1; i<=N/2; i++){
			for(int j=1; j<=N/2; j++){
				now = update(&check, now);
				matrix[i][j] = now;
				matrix[i][N-j+1] = now;
				matrix[N-i+1][j] = now;
				matrix[N-i+1][N-j+1] = now;
				count[now] -= 4;
			}
		}
	}
	else{
		for(int i=1; i<=1000; i++){
			if(count[i]%4){
				printf("NO");
				return 0;
			}
		}
		int k=1;
		for(int i=1; i<=N/2; i++){
			for(int j=1; j<=N/2; j++){
				while(count[k] == 0) k++;
				count[k] -= 4;
				matrix[i][j] = k;
				matrix[N-i+1][j] = k;
				matrix[i][N-j+1] = k;
				matrix[N-i+1][N-j+1] = k;
			}
		}
	}
	printf("YES\n");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
