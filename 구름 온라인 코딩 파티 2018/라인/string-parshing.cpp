#include<stdio.h>
#include<string.h>
#include<math.h>

int trans(char N[], int x){
	int max = strlen(N);
	int sum = 0;
	for(int i=0; i<max; i++){
		if(N[i] >= 'a'){
			N[i] = N[i] - 'a' + 10;
		}
		else{
			N[i] -= '0';
		}
		sum += N[i] * pow(x, max-i-1);
	}
	return sum;
}

int check(char s[]){
	if(!strcmp(s, "yes")) return 1;
	return 0;
}

int main(void){
	int x, y;
	scanf("Canvas size: %d x %d\n", &x, &y);
	char color[256];
	scanf("Background color: 0x%s\n", &color);
	int N;
	int w[65536];
	int h[65536];
	char a[65536][4];
	int d[65536];
	scanf("Number of frames: %d\n", &N);
	scanf("No.: width height alpha duration");
	for(int i=1; i<=N; i++){
		scanf("\n%d: %d %d %s %d", &i, &w[i], &h[i], &a[i], &d[i]);
	}
	printf("%d\n%d\n", x, y);
	printf("%d\n", trans(color, 16));
	printf("%d\n", N);
	for(int i=1; i<=N; i++){
		printf("%dx%d, %d, %d\n", w[i], h[i], d[i], check(a[i]));
	}
	return 0;
}
