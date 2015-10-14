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
int TARGET;
const double MAXNLEN=1E30;

struct Point{
	double x,y;
	Point(int xx=0,int yy=0):x(xx),y(yy){}
	double length(const Point &r){
		return sqrt((r.x-x)*(r.x-x)+(r.y-y)*(r.y-y));
	}
};

struct Edge{
	int to;
	double len;
	Edge(int b=0,double c=0.0):to(b),len(c){}
};

void spfa(vector<int> *g,const vector<Point>& point,const vector<Edge>& edge,double *dist,int *pre){
	bool vis[1005];
	memset(vis,false,sizeof(vis));
	vis[0]=true;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int now=q.front();
		vis[now]=false;
		q.pop();
		for(int i=0;i<g[now].size();++i){
			const Edge &e=edge[g[now][i]];
			if(dist[e.to]>dist[now]+e.len){
				dist[e.to]=dist[now]+e.len;
				pre[e.to]=now;
				if(!vis[e.to]){
					vis[e.to]=true;
					q.push(e.to);
				}
			}
		}
	}
}

int main(int argc,char *argv[]){
	if(strcmp(argv[1],"Cities(144).txt")==0)
		TARGET=143;
	else TARGET=999;
	freopen(argv[1],"r",stdin);
	int a,b,c;
	double dist[1005];
	for(int i=0;i<1005;++i)
		dist[i]=MAXNLEN;
	dist[0]=0.0;
	int pre[1005];
	vector<int> g[1005];
	vector<Point> point;
	vector<Edge> edge;
	memset(pre,-1,sizeof(pre));
	while(~scanf("%d%d%d",&a,&b,&c)){
		point.push_back(Point(b,c));
	}
	fclose(stdin);
	freopen(argv[2],"r",stdin);
	while(~scanf("%d%d",&a,&b)){
		--a;--b;
		edge.push_back(Edge(b,point[a].length(point[b])));
		g[a].push_back(edge.size()-1);
		edge.push_back(Edge(a,point[a].length(point[b])));
		g[b].push_back(edge.size()-1);
	}
	fclose(stdin);
	spfa(g,point,edge,dist,pre);
	printf("Length:\t%f\n",dist[TARGET]);
	vector<int> path;
	while(pre[TARGET]!=-1){
		path.push_back(TARGET);
		TARGET=pre[TARGET];
	}
	for(int i=path.size()-1;i>=0;--i)
		printf("%d\t",path[i]);
	printf("\n");
	// for(int i=0;i<100;++i)
	// 	printf("%lf\n",dist[i]);
	return 0;
}