#include<stdio.h>
#include<algorithm>

bool cmp(const int &x, const int &y){
	if(x%10 == y%10){
		return x<y;
	}
	return (x%10) < (y%10);
}

int main(void){
	int N, M, a[1001], ans=0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a, a+N, cmp);
	for(int i=0; i<N; i++){
		if(a[i]%10 == 0){
			if(M>=a[i]/10-1){
				ans += a[i]/10;
				M -= a[i]/10-1;
			}
			else{
				ans += M;
				M = 0;
			}
		}
		else if(M>0){
			int temp = (M>a[i]/10) ? (a[i]/10) : (M);
			M -= temp;
			ans += temp;
		}
	}
	printf("%d", ans);
}
