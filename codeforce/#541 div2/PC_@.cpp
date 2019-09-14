#include<stdio.h>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))

int abs(int x){
	if(x>0) return x;
	return -x;
}

int a[101];
int b[101];
int c[101];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	int ans = 2100000000;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i==j) continue;
			b[0] = a[i];
			b[N-1] = a[j];
			for(int k=0, cnt=1; cnt<N-1; k++){
				if(k==i || k==j) continue;
				b[cnt] = a[k];
				cnt++;
			}
			std::sort(b+1, b+N-1);
			int temp = abs(b[N-1] - b[0]);
			for(int k=1; k<N; k++){
				temp = max(temp, abs(b[k] - b[k-1]));
			}
			if(ans>temp){
				ans = temp;
				for(int k=0; k<N; k++) c[i] = b[i];
			}
		}
	}
	for(int i=0; i<N; i++) printf("%d ", c[i]);
}
