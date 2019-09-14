#include<stdio.h>
#include<math.h>

int main(void){
	int T;
	scanf("%d", &T);
	for (int ii=1; ii<=T; ii++){
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		float d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
		d = sqrt(d);
		if (d==0){
			if(r1==r2){
				printf("-1\n");
			}
			else{
				printf("0\n");
			}
		}
		else{
			if(d>r1+r2){
				printf("0\n");
			}
			else if(d==r1+r2){
				printf("1\n");
			}
			else{
				if(r1>r2){
					int temp = r1;
					r1 = r2;
					r2 = r1;
				}
				if(d<r2-r1){
					printf("0\n");
				}
				else if (d==r2-r1){
					printf("1\n");
				}
				else{
					printf("2\n");
				}
			}
		}
	}
// */
}
