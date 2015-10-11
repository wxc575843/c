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
map<int,vector<int> > h;
int a[100006];
const long long M=1000000007;
long long pow2(int x){
	long long ans=1,tem=2;
	while(x){
		if(x&1){
			ans=(ans*tem)%M;
		}
		tem=(tem*tem)%M;
		x>>=1;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		h.clear();
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			h[a[i]].push_back(a[i]);
		}
		long long ans=0;
		for(int i=0;i<n;++i){
			vector<int> &vec=h[a[i]];
			for(int j=1;j<vec.size();++j){
				int num=vec[j]-vec[j-1]-1;
				
			}
		}
	}
	return 0;
}