#include<stdio.h>

int x[100001], y[100001];

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N, Q;
		scanf("%d %d", &N, &Q);
		while(N--){
			int tx, ty;
			char type;
			scanf("%d %d %c", &tx, &ty, &type);
			if(type=='N') y[ty+1]++;
			if(type=='S') y[ty]--, y[0]++;
			if(type=='E') x[tx+1]++;
			if(type=='W') x[tx]--, x[0]++;
		}
		int ax=0, ay=0;
		int xmax=0, ymax=0;
		int xsum=0, ysum=0;
		for(int i=0; i<=Q; i++){
			xsum+=x[i], ysum+=y[i];
			if(xmax<xsum){
				xmax=xsum;
				ax=i;
			}
			if(ymax<ysum){
				ymax=ysum;
				ay=i;
			}
		}
		printf("Case #%d: %d %d\n", t, ax, ay);
	}
}
