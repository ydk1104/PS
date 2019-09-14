#include<stdio.h>
#include<stdlib.h>

typedef struct road{
	int end;
	int len;
	int *next;
}road;

road map[50001];

void ins(int start, int end, int len){
	road* temp = (road*)malloc(sizeof(road*));
	temp->next = map[start].next;
	while(temp->next != 0){
		temp = temp->next;
	}
	temp->next = temp;
	temp->end = end;
	temp->len = len;
	return;
}

void read(int start){
	road* temp = (road*)malloc(sizeof(road*));
	temp->next = map[start].next;
	while(temp->next->next != 0){
		temp = temp->next;
		push(temp-)
	}
}

int dijk(void){
	read(start);
	
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N-1; i++){
		int a, b, len;
		scanf("%d %d %d", &a, &b, &len);
		ins(a, b, len);
	}
	for(int i=1; i<=N; i++){
		put(i);
		printf("%d\n", dijk);
	}
}
