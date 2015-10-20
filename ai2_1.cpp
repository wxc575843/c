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
#include <ctime>
using namespace std;
const int TARGET=999;
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

vector<int> g[1005];
vector<Point> point;
vector<Edge> edge;
double dist[1005];
int pre[1005];

void spfa(){
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
struct cmp{
	bool operator()(const int &x,const int &y){
		return dist[x]+point[x].length(point[TARGET])<dist[y]+point[y].length(point[TARGET]);
	}
};

void astar(){
	bool vis[1005];
	memset(vis,false,sizeof(vis));
	vis[0]=true;
	priority_queue<int,vector<int>,cmp> q;
	q.push(0);
	while(!q.empty()){
		int now=q.top();
		q.pop();
		// if(now==TARGET)
		// 	break;
		for(int i=0;i<g[now].size();++i){
			const Edge &e=edge[g[now][i]];
			if(dist[e.to]>dist[now]+e.len){
				dist[e.to]=dist[now]+e.len;
				pre[e.to]=now;
				vis[e.to]=true;
					q.push(e.to);
			}
		}
	}
}

int main(int argc,char *argv[]){
	freopen("/users/fangpin/Documents/programs/c/Cities(1000).txt","r",stdin);
	int a,b,c;
	double x,y;	
	for(int i=0;i<1005;++i)
		dist[i]=MAXNLEN;
	dist[0]=0.0;
	memset(pre,-1,sizeof(pre));
	while(~scanf("%d%lf%lf",&a,&x,&y))
		point.push_back(Point(x,y));
	fclose(stdin);
	freopen("/users/fangpin/Documents/programs/c/Cities(1000)link.txt","r",stdin);
	while(~scanf("%d%d",&a,&b)){
		--a;--b;
		edge.push_back(Edge(b,point[a].length(point[b])));
		g[a].push_back(edge.size()-1);
		edge.push_back(Edge(a,point[a].length(point[b])));
		g[b].push_back(edge.size()-1);
	}
	fclose(stdin);

	int t1=clock();
 	spfa();
	printf("spfa shortest length:\t%f\n",dist[TARGET]);
	vector<int> path;
	int target=TARGET;
	while(pre[target]!=-1){
		path.push_back(target);
		target=pre[target];
	}
	path.push_back(0);
	for(int i=path.size()-1;i>=0;--i)
		printf("%d\t",path[i]+1);
	printf("\n");
	int t2=clock();
	printf("Spfa costs %fs\n",1.0*(t2-t1)/CLOCKS_PER_SEC);

	path.clear();
	for(int i=0;i<1005;++i)
		dist[i]=MAXNLEN;
	dist[0]=0.0;
	memset(pre,-1,sizeof(pre));
	t1=clock();
	astar();
	printf("Astar shortest length:\t%f\n",dist[TARGET]);
	target=TARGET;
	while(pre[target]!=-1){
		path.push_back(target);
		target=pre[target];
	}
	path.push_back(0);
	for(int i=path.size()-1;i>=0;--i)
		printf("%d\t",path[i]+1);
	printf("\n");
	t2=clock();
	printf("A* costs %fs\n",1.0*(t2-t1)/CLOCKS_PER_SEC);
	return 0;
}