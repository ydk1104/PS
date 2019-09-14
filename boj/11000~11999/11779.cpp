#include<stdio.h>
#define INF 2000000000
#define min(a,b) (a)>(b) ? (b) : (a)

typedef struct City{
	int num;
	int cost;
	int prev;
	int check;
}C;

int N;
int bus[1011][1011];
C city[1011];
C heap[10000001];
int cnt;

int compare(C a, C b){
	if(a.cost > b.cost) return 1;
	return 0;
}

void swap(C* a, C* b){
	C temp = *a;
	*a = *b;
	*b = temp;
}

void push(int num, int cost, int prev, int check){
	cnt++;
	heap[cnt].num = num;
	heap[cnt].cost = cost;
	heap[cnt].prev = prev;
	heap[cnt].check = check;
	int i = cnt;
	while(i>1 && compare(heap[i/2], heap[i])){
		swap(&heap[i/2], &heap[i]);
		i /= 2;
	}
}

C pop(){
	C temp = heap[1];
	heap[1] = heap[cnt];
	heap[cnt--] = heap[0];
	int i = 1;
	while(i*2<=cnt && (compare(heap[i], heap[i*2]) || compare(heap[i], heap[i*2+1]))){
		if(compare(heap[i*2], heap[i*2+1])){
			swap(&heap[i], &heap[i*2+1]);
			i = i*2+1;
		}
		else{
			swap(&heap[i], &heap[i*2]);
			i = i*2;
		}
	}
	return temp;
}

void dijk(int end){
	C now = pop();
	if(now.num == end) return;
	if(city[now.num].check) return dijk(end);
	city[now.num].check = 1;
	for(int i=1; i<=N; i++){
		if(bus[now.num][i] != -1){
			if(city[i].cost > city[now.num].cost + bus[now.num][i]){
				city[i].cost = city[now.num].cost + bus[now.num][i];
				city[i].prev = now.num;
				push(i, city[i].cost, city[i].prev, city[i].check);
			}
		}
	}
	return dijk(end);
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			bus[i][j] = -1;
		}
	}
	int M;
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(bus[a][b] == -1) bus[a][b] = c;
		else bus[a][b] = min(bus[a][b], c);
	}
	int start, end;
	scanf("%d %d", &start, &end);
	for(int i=1; i<=N; i++){
		if(i!=start) city[i].cost = INF;
	}
	heap[0].num = INF;
	heap[0].cost = INF;
	heap[0].prev = INF;
	heap[0].check = INF;
	push(start, 0, 0, 0);
	dijk(end);
	printf("%d\n", city[end].cost);
	int ans[1011];
	int cnt = 0;
	ans[cnt] = end;
	cnt++;
	for(; city[end].prev!=0; end=city[end].prev){
		ans[cnt] = city[end].prev;
		cnt++;
	}
	printf("%d\n", cnt);
	for(cnt--; cnt>=0; cnt--){
		printf("%d ", ans[cnt]);
	}
}
