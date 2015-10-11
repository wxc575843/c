//poj1077 八数码  A*
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
int fac[13];//预处理阶乘
bool h[1000000];//hash

char toCompare[3][4]={"123","456","78x"};//目标矩阵
struct Node{
	char b[3][3];//棋盘board状态
	int deep,dif;//深度g和不在位数h，f=g+h为启发函数
	int x,y,canton;//x的期盼位置，和当前状态康托展开hash值
	string ans;//path
	Node(){
		deep=dif=x=y=canton=0;
		ans.clear();
		memset(b,0,sizeof(b));
	}
	Node(const Node &r){
		*this=r;
	}
	Node& operator=(const Node &r){
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				b[i][j]=r.b[i][j];
		deep=r.deep;
		dif=r.dif;
		ans=r.ans;
		x=r.x;
		y=r.y;
		canton=r.canton;
		return *this;
	}
	//四种移动
	bool left(){
		if(y==0) return false;
		swap(b[x][y],b[x][y-1]);
		--y;
		ans+='l';
		countDif();
		getCanton();
		++deep;
		return true;
	}
	bool right(){
		if(y==2) return false;
		swap(b[x][y],b[x][y+1]);
		++y;
		ans+='r';
		countDif();
		getCanton();
		++deep;
		return true;
	}
	bool up(){
		if(x==0) return false;
		swap(b[x][y],b[x-1][y]);
		--x;
		ans+='u';
		countDif();
		getCanton();
		++deep;
		return true;
	}
	bool down(){
		if(x==2) return false;
		swap(b[x][y],b[x+1][y]);
		++x;
		ans+='d';
		countDif();
		getCanton();
		++deep;
		return true;
	}
	// 计算不在位奖牌数
	void countDif(){
		dif=0;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(b[i][j]!=toCompare[i][j])
					++dif;
	}
// 利用康托展开作为hash函数判重
	void getCanton(){
		int num[9];
		canton=0;
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				if(b[i][j]=='x'){
					num[i*3+j]=9;
				}
				else{
					num[i*3+j]=b[i][j]-'0';
				}
			}
		}
		for(int i=0;i<9;++i){
			int sum=0;
			for(int j=i-1;j>=0;--j){
				if(num[j]<num[i])
					++sum;
			}
			canton+=(num[i]-1-sum)*fac[8-i];
		}
	}
	//重载篇序符，维护f排序的priority_queen
	friend bool operator<(const Node& l,const Node& r){
		return l.deep+l.dif>r.deep+r.dif;
	}
}now;

string bfs(){
	priority_queue<Node> q;
	q.push(now);
	while(!q.empty()){
		now=q.top();
		if(now.dif==0)
			return now.ans;
		q.pop();
		Node next[4]={now,now,now,now};
		if(next[0].down() && !h[next[0].canton]){
			h[next[0].canton]=true;
			q.push(next[0]);
		}
		if(next[1].left() && !h[next[1].canton] ){
			h[next[1].canton]=true;
			q.push(next[1]);
		}
		if(next[2].right() && !h[next[2].canton]){
			h[next[2].canton]=true;
			q.push(next[2]);
		}
		if(next[3].up() && !h[next[3].canton]){
			h[next[3].canton]=true;
			q.push(next[3]);
		}
	}
	return "unsolvable";
}

int main(){
	// 预处理阶乘
	fac[0]=1;
	for(int i=1;i<=9;++i)
		fac[i]=fac[i-1]*i;
	memset(h,false,sizeof(h));
	int t;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			cin>>now.b[i][j];
			if(now.b[i][j]=='x'){
				now.x=i;
				now.y=j;
			}
		}
	}
	now.countDif();
	now.getCanton();
	h[now.canton]=true;
	string output=bfs();
	// if(output.empty())
	// 	output="unsolvable";
	cout<<output<<endl;
	return 0;
}