#include<stdio.h>

int a[15];
int num[10];
int length;

void count(int number, int k, int l){
	if(k<l){
		int cnt = a[l];
		for (int i=1; i<l; i++){
			cnt *= 10;
		}
		num[number] += cnt;
		count(number, k, l-1);
	}
	else if (k==l){
		if (number<a[l]){
			int cnt = 1;
			for (int i=0; i<l; i++){
				cnt *= 10;
			}
			num[number] += cnt;
		}
		else if (number == a[l]){
			int cnt = 0;
			for (int i=l-1; i>=0; i--){
				cnt *= 10;
				cnt += a[i];
			}
			num[number] += cnt + 1;
		}
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	int j=1;
	int cnt = 1;
	while(j*10<=N){
		num[0] += cnt * j * 9;
		j *= 10;
		cnt++;
	}
	num[0] += cnt * (N-j+1);
	while(N){
		a[length] = N%10;
		N = N/10;
		length++;
	}
	length--;
	for(int i=0; i<=length; i++){
		for(int j=1; j<=9; j++){
			count(j,i,length);
		}
	}
	for (int i=1; i<=9; i++){
		num[0] -= num[i]; 
	}
	for (int i=0; i<=9; i++){
		printf("%d ", num[i]);
	}
	return 0;

}
