#include<stdio.h>
#include<stdlib.h>
#define abs(x) x>0 ? x : -(x)

int gcd(int a, int b){
	if(a==0) return b;
	if(b==0) return a;
	if(a>b) return gcd(a%b, b);
	return gcd(a, b%a);
}

int answer[200001];

int compare(const void *a, const void *b){
	int* n1 = (int*) a;
	int* n2 = (int*) b;
	if(*n1 > *n2){
		return 1;
	}
	if(*n1 == *n2){
		return 0;
	}
	return -1;
}

int main(void){
	int N;
	int a[101];
	int b[101];
	int ans;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		if(i==2){
			b[i] = abs(a[i]-a[i-1]);
			ans = b[i];
		}
		if(i>=3){
			b[i] = abs(a[i] - a[i-1]);
			ans = gcd(ans, b[i]);
		}
	}
	int cnt = 0;
	for(int i=1; i*i<=ans; i++){
		if(ans%i == 0){
			answer[cnt] = i;
			answer[cnt+1] = ans/i;
			if(answer[cnt+1] == answer[cnt]){
				cnt--;
			}
			cnt+=2;
		}
	}
	qsort(answer, cnt, sizeof(int), compare);
	for(int i=1; i<cnt; i++){
		printf("%d ", answer[i]);
	}
}
