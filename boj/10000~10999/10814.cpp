#include<stdio.h>

typedef struct id{
	int age;
	char name[101];
}id;

id a[100001];
id c[100001];

void sort(int start, int end){
	if(start == end){
		return;
	}
	int mid = (start + end) / 2;
	sort(start, mid), sort(mid+1, end);
	int left = start;
	int right = mid+1;
	int i = left;
	while(left<=mid && right<=end){
		if((a[left].age <= a[right].age) && (a[left].age != 0)){
			c[i] = a[left];
			left++;
			i++;
		}
		else{
			c[i] = a[right];
			right++;
			i++;
		}
	}
	while(left<=mid){
		c[i] = a[left];
		left++;
		i++;
	}
	while(right<=end){
		c[i] = a[right];
		right++;
		i++;
	}
	for(i=start; i<=end; i++){
		a[i] = c[i];
	}
	return;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i].age);
		scanf("%s", &a[i].name);
	}
	sort(0, N-1);
	for(int i=0; i<N; i++){
		printf("%d %s\n", a[i].age, a[i].name);
	}
}
