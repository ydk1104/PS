#include<stdio.h>

typedef struct node{
	int left;
	int right;
}node;

node tree[27];

void find1(int N){
	printf("%c", N+'A');
	int left = tree[N].left;
	int right = tree[N].right;
	if(left>0 && right>0) return find1(left), find1(right);
	if(left>0) return find1(left);
	if(right>0) return find1(right);
}

void find2(int N){
	int left = tree[N].left;
	int right = tree[N].right;
	if(left>0) find2(left);
	printf("%c", N+'A');
	if(right>0) return find2(right);
}

void find3(int N){
	int left = tree[N].left;
	int right = tree[N].right;
	if(left>0) find3(left);
	if(right>0) find3(right);
	printf("%c", N+'A');
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		char x, a, b;
		scanf("%c %c %c", &x, &a, &b);
		tree[x-'A'].left = a-'A';
		tree[x-'A'].right = b-'A';
	}
	find1(0);
	printf("\n");
	find2(0);
	printf("\n");
	find3(0);
}
