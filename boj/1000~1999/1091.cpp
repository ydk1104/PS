#include<stdio.h>

int main(void){
	int N;
	int p[50] = {0, };
	int s[50] = {0, };
	int temp[50][2] = {0, };
	int check = 0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &p[i]);
		temp[i][0] = (p[i]+2)%3+1;
		if((i+1)%3+1 == temp[i][0]){
			check++;
		}
	}
	for(int i=1; i<=N; i++){
		scanf("%d", &s[i]);
		s[i]++;
	}
	if(check == N){
		printf("0");
		return 0;
	}
	int cnt = 0;
	int check2;
	do{
		check = 0;
		check2 = 0;
		cnt++;
		for(int i=1; i<=N; i++){
			temp[s[i]][cnt%2] = temp[i][1-cnt%2];
			if((temp[s[i]][cnt%2] == (s[i]+1)%3+1)){
				check++;
			}
			if((s[i]+1)%3+1 == (i+1)%3+1){
				check2++;
			}
		}
	}
	while((check != N) && (check2 != N));
	if(check==N){
		printf("%d", cnt);
	}
	else{
		printf("-1");
	}
	return 0;
}
