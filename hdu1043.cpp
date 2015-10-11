// poj 1077 八数码  暴力dfs＋map
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
map<string,string> h;
string target="123456789";
string node="12345678x";
char chessBoard[3][4]={"123","456","78x"};
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
string dest="udlr";
map<string,string>::iterator it;
void dfs(int x,int y,string path){
	for(int i=0;i<4;++i){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=0 && xx<3 && yy>=0 && yy<3){
			swap(chessBoard[x][y],chessBoard[xx][yy]);
			string tem;
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					tem+=chessBoard[i][j];
			if(h.find(tem)!=h.end()){
				swap(chessBoard[x][y],chessBoard[xx][yy]);
				continue;
			}
			h[tem]=path+dest[i];
			dfs(xx,yy,path+dest[i]);
			swap(chessBoard[x][y],chessBoard[xx][yy]);
		}
	}
}

int main(){
	dfs(2,2,"");
	while(cin>>target[0]){
		for(int i=0;i<8;++i)
			cin>>target[i+1];
		it=h.find(target);
		if(it!=h.end()){
			string ans=h[target];
			for(int i=ans.length()-1;i>=0;--i)
				cout<<ans[i];
			cout<<endl;
		}
		else cout<<"unsolvable"<<endl;
	}
	return 0;
}