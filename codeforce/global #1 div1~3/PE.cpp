#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){
	int N;
	scanf("%d", &N);
	long long int a[100001];
	long long int b[100001];
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	for(int i=0; i<N; i++) scanf("%lld", &b[i]);
	int flag = 1;
	if((a[0] != b[0]) || (a[N-1] != b[N-1])) flag = 0;
	for(int i=0; i<N-1; i++){
		a[i] = a[i+1] - a[i];
		b[i] = b[i+1] - b[i];
	}
	sort(a, a+N-1);
	sort(b, b+N-1);
	for(int i=0; i<N-1; i++){
		if(a[i] != b[i]){
			flag = 0;
			break;
		}
	}
	if(flag) printf("Yes");
	else printf("No");
}
