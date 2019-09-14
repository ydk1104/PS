#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct xyz{
	int x, y, z, cnt;
	xyz(int a, int b, int c, int d){
		x=a, y=b, z=c, cnt=d;
	}
};

vector<int[7][7]> map(7);

void test_print(){
	printf("test_start\n");
	for(int i=1; i<6; i++){
		for(int j=1; j<6; j++){
			for(int k=1; k<6; k++){
				printf("%d ", map[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("test_end\n");
}

bool cmp(int a[][7], int b[][7]){
	return a[0][0] < b[0][0];
}

void rotate(int x){
	int v[7][7];
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			v[i][j] = map[x][6-j][i];
		}
	}
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			map[x][i][j] = v[i][j];
		}
	}
}

int ans=-1;

int min(int a, int b){
	if(a==-1) return b;
	return a>b?b:a;
}

void BFS(){
	if(!map[1][1][1]) return;
	int cnt[7][7][7] = {0, };
	cnt[1][1][1] = 1;
	xyz T(1, 1, 1, 0);
	queue<xyz> Q;
	Q.push(T);
	while(!Q.empty()){
		xyz temp = Q.front(); Q.pop();
		if(temp.x==5 && temp.y==5 && temp.z==5){
			ans=min(ans, temp.cnt);
//			if(temp.cnt==16) test_print();
			return;
		}
		int dx[] = {1, -1, 0, 0, 0, 0};
		int dy[] = {0, 0, 1, -1, 0, 0};
		int dz[] = {0, 0, 0, 0, 1, -1};
		for(int i=0; i<6; i++){
			int nowx = temp.x + dx[i];
			int nowy = temp.y + dy[i];
			int nowz = temp.z + dz[i];
			if(nowx<1 || nowy<1 || nowz<1) continue;
			if(nowx>5 || nowy>5 || nowz>5) continue;
			if(!map[nowx][nowy][nowz]) continue;
			if(cnt[nowx][nowy][nowz]) continue;
			cnt[nowx][nowy][nowz] = temp.cnt+1;
			xyz T(nowx, nowy, nowz, temp.cnt+1);
			Q.push(T);
		}
	}
	while(!Q.empty()) Q.pop();
}

int main(void){
	test_print();
	for(int i=1; i<6; i++){
		for(int j=1; j<6; j++){
			for(int k=1; k<6; k++){
				scanf("%d", &map[i][j][k]);
//				map[i][j][k] = i*25+j*5+k-30;
			}
		}
		map[i][0][0] += i*25;
		map[i][6][0] += i*25;
		map[i][0][6] += i*25;
		map[i][6][6] += i*25;
	}
	for(int i=5; i<=3125*5; i+=5){
		int temp = i, cnt=5;
		while(temp>0){
			if(temp%5!=0) break;
			rotate(cnt);
			temp/=5;
			cnt--;
		}
//		test_print();
		do{
			BFS();
		}while(next_permutation(map.begin()+1, map.end()-1, cmp));
	}
	printf("%d", ans);
}
