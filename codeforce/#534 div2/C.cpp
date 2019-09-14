#include<stdio.h>

char s[1001];
int map[4][4];

void test(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void check(){
//	test();
	int temp[4][2] = {0, };
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(map[i][j]){
				temp[i][0]++;
				temp[j][1]++;
			}
		}
	}
	for(int i=0; i<4; i++){
		if(temp[i][0] == 4){
			for(int j=0; j<4; j++){
				map[i][j] = 0;
			}
		}
		if(temp[i][1] == 4){
			for(int j=0; j<4; j++){
				map[j][i] = 0;
			}
		}
	}
}

void fill(char x){
	if(x == '1'){
		for(int i=0; i<=3; i++){
			for(int j=0; j<3; j++){
				if(map[i][j] == 0 && map[i][j+1] == 0){
					map[i][j]++;
					map[i][j+1]++;
					printf("%d %d\n", i+1, j+1);
					return check();
				}
			}
		}
	}
	else{
		for(int j=0; j<=3; j++){
			for(int i=0; i<3; i++){
				if(map[i][j] == 0 && map[i+1][j] == 0){
					map[i][j]++;
					map[i+1][j]++;
					printf("%d %d\n", i+1, j+1);
					return check();
				}
			}
		}
	}
}

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]!=0; i++){
		fill(s[i]);
	}
}
