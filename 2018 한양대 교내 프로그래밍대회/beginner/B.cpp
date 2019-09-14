#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

class users{
	public:
		char username[20];
		int distance;
		bool FM[5] = {false, };
		void scan(){
			scanf("%s", &username);
			char temp[5];
			scanf("%s", &temp);
			for(int i=0; i<strlen(temp); i++){
				check(temp[i]);
			}
			scanf("%d", &distance);
			return;
		}
		void test(int i){
			strcpy(username, "AliceAlice");
			username[0] = i%26 + 'A';
			FM[0] = 1;
			distance = 20;
			return;
		}
		int print(users x, int flag){
			if(distance > x.distance) return 0;
			if((FM[0] && x.FM[0]) || (FM[1] && x.FM[1])){
				if(flag) printf("\n");
				printf("%s",username);
				return 1;
			}
			return 0;
		}
		bool operator <(users &x){
			int temp = strcmp(x.username, this->username);
			if(temp<0) temp=0;
			return temp;
		}
	private:
		void check(char x){
			if(x == 'F') FM[0] = true;
			else if (x == 'M') FM[1] = true;
			return;
		}
};

users user[100005];

int main(void){
	users tar;
	tar.scan();
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		user[i].scan();
	}
	sort(user, user+N);
	int flag = 0;
	for(int i=0; i<N; i++){
		int temp = user[i].print(tar, flag);
//		printf("\ntest // %s\n", user[i].username);
		flag += temp;
	}
	if(!flag) printf("No one yet");
	return 0;
}
