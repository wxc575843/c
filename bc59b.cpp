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
struct Node{
	vector<int> a;
	long long cnt,step;
	Node(int len=19){
		a.resize(len);
		cnt=0;
		step=0;
	}
	Node(const vector<int> &r){
		a=r;
		cnt=0;
	}
	Node &operator=(const Node &r){
		a=r.a;
		cnt=r.cnt;
		step=r.step;
		return *this;
	}
	Node(const Node &r){
		*this=r;
	}
	void setCnt(){
		for(int i=0;i<a.size();++i){
			for(int j=i+1;j<a.size();++j){
				if(a[i]>a[j])
					++cnt;
			}
		}
	}
}now,nex,tocmp;

bool equal(const Node &x,const Node &y){
	if(x.cnt!=y.cnt)
		return false;
	return x.a==y.a;
}

bool operator<(const Node& x,const Node& y){
	return x.step+x.cnt>y.step+y.cnt;
}

vector<int> vec;

long long bfs(int n){
	now=vec;
	now.step=0;
	now.setCnt();
	priority_queue<Node> q;
	q.push(now);
	while(!q.empty()){
		now=q.top();
		q.pop();
		if(equal(now,tocmp))
			return now.step;
		for(int i=1;i<n;++i){
			nex=now;
			int tem=now.a[i];
			for(int j=i-1;j>=0;--j){
				nex.a[j+1]=nex.a[j];
			}
			nex.a[0]=tem;
			nex.step++;
			nex.setCnt();
			// if(nex.cnt+nex.step<now.cnt+now.step)
			q.push(nex);
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		vec.clear();
		tocmp.a.clear();
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			tocmp.a.push_back(i+1);
		for(int i=0;i<n;++i){
			int tem;
			scanf("%d",&tem);
			vec.push_back(tem);
		}
		cout<<bfs(n)<<endl;
	}	
	return 0;
}