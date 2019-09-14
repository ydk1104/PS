#include<stdio.h>

typedef struct tree{
	int pa;
	int N;
}tree;

tree a[51] = {};

int leaf(int num, int de){
	if(num==de){
		return 0;
	}
	while(a[num].pa != -1 && a[num].pa != de){
		num = a[num].pa;
	}
	if(a[num].pa != de){
		return 1;
	}
	return 0;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i].pa);
		int j = a[i].pa;
		if(j!=-1){
			a[j].N++;			
		}
	}
	int de;
	scanf("%d", &de);
	a[a[de].pa].N--;
	int ans = 0;
	for(int i=0; i<N; i++){
		if(a[i].N == 0){
			ans += leaf(i, de);
		}
	}
	printf("%d", ans);
	return 0;
}
