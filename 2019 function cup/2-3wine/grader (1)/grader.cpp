#include <stdio.h>
#include <stdlib.h>
#include "bartender.h"
#include "taster.h"
#include "bartender.cpp"
#include "taster.cpp"

static int N, K, chk[33];
static std::vector<int> A, R1, R2;

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(0); }
}

static int call_cnt = 0;
int Compare(int P, int Q){
	call_cnt++;
	my_assert(call_cnt <= 30, "Wrong[2] : Too Much Calls");
	my_assert(0 <= P && P < N && 0 <= Q && Q < N && P != Q, "Wrong[2] : Invalid Argument");
	my_assert(A[P] + A[Q] <= K, "Wrong[2] : Hangover");

	return R1[P] < R1[Q] ? -1 : 1;
}

int main(){
	my_assert(scanf("%d%d", &N, &K) == 2, "Error: Invalid Input");
	my_assert(1 <= N && N <= 30 && 7 <= K && K <= 30, "Error: Invalid Input");
	R1.resize(N);
	for(int i = 0; i < N; i++){
		my_assert(scanf("%d", &R1[i]) == 1, "Error: Invalid Input");
		my_assert(1 <= R1[i] && R1[i] <= N && !chk[R1[i]], "Error: Invalid Input");
		chk[R1[i]] = 1;
	}

	A = BlendWines(K, R1);
	my_assert((int) A.size() == N, "Wrong[1] : Invalid Array");
	for(int i = 0; i < N; i++){
		my_assert(1 <= A[i] && A[i] <= K, "Wrong[1] : Invalid Array");
	}

	R2 = SortWines(K, A);
	my_assert((int) R2.size() == N, "Wrong[2] : Invalid Array");
	for(int i = 0; i < N; i++){
		my_assert(R1[i] == R2[i], "Wrong[2] : Wrong Answer");
	}

	printf("Correct\n");
	return 0;
}
