#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){
	int a[3];
	for(int i=0; i<3; i++) scanf("%d", &a[i]);
	sort(a, a+3);
	char s[4];
	scanf("%s", &s);
	for(int i=0; i<3; i++) printf("%d ", a[s[i]-'A']);
}
