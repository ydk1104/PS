#include<stdio.h>

double a[2][2];
int nowmax, ans;

void rotate(){
	double temp[2][2];
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			temp[i][j] = a[1-j][i];
		}
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			a[i][j] = temp[i][j];
		}
	}
}

void find(int i){
	double temp = a[0][0] / a[1][0] + a[0][1] / a[1][1];
	if(temp>nowmax){
		nowmax = temp;
		ans = i;
	}
}

int main(void){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++) scanf("%lf", &a[i][j]);
	}
	for(int i=0; i<4; i++){
		find(i);
		rotate();
	}
	printf("%d", ans);
}
