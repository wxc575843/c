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
char map[205][205];
int n,m;
char tem[208];
struct P{
	int x,y;
}start,endp;
int step[205][205];
const int INF=1e9;
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};

void bfs(){
	for(int i=0;i<205;++i)
		for(int j=0;j<205;++j)
			step[i][j]=INF;
	step[start.x][start.y]=0;
	queue<P> q;
	q.push(start);
	while(!q.empty()){
		P now=q.front(),next;
		q.pop();
		for(int i=0;i<4;++i){
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(map[next.x][next.y]!='#'){
				int tmp=step[now.x][now.y]+1;
				if(map[next.x][next.y]=='X')
					tmp++;
				if(tmp<step[next.x][next.y]){
					step[next.x][next.y]=tmp;
					q.push(next);
				}
			}
		}
	}
}

int main(){
	while(cin>>n>>m){
		memset(map,'#',sizeof(map));
		for(int i=0;i<n;++i){
			scanf("%s",tem);
			for(int j=0;j<m;++j){
				map[i+1][j+1]=tem[j];
				if(tem[j]=='S'){
					start.x=i+1;
					start.y=j+1;
				}
				if(tem[j]=='T'){
					endp.x=i+1;
					endp.y=j+1;
				}
			}
		}
		bfs();
		if(step[endp.x][endp.y]==INF)
			puts("impossible");
		else{
			printf("%d\n",step[endp.x][endp.y]);
		}
	}
	return 0;
}