#include<stdio.h>
#include<algorithm>

int main(void){
	int N;
	scanf("%d", &N);
	int a[101], ans=0;
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a,a+N);
	for(int i=0; i<N; i++){
		if(a[i]){
			for(int j=i+1; j<N; j++){
				if(a[j] % a[i]) continue;
				a[j] = 0;
			}
			ans++;
		}
	}
	printf("%d", ans);
}
