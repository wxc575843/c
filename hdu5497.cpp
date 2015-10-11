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
int c[100006],n,m,g[100006],h[100006],data[100006];
void add(int *a,int pos,int val){
	for(int i=pos;i<=n;i+=i&-i)
		a[i]+=val;
}
int sum(int *a,int pos){
	int ans=0;
	for(int i=pos;i;i-=i&-i)
		ans+=a[i];
	return ans;
}
int query(int *a,int l,int r){
	return sum(a,r)-sum(a,l-1);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		memset(g,0,sizeof(g));
		memset(h,0,sizeof(h));
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d",data+i);
			int sum=query(c,data[i]+1,n);
			ans+=sum;
			add(c,data[i],1);
			add(g,i,sum);
		}
		memset(c,0,sizeof(c));
		for(int i=n;i>=1;--i){
			int sum=query(c,1,data[i]-1);
			add(h,i,sum);
		}
		memset(c,0,sizeof(c));
		int num=0;
		int tem=ans-(query(g,1,m)+query(h,1,m)-num);
		for(int i=2;i<=n-m+1;++i){
			num=
			int cnt=ans-query(g,i,i+m-1)-query(h,i,i+m-1)+num;
		}
	}
	return 0;
}