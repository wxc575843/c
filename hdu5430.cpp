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

int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt=1;
		for(int i=2;i<=n+1;++i){
			if(gcd(i,n+1)==1) ++cnt;
		}
		cout<<cnt<<endl;
	}	
	return 0;
}