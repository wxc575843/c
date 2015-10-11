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
int a[100006];
long long pw[100006]={1,2};
map<int,long long> h;
const long long M=1000000007;

int main(){
	int t;
	cin>>t;
	for(int i=2;i<100006;++i)
		pw[i]=(pw[i-1]<<1)%M;
	while(t--){
		int n;
		cin>>n;
		h.clear();
		long ans=0,sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			sum=(ans+a[i]*pw[i]%M-h[a[i]]*a[i]%M+M)%M;
			ans=(ans+sum)%M;
			h[a[i]]=(h[a[i]]+pw[i])%M;
		}
		cout<<ans<<endl;
	}	
	return 0;
}