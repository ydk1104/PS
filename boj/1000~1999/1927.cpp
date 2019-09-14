#include<stdio.h>

int PQ[100001];
int cnt;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(int x){
	cnt++;
	PQ[cnt] = x;
	int i = cnt;
	while((i>1) && (PQ[i/2])>PQ[i]){
		swap(&PQ[i/2], &PQ[i]);
		i /= 2;
	}
}

int pop(){
	if(cnt==0) return 0;
	int temp = PQ[1];
	PQ[1] = PQ[cnt--];
	int i = 1;
	while((2*i<=cnt) && ((PQ[i]>PQ[i*2]) || (PQ[i]>PQ[i*2+1]))){
		if(PQ[i*2] > PQ[i*2+1]){
			swap(&PQ[i], &PQ[i*2+1]);
			i = i*2+1;
		}
		else{
			swap(&PQ[i], &PQ[i*2]);
			i = i*2;
		}
	}
	return temp;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(; N>0; N--){
		int x;
		scanf("%d", &x);
		if(x==0) printf("%d\n", pop());
		else push(x);
	}
}
