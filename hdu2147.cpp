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
int n,m,dp[2005][2006];
int judge(int row,int col){
	if(dp[row][col]!=-1)
		return dp[row][col];
	int flag1=0,flag2=0,flag3=0;
	if(row<n)
		flag1=judge(row+1,col);
	if(col<m)
		flag2=judge(row,col+1);
	if(row<n && col<m)
		flag3=judge(row+1,col+1);
	// int final;
	if(row==n){
		return dp[row][col]=flag2;
	}
	else if(col==m){
		return dp[row][col]=flag1;
	}
	if(flag1 && flag2 && flag3)
		return dp[row][col]=0;
	if(!flag1 || !flag2 || !flag3)
		return dp[row][col]=1;
}


int main(){
	while(cin>>n>>m,n+m){
		--n;--m;
		memset(dp,-1,sizeof(dp));
		dp[n][m]=0;
		if(!judge(0,0))
			puts("What a pity!");
		else puts("Wonderful!");
	}
	return 0;
}