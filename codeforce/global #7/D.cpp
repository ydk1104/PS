#include<stdio.h>
#include<string>

char s[1000011];

const bool Debug = true;

std::string find1(int l, int r){
//	printf("find : ");
//	for(int i=l; i<r; i++) printf("%c", s[i]);
	
	
	int ans = 0;
	for(int len=1; len<r-l+1; len++){
		for(int i=0; i<len; i++){
			if(s[r -len+i] != s[r-1-i]) goto w;
		}
		ans = len;
		w:;
		
		for(int i=0; i<len; i++){
			if(s[l+i] != s[l+len-1-i]) goto ww;
		}
		ans = -len;
		ww:;
	}
//	printf("\n");
//	printf("ans : ");
	std::string temp;
	if(ans >= 0) for(int i=r-ans; i<r; i++) temp += s[i];
	else for(int i=l; i<l-ans; i++) temp += s[i];
//	printf("Debug : %s\n", temp.c_str());
//	printf("\n");
	return temp;
}

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		scanf("%s", &s);
		int len = 0;
		while(s[len]) len++;
		std::string temp = "";
		std::string ans;
		for(int i=0; i<=len; i++){

			int j;
			for(j=0; temp[j]; j++){
				if(s[len-1 -j] != temp[j]) goto v;
			}
				{
				std::string nowmax = temp + find1(i, len -j) + std::string(temp.rbegin(), temp.rend());
				if(nowmax.size() > ans.size()) ans = nowmax;
				}
			
			v:;
			temp += s[i];
		}
		printf("%s\n", ans.c_str());
	}
}
