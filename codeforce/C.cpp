#include<stdio.h>
#include<algorithm>

using namespace std;

long long int D[300000];
long long int temp[300000];
long long int sum;
char s[300000];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%I64d", &D[i]);
	}
	scanf("%s", &s);
	for(int i=0; i<N;){
		int row = 0;
		while(s[i] == s[i+row]){
			temp[row] = D[i+row];
			row++;
		}
		sort(temp, temp+row);
		for(int j=0; j<K && j<row; j++){
			sum += temp[row-j-1];
		}
		i += row;
	}
	printf("%I64d", sum);
}
