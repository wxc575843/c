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
#include <string>
using namespace std;

struct P{
	string name,age;
}p[105];

bool cmp(const P &x,const P &y){
	return  x.age>y.age;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		getchar();
		for(int i=0;i<n;++i){
			string tem;
			getline(cin,tem);
			p[i].name=tem.substr(0,tem.length()-5);
			p[i].age=tem.substr(tem.length()-4,4);
		}
		sort(p,p+n,cmp);
		for(int i=0;i<n;++i)
			cout<<p[i].name<<endl;
	}
	return 0;
}