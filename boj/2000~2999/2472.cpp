#include<stdio.h>

typedef struct road {
	int end;
	int value;
}road;

typedef struct tree {
	int value;
	int number;
}tree;

road r[100001][5];
tree t[100001];

int A[100001];
int B[100001];
int C[100001];
int check[100001];
int MAX;

int min(int x, int y) {
	if (x < y) return x;
	else return y;
}

void swap(tree *x, tree *y) {
	tree temp = *x;
	*x = *y;
	*y = temp;
}

void put(int value, int number) {
	MAX++;
	t[MAX].value = value;
	t[MAX].number = number;
	int i = MAX;
	while (t[i].value < t[i / 2].value && i > 1) {
		swap(&t[i], &t[i / 2]);
		i = i / 2;
	}
}

int pop() {
	int temp = t[1].number;
	if (temp == 0) return temp;
	t[1] = t[MAX];
	t[MAX].value = 0;
	t[MAX].number = 0;
	MAX--;

	int i = 1;
	while (((t[i].value < t[2 * i].value && t[2 * i].value != 0) || (t[i].value < t[2 * i + 1].value && t[2 * i + 1].value != 0)) && i <= MAX) {
		int big;
		if (t[2 * i + 1].value == 0) big = 2 * i;
		else if (t[2 * i].value > t[2 * i + 1].value) big = 2 * i + 1;
		else big = 2 * i;
		//		printf("swap (%d %d) %d %d", t[i].value, t[big].value, i, big);
		swap(&t[i], &t[big]);
		i = big;
	}

	return temp;
}

void length(int a[], int x) {
	for (int i = 0; i <= 4; i++) {
		if (r[x][i].end == 0) return;

		int end = r[x][i].end;
		int value = r[x][i].value;

		if (a[end] == -1) {
			a[end] = a[x] + value;
			//			printf("a[end] = %d, end = %d\n", a[end], end);

			put(a[end], end);
		}
		else {
			if (a[x] + value < a[end]) {
				a[end] = a[x] + value;
				//				printf("a[end] = %d, end = %d\n", a[end], end);
				put(a[end], end);
			}
		}
	}
}

void find(int a[], int x) {
	length(a, x);
	check[x] = 1;
	int k = pop();
	//	printf("k = %d \n", k);
	if (k == 0) return;
	while (check[k] == 1) {
		k = pop();
		//		printf("k = %d \n", k);
		if (k == 0) return;
	}
	//	printf("k == %d \n", k);
	find(a, k);
}

int main(void) {
	int N, M;
	scanf("%d", &N);
	scanf("%d %d %d", &A[0], &B[0], &C[0]);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		for (int i = 0; i <= 4; i++) {
			if (r[x][i].value == 0) {
				r[x][i].end = y;
				r[x][i].value = z;
				break;
			}
		}
		for (int i = 0; i <= 4; i++) {
			if (r[y][i].value == 0) {
				r[y][i].end = x;
				r[y][i].value = z;
				break;
			}
		}
	}


	int T;
	scanf("%d", &T);
	if (N <= 2) {
		for (int i = 1; i <= T; i++) {
			int Q;
			scanf("%d", &Q);
			printf("YES\n");
		}
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		A[i] = -1;
		B[i] = -1;
		C[i] = -1;
	}
	A[A[0]] = B[B[0]] = C[C[0]] = 0;
	find(A, A[0]);
	for (int i = 1; i <= N; i++) {
		check[i] = 0;
		t[i].value = 0;
		t[i].number = 0;
	}
	MAX = 0;
	find(B, B[0]);
	for (int i = 1; i <= N; i++) {
		check[i] = 0;
		//		printf("t[i] = %d %d\n", t[i]);
		t[i].value = 0;
		t[i].number = 0;
	}
	MAX = 0;
	find(C, C[0]);
		for (int i = 1; i <= N; i++) {
			printf("%d %d %d\n", A[i], B[i], C[i]);
		}
	for (int i = 1; i <= T; i++) {
		int Q;
		scanf("%d", &Q);
		for (int i = 1; i <= N; i++) {
			if (A[Q] > A[i] && B[Q] > B[i] && C[Q] > C[i]) {
				printf("NO\n");
				Q = 0;
				break;
			}
		}
		if (Q != 0) printf("YES\n");
	}
}
