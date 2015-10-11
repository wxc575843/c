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
int s[105];
int sg[10005];
int k;;

int getSg(int n){
	if(sg[n]!=-1)
		return sg[n];
	int h[101]={0};
	for(int i=0;i<k;++i){
		int tem=n-s[i];
		if(tem<0) 
			break;
		sg[tem]=getSg(tem);
		h[sg[tem]]=1;
	}
	for(int i=0;;++i)
		if(!h[i])
			return i;
}

int main(){
	
	while(scanf("%d",&k),k){
		memset(sg,-1,sizeof(sg));
		sg[0]=0;
		for(int i=0;i<k;++i)
			scanf("%d",s+i);
		sort(s,s+k);
		int n;
		scanf("%d",&n);
		while(n--){
			int m;
			scanf("%d",&m);
			int ans=0;
			while(m--){
				int t;
				scanf("%d",&t);
				ans^=getSg(t);
			}
			if(!ans)
				printf("L");
			else printf("W");
		}
		printf("\n");
	}
	return 0;
}