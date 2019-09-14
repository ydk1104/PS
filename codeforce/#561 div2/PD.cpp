#include<stdio.h>

int main(void){
	int q;
	scanf("%d", &q);
	while(q--){
		long long a, b, m;
		scanf("%lld %lld %lld", &a, &b, &m);
		if(a==b){
			printf("1 %lld\n", a);
			continue;
		}
		long long temp = a+1;
		long long cnt = 1;
		long long max = 1;
		long long ans[99] = {0,};
		ans[0] = a;
		ans[cnt++] = temp;
		while(temp<=b){
			if(cnt>50) break;
			if(temp+max*(m-1)>=b) goto v;
			temp*=2;
			max*=2;
			ans[cnt++]=temp;
		}
		printf("-1\n");
		continue;
		v:
//			for(int i=cnt-2; i>=0; i--) ans[i] = (ans[i+1])/2;
//			ans[cnt-1] = b;
			temp=b-temp;
			for(int i=cnt-1; i>0; i--) ans[i]+=temp, temp=(temp)/2;
			printf("%lld", cnt);
			long long sum[50]={0,};
			for(int i=0; i<cnt; i++){
				int j=i;
				while(j && sum[j-1]>=ans[j]){
					ans[--j]--;
					sum[j+1] = sum[j]+ans[j];
				}
				j=i;
				while(j && sum[j-1]+m<ans[j]){
					ans[--j]++;
					sum[j+1]=sum[j]+ans[j];
				}
				if(i) sum[i]=sum[i-1];
				sum[i]+=ans[i];
			}
			for(int i=0; i<cnt; i++) printf(" %lld",ans[i]);
			printf("\n");
	}
}
