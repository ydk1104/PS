#include<stdio.h>
#include<vector>
#include<tuple>
#include<algorithm>

int matrix[101][101];
int r, c, k;
int row, col, check;
int cnt[101];

void operation(){
	int max=0;
	for(int i=0; i<row; i++){
		for(int j=0; j<101; j++) cnt[j] = 0;
		for(int j=0; j<col; j++) cnt[matrix[i][j]]++;
		std::vector<std::pair<int, int> > v;
		for(int j=1; j<101; j++){
			if(cnt[j]) v.push_back(std::make_pair(cnt[j], j));
		}
		std::sort(v.begin(), v.end());
		int cnt=0;
		for(auto j:v){
			matrix[i][cnt++] = j.second;
			matrix[i][cnt++] = j.first;
			if(cnt>100) break;
		}
		while(cnt<col) matrix[i][cnt++] = 0;
		if(max<cnt) max=cnt;
	}
	if(col<max) col=max;
}

void rotate(){
	int temp[101][101];
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			temp[j][i] = matrix[i][j];
			matrix[i][j] = 0;
		}
	}
	for(int i=0; i<col; i++){
		for(int j=0; j<row; j++){
			matrix[i][j] = temp[i][j];
		}
	}
	**temp = row;
	row = col;
	col = **temp;
	**temp = r;
	r = c;
	c = **temp;
	check = 1-check;
}

void test_print(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void){
	scanf("%d %d %d", &r, &c, &k);
	row=3, col=3;
	r--, c--;
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			scanf("%d", &matrix[i][j]);
	for(int t=0; t<=101; t++){
		if(matrix[r][c] == k){
			printf("%d",t);
			goto v;
		}
		operation();
//		printf("%d\n",t);
//		test_print();
		if(row<col) rotate();
		if(check && row==col) rotate();
//		test_print();
	}
	printf("-1");
	v:;
}
