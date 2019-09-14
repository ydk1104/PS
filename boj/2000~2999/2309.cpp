#include<stdio.h>

int main(void){
	int key[10] = {0, };
	for(int i=1; i<=9; i++){
		scanf("%d", &key[i]);
		key[0] += key[i];
	}
	for(int i=1; i<=9; i++){
		for(int j=i+1; j<=9; j++){
			if(key[0] - key[i] - key[j] == 100){
				key[i] = 0;
				key[j] = 0;
				key[0] = 0;
				for(int i=0; i<=9; i++){
					for(int j=i+1; j<=9; j++){
						if(key[i] > key[j]){
							int temp = key[i];
							key[i] = key[j];
							key[j] = temp;
						}
					}
					if(i>2){
						printf("%d\n", key[i]);						
					}
				}
			}
		}
	}
}
