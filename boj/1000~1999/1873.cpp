#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<std::pair<float, int> > v; // ÁÂÇ¥, type 

float line(int x1, int y1, int x2, int y2, int x, int y){
	if(x1==x2){
		if(x==-1) return x1;
		return y1;
	}
	float a = (float)(y2-y1)/(float)(x2-x1);
	float b = (float)y1;
	if(y==-1) return a * (x-x1) + b;
	else return (y-y1)/a+x1;
}

int main(void){
	long long x1,y1,x2,y2;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	if(x1==x2) y1=-1;
	else x1=-1;
	int N;
	scanf("%d", &N);
	long long x[2]={x1, x1}, y[2]={y1, y1};
	long long xf, yf;
	int ans=0, check=0, cf=0;
	float prev, pf;
	for(int i=0, n=0; i<=N; i++, n=1-n){
		if(i<N) scanf("%lld %lld", &x[n], &y[n]);
		else x[n] = xf, y[n] = yf, check=cf, prev=pf;
		if(!i){
			if(*x==x1 || *y==y1) cf=1, pf=(float)*x+*y-x1-y1-1, n=1-n, i--, N--;
			xf=*x, yf=*y;
		}
		else if(x[n] == x1 || y[n] == y1){
			check=1, prev=(float)x[n]+y[n]-x1-y1-1, n=1-n;
		}
		else if((x[n]-x1)*(x[1-n]-x1)<0 || (y[n]-y1)*(y[1-n]-y1)<0){
			ans++;
			if(check) v.push_back({prev, 0});
			else v.push_back({line(*x, *y, x[1], y[1], x1, y1), 0});
			check=0;
		}
		else{
			if(check) v.push_back({prev, 1});
			check=0;
		}
	}
	int cnt=0;
	std::sort(begin(v), end(v));
	for(auto &i:v){
//		printf("%lf %d\n", i.first, i.second);
		if(i.second) ans+=2*(cnt%2);
		else cnt++;
	}
	printf("%d",(ans+1)/2+1);
}
