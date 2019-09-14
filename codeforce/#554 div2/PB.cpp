#include<stdio.h>

int main(void){
	int i, N, max, cnt=0, ans=0, a[50];
	scanf("%d", &N);
	v:
	for(i=N,max=-1, cnt=0; i; i/=2){
//		printf("%d", i%2);
		if(i%2==0) max=cnt;
		cnt++;
	}
//	printf("\n");
	if(max==-1){
		v1:
		printf("%d\n", ans);
		for(int i=0; i<(ans+1)/2; i++) printf("%d ",a[i]);
	}
	else{
		ans++;
		a[ans/2] = max+1;
		int temp=1;
		for(int i=0; i<max; i++) temp=temp*2+1;
		N=N^temp;
		for(int i=N; i; i/=2) if(i%2==0) goto v2;
		goto v1;
		v2:
		N++;
		ans++;
		goto v;
	}
}
