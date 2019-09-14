#include<stdio.h>

int main(void){
	int X;
	scanf("%d", &X);
	int a = 1;
	int b = 1;
	int cnt = 1;
	while(X>1){
		if(cnt%2 == 0){
			if(b==1){
				cnt++;
				a++;
			}
			else{
				a++;
				b--;
			}
		}
		else{
			if(a==1){
				cnt++;
				b++;
			}
			else{
				a--;
				b++;
			}
		}
		X--;
	}
	printf("%d/%d", a, b);
}
