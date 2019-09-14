#include<stdio.h>

int main(void){
	int r, w, h;
	int cnt = 1;
	while(1){
		scanf("%d", &r);
		if(r==0) break;
		scanf("%d %d", &w, &h);
		r *= 2;
		r *= r;
		w *= w;
		h *= h;
		if(r<w+h){
			printf("Pizza %d does not fit on the table.\n", cnt);
		}
		else{
			printf("Pizza %d fits on the table.\n", cnt);
		}
		cnt++;		
	}
	return 0;
}
