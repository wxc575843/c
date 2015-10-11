#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[105],d[105],cost[105][105],num[105],low[105];
int n,m,k;
const int MAXN=200;

int main(){
	while(scanf("%d%d",&n,&m)==2){
		for(int i=0;i<103;++i)
			for(int j=0;j<103;++j)
				cost[i][j]=MAXN;
		memset(vis,0,sizeof(vis));		
		for(int i=0;i<m;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			cost[x][y]=cost[y][x]=1;
		}

		for(int i=0;i<101;++i)
			d[i]=cost[1][i];
		d[1]=0;
		vis[1]=true;
		for(int i=1;i<=n;++i){
			int minn=MAXN+1;
			for(int j=1;j<=n;++j){
				if(!vis[k] && d[j]<minn)
					k=j;minn=d[j];
			}
			if(k==1) break;
			vis[k]=true;
			for(int j=1;j<=n;++j){
				if(!vis[j]){
					d[j]=min(d[j],cost[i][k]+cost[k][j]);
				}				
			}
		}
		int to,minn=MAXN+1;
		for(int i=2;i<=n;++i){
			if(minn>d[i]){
				to=i;
				minn=d[i];
			}
		}


		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
		vis[1]=true;
		for(int i=2;i<=n;++i)
			low[i]=cost[1][i];
		for(int i=2;i<=n;++i)
			if(d[i]==cost[1][i])
				num[i]=1;
		for(int i=2;i<=n;++i){
			int minn=MAXN+1;
			for(int j=2;j<=n;++j){
				if(!vis[j] && low[j]<minn)
                	minn=low[j];k=j;
            }
	        vis[k]=true;
	        for(int j=1;j<=n;++j){
	            if(!vis[j]){
	                low[j]=min(low[j],low[k]+cost[k][j]);
	            }
	            if(low[k]+cost[k][j]==d[j])
	                num[j]+=num[k];
	        }
        }

        if(to==n){
        	cout<<d[n]<<" "<<num[n]<<endl; 
        }
        else{
        	cout<<d[to]+1<<" "<<num[to]+1<<endl;
        }
    }
 	return 0;
}



