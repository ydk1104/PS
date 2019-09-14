#include<stdio.h>

int stack[100001];
int end = 1;
int cnt = 1;
int a[100001];
int b[100001];

void push(int N){
	stack[end] = N;
	end++;
	printf("+\n");
}

int pop(){
	int temp = stack[end];
	end--;
	printf("-\n");
	return temp;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		b[i] = 1;
	}
	for(int i=1; i<=N; i++){
		if(a[i]<a[i-1]){
			for(int j = a[i-1]-1; j>a[i]; j--){
				if(b[j] == 1){
					printf("NO");
					return 0;
				}
			}
		}
		b[a[i]] = 0;
	}
	for(int i=1; i<=N; i++){
		while(stack[end-1] != a[i]){
			push(cnt);
			cnt++;
		}
		pop();
	}
}
