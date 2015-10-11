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
long long pow2[32];
const long long M=1000000007;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

void init(){
	pow2[0]=1;
	for(int i=1;i<32;++i)
		pow2[i]=pow2[i-1]<<1;
}

int x[100005],y[100005],h[200005];
double sum[100005];

void build(){
	memset(sum,0,sizeof(sum));
}

void pushup(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void update(int l,int r,int a,int b,int rt){
	if(l>=a && r>=b){
		sum[rt]=(1-(1-sum[rt]/(h[r]-h[l]))*0.5)*(h[r]-h[l]);
		return;
	}
	int m=(a+b)>>1;
	if(l<=m)
		update(l,r,lson);
	if(r>m)
		update(l,r,rson);
	pushup(rt);
}


int main(){
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int k=0;
		for(int i=0;i<n;++i){
			int l,r;
			scanf("%d%d",&l,&r);
			x[i]=h[k++]=l;
			y[i]=h[k++]=r;
		}
		sort(h,h+n);
		int len=unique(h,h+n)-h;
		build();
		for(int i=0;i<n;++i){
			int pos1=lower_bound(h,h+len,x[i])-h;
			int pos2=lower_bound(h,h+len,y[i])-h;
			update(pos1+1,pos2+2,1,len-1,1);
		}
		if(n>31) n=31;
		cout<<(long long)sum[1]<<endl;
		// cout<<(long long)(floor(sum[1]*pow(2,n)))%M<<endl;
	}
	return 0;
}