#include<stdio.h>
#include<vector>
#include<algorithm>

typedef struct student{
	int score[3];
}stu;

std::vector<stu> v;

int main(void){
	int N;
	scanf("%d", &N);
	v.resize(N);
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			scanf("%d", &v[i].score[i]);
	std::sort(v.begin(), v.end(), [](const student &x, const student &y){
		return x.score[0] < y.score[0];
	});
	for(auto i:v){
		printf("%d %d %d\n", i.score[0], i.score[1], i.score[2]);
	}
}
