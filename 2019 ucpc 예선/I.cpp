#include<stdio.h>

struct point{
	int x;
	int h;
	int type;
	
	bool operator ==(point &x){
		if(this->x != x.x) return 0;
		if(this->h != x.h) return 0;
		if(this->type != x.type) return 0;
		return 1;
	}
};

int ans;

void BT(int N, int now, point arr[], point x, point prev){
	for(int i=0; i<now; i++){
//		printf("%d : %d %d %d // %d %d %d\n", now, x.x, x.h, x.type, prev.x, prev.h, prev.type);
		if(x==arr[i]){
			ans+=N==now;
			printf("return\n");
			return;
		}
	}
	if(N==now) return;
	arr[now] = x;
	if(prev.h == 1){
		point y, z={0,0,0};
		z.h = 1;
		y.x = x.x-1;
		y.h = x.h;
		y.type = -x.type;
		BT(N, now+1, arr, y, z);
		
		y.x = x.x;
		y.h = x.h+x.type;
		z.h = 0;
		z.type = 1;
		BT(N, now+1, arr, y, z);
	}
	else if(prev.x == 1){
		point y, z={0,0,0};
		z.type = 1;
		y.x = x.x;
		y.h = x.h+x.type;
		y.type = -x.type;
		BT(N, now+1, arr, y, z);
		
		y.x = x.x+1;
		y.h = x.h;
		z.type = 0;
		z.x = 1;
		BT(N, now+1, arr, y, z);		
	}
	else {
		point y,z={0,0,0};
		z.x = 1;
		y.x = x.x+1;
		y.h = x.h;
		y.type = -x.type;
		BT(N, now+1, arr, y, z);
		
		y.x = x.x-1;
		y.h = x.h;
		z.x = 0;
		z.h = 1;
		BT(N, now+1, arr, y, z);				
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	point arr[30] = {{0,0,1}, };
	point x = {0,1,-1};
	point prev = {0,0,1};
	BT(N+1, 1, arr, x, prev);
	printf("%d",ans);
}
