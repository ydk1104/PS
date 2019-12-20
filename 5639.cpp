#include<stdio.h>
#include<stack>

std::stack<int> s;

int main(void){
	int x;
	scanf("%d", &x);
	s.push(x);
	int max = 100000;
	while(~scanf("%d", &x)){
		if(s.top() > x){
			s.push(x);
			max = x;
		}
		if(x < max){
			printf("%d\n", s.top()); s.pop();
		}
		else if(s.top() < x){
			s.push(x);
		}
		printf("%d")
	}
	while(!s.empty()){
		printf("out : ");
		printf("%d\n", s.top()); s.pop();
	}
}
