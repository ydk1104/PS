#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d\n", &N, &M);
	char map[101][101];
	for(int i=0; i<N; i++) scanf("%s", &map[i]);
	char ch[128];
	ch[46] = '.'; ch[79] = 'O'; ch[45]=124; ch[124]=45; ch[47]=92; ch[92]=47;
	ch[94]=60; ch[60]=118; ch[118]=62; ch[62]=94;
	for(int i=M-1; i>=0; i--){
		for(int j=0; j<N; j++){
			printf("%c", ch[map[j][i]]);
		}
		printf("\n");
	}
}
