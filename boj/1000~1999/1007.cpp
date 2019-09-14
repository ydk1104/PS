#include<stdio.h>
#include<math.h>

class Point{
	public:
	double x;
	double y;
	void print(){
		printf("%lf", sqrt(x*x + y*y));
	}
};

Point point[21];

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%lf %lf", &point[i].x, point[i].y);
		
	}
	Point x;
	scanf("%lf %lf", &x.x, &x.y);
	x.print();
}
