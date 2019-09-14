#include<stdio.h>

int set[21];

void add(int x){scanf("%d",&x);set[x]=1;}
void remove(int x){scanf("%d",&x);set[x]=0;}
bool check(int x){scanf("%d",&x);return set[x];}
void toggle(int x){scanf("%d",&x);set[x]=1-set[x];}
void all(){for(int i=1; i<=20; i++) set[i]=1;}
void empty(){for(int i=1; i<=20; i++) set[i]=0;}

int main(void){
	int M;
	scanf("%d", &M);
	while(M--){
		getchar();
		char s[10];
		scanf("%s", &s);
		if(s[0]=='a'){
			if(s[1]=='d') add(0);
			else all();
		}
		if(s[0]=='c') printf("%d\n", check(0));
		if(s[0]=='t') toggle(0);
		if(s[0]=='r') remove(0);
		if(s[0]=='e') empty();
	}
}
