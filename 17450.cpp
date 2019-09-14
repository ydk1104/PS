#include<stdio.h>

int main(void){
	int a,b, ans=0, aa=0, ab=0;
	char s[4] = "SNU";
	for(int i=0; i<3; i++){
		scanf("%d %d", &a, &b);
		if(a>=500) a-=50;
		if(a * ab <= b * aa){
			aa = a;
			ab = b;
			ans = i;
		}
	}
	printf("%c",s[ans]);
}
