#include<stdio.h>

struct bigint{
	char num[100001]={0,};
	void operator +=(bigint x){
		for(int i=0; x.num[i]; i++){
			if(!(this->num[i])) this->num[i] += '0';
			this->num[i] += x.num[i]-'0';
		}
		for(int i=0; this->num[i]; i++){
			int plus = (this->num[i]-'0')/10;
//			printf("test:%d %d\n",this->num[i], this->num[i]-'0');
			this->num[i]-=plus*10;
			if(plus && !this->num[i+1]) this->num[i+1]+='0';
			this->num[i+1]+=plus;
		}
	}
	void print(){
		int i=0, cnt=0;
		char temp[100001] = {0,};
		while(this->num[i]) i++;
		for(i--; i>=0; i--){
			temp[cnt++] = this->num[i];
		}
		printf("%s\n", this->num);
		printf("%s\n", temp);
	}
};

int main(void){
	bigint a, b;
	scanf("%s %s", &a.num, &b.num);
	a.print(); b.print();
	a += b;
	a.print();
}
