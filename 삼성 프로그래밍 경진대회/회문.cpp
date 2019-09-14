#include<stdio.h>

int check[10001];
int num[10001];
int cnt = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int palin(int i){
	int temp = i;
	int i2 = 0;
	while(temp>0){
		i2 *= 10;
		i2 += temp%10;
		temp /= 10;
	}
	if(i==i2){
		num[cnt++] = i;
		return 1;
	}
	return 0;
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= 10000; i++){
		check[i] = palin(i);
	}
	for(int t = 1; t <= T; t++){
		int N;
		int ans[4] = {0, };
		scanf("%d", &N);
		if(check[N] == 1){
			ans[0] = 1;
			printf("Case #%d\n%d %d\n", t, ans[0], N);
		}
		else{
			for(int i=0; 2 * num[i]<=N && num[i]!=0; i++){
				if(check[N-num[i]]){
					ans[0] = 2;
					ans[1] = N-num[i];
					ans[2] = num[i];
					if(ans[1] < ans[2]) swap(&ans[1], &ans[2]);
					printf("Case #%d\n%d %d %d\n", t, ans[0], ans[1], ans[2]);
					break;
				}
				if(ans[0] != 3){
					for(int j=0; 2 * num[j]<=N-num[i] && num[j] != 0; j++){
						if(check[N-num[i]-num[j]]){
							ans[0] = 3;
							ans[1] = N-num[i]-num[j];
							ans[2] = num[i];
							ans[3] = num[j];
							break;
						}
					}
				}
			}
		}
		if(ans[0] == 3){
			for(int i=1; i<=3; i++){
				for(int j=i+1; j<=3; j++){
					if(ans[i]>ans[j]){
						swap(&ans[i], &ans[j]);
					}
				}
			}
			printf("Case #%d\n%d %d %d %d\n", t, ans[0], ans[3], ans[2], ans[1]);
		}
		else if(ans[0] == 0){
			printf("Case #%d\n%d", t, ans[0]);
		}
	}
}
