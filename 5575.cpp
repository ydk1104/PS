#include<stdio.h>

int main(void){
	for(int i=0; i<3; i++){
		int a,b,c,d,e,f;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		d-=a; e-=b; f-=c;
		if(f<0) f+=60,e--;
		if(e<0) e+=60,d--;
		printf("%d %d %d\n",d,e,f);
	}
}
