#include<stdio.h>
#define min(a,b) (a>b) ? (b) : (a)

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void){
	int a, b, ta, tb;
	scanf("%d %d %d %d", &a, &b, &ta, &tb);
	if(a>b){
		swap(&a, &b);
		swap(&ta, &tb);
	}
	int ans1, ans2;
	ans1 = ans2 = 0;
	int i, j;
	i = j = 0;
	while(((i!=ta)||(j!=tb))&&(ans1<1000000)){
		if(j==b) j = 0;
		else if(i==0) i = a;
		else{
			j += i;
			i = 0;
			if(j>b){
				i = j-b;
				j = b;
			}
		}
		ans1++;
	}
	i = j = 0;
	while(((i!=ta) || (j!=tb)) && (ans2<1000000)){
		if(j==0) j = b;
		else if(i==a){
			i = 0;
		}
		else{
			i += j;
			j = 0;
			if(i>a){
				j = i-a;
				i = a;
			}
		}
		ans2++;
	}
	int ans = min(ans1, ans2);
	if((a == ta) && (b == tb)) ans = min(ans, 2);
	if(ans == 1000000) printf("-1");
	else printf("%d", ans);
}
