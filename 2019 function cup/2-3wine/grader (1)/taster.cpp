#include "taster.h"

std::vector<int> SortWines(int K, std::vector<int> A) {
	int N = A.size();
	int sum[31] = {0, };
	for(int i=0; i<N; i++){
		if(A[i]>1) A[i]+=4;
		else{
			for(int j=i+1; j<N; j++){
				if(A[j]<=1){
					if(Compare(im j)==1) A[i]++;
					else sum[j]++;
				}
			}
			A[i] += sum[i];
		}
	}
	return A;
}
