#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	char name[20];
	int day;
	int month;
	int year;
}student;

int compare(const void *a, const void *b){
	student *p1 = (student*) a;
	student *p2 = (student*) b;
	if(p1->year > p2->year) return -1;
	if(p1->year == p2->year){
		if(p1->month > p2->month) return -1;
		if(p1->month == p2->month){
			if(p1->day > p2->day) return -1;
			if(p1->day == p2->day) return 0;
		}
	}
	return 1;
}

int main(void){
	int N;
	student a[100];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s %d %d %d", &a[i].name, &a[i].day, &a[i].month, &a[i].year);
	}
	qsort(a, N, sizeof(student), compare);
	printf("%s\n%s", a[0].name, a[N-1].name);
}
