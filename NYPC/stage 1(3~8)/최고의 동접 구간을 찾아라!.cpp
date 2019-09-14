#include<stdio.h>

void timeprint(int time){
	int hour = time/60;
	int min = time%60;
	if(hour<10) printf("0");
	printf("%d:", hour);
	if(min<10) printf("0");
	printf("%d ", min);
}

int main(void){
	int N;
	int day[1440] = {0, };
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int hour, min;
		scanf("%d:%d", &hour, &min);
		day[hour*60+min]++;
		scanf("%d:%d", &hour, &min);
		day[hour*60+min]--;
	}
	int ans = 0;
	int now = 0;
	int ans_start = 0;
	int ans_end = -1;
	for(int i=0; i<1440; i++){
		now += day[i];
		if(now>ans){
			ans = now;
			ans_start = i;
		}
		if(now<ans && ans_end<ans_start) ans_end = i;
	}
	printf("%d\n", ans);
	timeprint(ans_start);
	timeprint(ans_end);
}
