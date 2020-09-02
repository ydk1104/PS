#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	int arr[7] = {1,0,1,0,0,1};
	while(T--){
		char a[10011] = {0, };
		scanf("%s", a);
		bool condition = true;
		int cnt = 0;
		bool check[26] = {0, };
		for(int i=0; i<6; ++i){
			condition &= arr[i] == (a[i] == a[i+1]);
			printf("%d %c %c\n", condition, a[i], a[i+1]);
		}
		for(int i=0; i<7; ++i){
			if(!check[arr[i] - 'A']){
				check[arr[i]-'A'] = true;
				cnt++;
			}
		}
		printf("%d\n", a[6] && !a[7] && condition && (cnt == 2));
	}
}
