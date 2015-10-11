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
int d[1008];
bool vis[1008];
vector<int> g[1008];

bool judge(int n){
	bool flag=true;
	for(int i=2;i<=n;++i){
		if(d[i]!=1){
			flag=false;
			break;
		}
	}
	if(flag) return true;
	sort(d+1,d+n+1);
	for(int i=2;i<n;++i){
		if(d[i]==d[i+1])
			return false;
	}
	return true;
}

void bfs(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<g[now].size();++i){
			int next=g[now][i];
			if(vis[next]) continue;
			vis[next]=true;
			d[next]=d[now]+1;
			q.push(next);
		}
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<=n;++i) g[i].clear();
		for(int i=0;i<n-1;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		d[1]=0;
		vis[1]=true;
		bfs();
		if(judge(n))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
	return 0;
}