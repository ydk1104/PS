#include<stdio.h>

class priority_queue{
	public:
	int a[100001];
	int cnt;
	void swap(int x, int y){
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}
	void push(int x){
		a[++cnt] = x;
		int i=cnt;
		while(i>1){
			if(a[i] > a[i/2]) swap(i, i/2);
			i/=2;
		}
	}
	void print(){
		for(int i=1; i<=cnt; i++) printf("%d ", a[i]);
	}
}pq;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=2; i<=N; i++){
		pq.push(i);
	}
	pq.push(1);
	pq.print();
}
