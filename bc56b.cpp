#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[1005];
int p,n;
const int M=1000000007;
int dp[1005][1005];//前i个数构成和为j的方案数
// int ans[100][1005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		// memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		scanf("%d",&p);
		for(int i=1;i<=n;++i){
			cin>>a[i];
			a[i]%=p;
		}
		// sort(a,a+n);
		dp[0][0]=1;
		for(int i=1;i<=n;++i){
			for(int j=0;j<p;++j){
				dp[i][j]=dp[i-1][j];
			}
			for(int j=0;j<p;++j){
				// int &tem=dp[i][(j+a[i])%p];
				// ++tem;
				// tem%=M;
				dp[i][j]=(dp[i][j]+dp[i-1][(j+p-a[i])%p])%M;
			}
			
		}
		cout<<dp[n][0]<<endl;
	}
	return 0;
}