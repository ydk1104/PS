#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void){
	char a[3][10];
	scanf("%s %s %s", &a[0], &a[1], &a[2]);
	int b[3];
	for(int i=0; i<=2; i++){
		if(!strcmp(a[i], "black")){
			b[i] = 0;
		}
		else if(!strcmp(a[i], "brown")){
			b[i] = 1;
		}
		else if(!strcmp(a[i], "red")){
			b[i] = 2;
		}
		else if(!strcmp(a[i], "orange")){
			b[i] = 3;
		}
		else if(!strcmp(a[i], "yellow")){
			b[i] = 4;
		}
		else if(!strcmp(a[i], "green")){
			b[i] = 5;
		}
		else if(!strcmp(a[i], "blue")){
			b[i] = 6;
		}
		else if(!strcmp(a[i], "violet")){
			b[i] = 7;
		}
		else if(!strcmp(a[i], "grey")){
			b[i] = 8;
		}
		else if(!strcmp(a[i], "white")){
			b[i] = 9;
		}
	}
	long long int c = b[0] * 10 + b[1];
	c *= pow(10, b[2]);
	printf("%lld",c);
}
