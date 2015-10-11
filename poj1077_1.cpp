// poj 1077 八数码  IDA*
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
char toCompare[3][4]={"123","456","789"};
char chessBoard[3][4];
bool ok=false;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
const int MAXN=9*8*7*6*5*4*3*2+2;
bool h[MAXN];
int fac[10],x,y;
string dest="udlr";

// 预处理阶乘
void getFac(){
	fac[0]=1;
	for(int i=1;i<10;++i)
		fac[i]=fac[i-1]*i;
}

// 利用康托展开hash全排列，返回康托展开的值
int getCanton(){
	int a[9];
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			a[i*3+j]=chessBoard[i][j]-'0';
	int canton=0;
	for(int i=0;i<9;++i){
		int cnt=0;
		for(int j=i+1;j<9;++j){
			if(a[i]>a[j])
				++cnt;//逆序值
		}
		canton+=cnt*fac[8-i];
	}
	return canton;
}

int countDif(){
	int cnt=0;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(toCompare[i][j]!=chessBoard[i][j])
				++cnt;
		}
	}
	return cnt;
}

// 迭代加深搜索
void dfs(int deep,int limit,string path){
	if(deep>limit || ok || countDif()+deep>limit)
		return;
	int canton=getCanton();
	if(!canton){//目标状态canton值为0
		ok=true;
		cout<<path<<endl;
		return;
	}
	for(int i=0;i<4;++i){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=0 && xx<3 && yy>=0 && yy<3){
			swap(chessBoard[xx][yy],chessBoard[x][y]);
			int canton=getCanton();
			if(!h[canton]){
				h[canton]=true;
				x+=dx[i];
				y+=dy[i];
				dfs(deep+1,limit,path+dest[i]);
				x-=dx[i];
				y-=dy[i];
			}
			swap(chessBoard[xx][yy],chessBoard[x][y]);
		}
	}
}

int main(){
	getFac();
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			cin>>chessBoard[i][j];
			if(chessBoard[i][j]=='x'){
				chessBoard[i][j]='9';
				x=i;
				y=j;
			}
		}
	}
	if(getCanton()==0){
		cout<<"unsolvable"<<endl;
		return 0;
	}
	int limit=1;//迭代加深
	for(;limit<100;++limit){
		ok=false;
		memset(h,false,sizeof(h));
		string path;
		dfs(0,limit,path);
		if(ok)
			break;
	}
	if(!ok)
		cout<<"unsolvable"<<endl;
	return 0;
}