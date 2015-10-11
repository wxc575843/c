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
int k;
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
char map[60][60];
struct Point{
	int x,y,k,s,h;
}start,endd;
double power[60][60];
bool operator<(const Point& x,const Point &y){
		return x.s>y.s;
}

double bfs(){
	priority_queue<Point> q;
	Point now,next;
	now.x=start.x;now.y=start.y;now.k=k;now.s=0.0,now.h=map[start.x][start.y]-'0';
	q.push(now);
	for(int i=0;i<60;++i)
		for(int j=0;j<60;++j)
			power[i][j]=1e8;
	power[start.x][start.y]=0.0;
	while(!q.empty()){
		now=q.top();
		q.pop();
		for(int i=0;i<4;++i){
			if(map[now.x+dx[i]][now.y+dy[i]]=='#')
				continue;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.k=now.k-1;
			if(next.k==0) continue;
			next.h=map[now.x+dx[i]][now.y+dy[i]];
			next.s=now.s+fabs((int)(map[now.x][now.y]-map[next.x][next.y]))/now.k;
			if(power[next.x][next.y]>next.s){
				power[next.x][next.y]=next.s;
				q.push(next);
			}
		}
		// cout<<"loop";
	}
	// cout<<"here"<<endl;
	if(power[endd.x][endd.y]<1e7)
		return power[endd.x][endd.y];
	else return -1; 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m>>k;
		memset(map,'#',sizeof(map));
		char tem[100];
		for(int i=0;i<n;++i){
			scanf("%s",tem);
			for(int j=0;j<m;++j){
				map[i+1][j+1]=tem[j];
			}
		}
			
		// Point start,end;
		cin>>start.x>>start.y>>endd.x>>endd.y;
		double ans=bfs();
		if(ans!=-1){
			cout<<ans<<endl;
		}
		else cout<<"No Answer"<<endl;
	}
	return 0;
}