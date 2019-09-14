#include<stdio.h>
#include<stdlib.h>

typedef struct User{
	char team[5];
	int m;
	int s;
	int x;
	int time;
}User;

int compare(const void *pa, const void *pb){
	User *a = (User*) pa;
	User *b = (User*) pb;
	return a->time>b->time;
}

int main(void){
	int T;
	scanf("%d", &T);
	int score[8] = {10, 8, 6, 5, 4, 3, 2, 1};
	for(; T>0; T--){
		char s[10];
		User user[8]; 
		scanf("%s", &s);
		for(int i=0; i<8; i++){
			scanf("%s %d:%d.%d", &user[i].team, &user[i].m, &user[i].s, &user[i].x);
			user[i].time = user[i].m*6000 + user[i].s*100 + user[i].x;
		}
		qsort(user, 8, sizeof(User), compare);
//		printf("first = %d:%d.%d\n", user[0].time/6000, user[0].time/100, user[0].time%100);
		if(s[0] == 'i') printf("%s\n", user[0].team);
		else{
			int red_score=0, blue_score=0;
			for(int i=0; i<8; i++){
				if(user[i].time-user[0].time>1000) break;
				if(user[i].team[0] == 'r') red_score += score[i];
				else blue_score += score[i];
			}
			if(red_score==blue_score){
				printf("%s\n", user[0].team);
			}
			else if(red_score>blue_score) printf("red\n");
			else printf("blue\n");
//			printf("%d %d", red_score, blue_score);
		}
	}
	return 0;
}
