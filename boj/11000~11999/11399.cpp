#include<stdio.h>
#include<algorithm>

using namespace std;
	
int main(void){
	int N;
	scanf("%d", &N);
	int time[1001];
	for(int i=0; i<N; i++) scanf("%d", &time[i]);
	sort(time, time+N);
	int sum = 0, ans = 0;
	for(int i=0; i<N; i++){
		sum += time[i];
		ans += sum;
	}
	printf("%d", ans);
}
