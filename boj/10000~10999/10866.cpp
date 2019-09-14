#include<stdio.h>
#include<string.h>

int deck[30000];
int start = 15000;
int end = 15001;

int size(void){
	return end-start-1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		char s[15];
		scanf("%s", &s);
		if(strcmp(s, "push_back") == 0){
			int temp;
			scanf("%d", &temp);
			deck[end] = temp;
			end++;
		}
		if(strcmp(s, "push_front") == 0){
			int temp;
			scanf("%d", &temp);
			deck[start] = temp;
			start--;
		}
		if(strcmp(s, "pop_front") == 0){
			if(size() != 0){
				start++;
				printf("%d\n", deck[start]);
				deck[start] = 0;
			}
			else{
				printf("-1\n");
			}
		}
		if(strcmp(s, "pop_back") == 0){
			if(size() != 0){
				end--;
				printf("%d\n", deck[end]);
				deck[end] = 0;
			}
			else{
				printf("-1\n");
			}
		}
		if(strcmp(s, "size") == 0){
			printf("%d\n", size());
		}
		if(strcmp(s, "empty") == 0){
			if(size() == 0){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		if(strcmp(s, "front") == 0){
			if(deck[start+1] == 0){
				printf("-1\n");
			}
			else{
				printf("%d\n", deck[start+1]);
			}
		}
		if(strcmp(s, "back") == 0){
			if(deck[end-1] == 0){
				printf("-1\n");
			}
			else{
				printf("%d\n", deck[end-1]);
			}
		}
	}
}
