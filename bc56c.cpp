#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
// #include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int map[505][505];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&map[i][j]);
		while(q--){
			int op;
			scanf("%d",&op);
			if(op==1){
				int x,y,a,b;
				scanf("%d%d%d%d",&x,&y,&a,&b);
				int sum1=0,sum2=0;
				for(int i=x;i<=a;++i){
					for(int j=y;j<=b;++j){
						if(map[i][j]==1)
							++sum1;
						else if(map[i][j]>1)
							++sum2;
					}
				}
				if(sum1%2==0 && sum2%2==0)
					puts("No");
				else 
					puts("Yes");
			}
			else{
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				map[x][y]=z;
			}
		}
	}
	return 0;
}