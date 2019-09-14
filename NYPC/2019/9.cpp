#include<stdio.h>
#include<algorithm>

int main(void){
   long long a,b;
   scanf("%lld %lld", &a, &b);
   long long ans=0;
 for(long long i=1; i*i<=b; i++){
      long long right = (b/i)*i;
      long long left = std::max( ((a-1)/i+1)*i, i*i);
//      printf("%d %d %d ", i, left, right);
      if(left==i*i && left <= right){
         ans++;
         left += i;
      }
      long long temp = (right-left)/i+1;
      ans += temp>0 ? temp*2 : 0;
//      printf("%d %d\n", ans, temp*2);
   }
   printf("%lld", ans);
}
