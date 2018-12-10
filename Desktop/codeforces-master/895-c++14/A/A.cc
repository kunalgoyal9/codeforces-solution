#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string.h>
using namespace std;
const int MOD=1e9+7;
int num[75];
long long dp[1<<22],tmp[1<<22];
int prime[75],id[75];
int main(){
	int n,i,j,a,ps=0,pw[110000]={1};
	for(i=2;i<=70;i++){
		if(prime[i]==1)continue;
		id[i]=ps++;
		for(j=2;i*j<=70;j++){
			prime[i*j]=1;
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)pw[i]=(pw[i-1]*2)%MOD;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		num[a]++;
	}
	dp[0]=1;
	//long long ans=0;
	for(i=1;i<=70;i++){
		if(num[i]==0)continue;
		int bit=0,i2=i;
		j=2;
		while(j<=i2){
			if(i2%j==0){
				bit^=1<<id[j];
				i2/=j;
			}
			else j++;
		}
		int even=pw[num[i]-1]-1,odd=pw[num[i]-1];
		//ans=(ans+dp[0]*odd+dp[bit]*even)%MOD;
		memcpy(tmp,dp,sizeof(dp));
		for(j=0;j<(1<<20);j++){
			tmp[j^bit]=(tmp[j^bit]+odd*dp[j])%MOD;
			tmp[j]=(tmp[j]+even*dp[j])%MOD;
		}
		memcpy(dp,tmp,sizeof(tmp));
	}
	printf("%lld\n",dp[0]-1);
    return 0;
}
