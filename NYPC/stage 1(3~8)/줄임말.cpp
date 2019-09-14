#include<stdio.h>

unsigned char s[10000];

int main(void){
	int T;
	FILE *out;
	out = fopen("answer3.txt", "w");
	scanf("%d\n", &T);
	for(; T>0; T--){
		scanf("%[^\n]s", &s);
		getchar();
//		printf("string check:%s\n", s);
		if(s[0] != ' '){
			if(s[0] > 128) fprintf(out, "%c%c", s[0], s[1]);
			else fprintf(out, "%c", s[0]);
//			printf("%c", s[0]);
//			printf("%d %d\n", 0x80, s[0]);
		}
		for(int i=1; s[i]!=0; i++){
			if(s[i-1] == ' '){
				if(s[i] > 128) fprintf(out, "%c%c", s[i], s[i+1]);
				else fprintf(out, "%c", s[i]);
//				printf("%c", s[i]);
//				printf("%d %d\n", 0x80, s[i]);
			}
		}
		fprintf(out, "\n");
	}
	fclose(out);
} 
