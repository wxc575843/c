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
int a[200];

int main(){
	int n;
	while(scanf("%d",&n),n){
		int sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",a+i);
			sum^=a[i];
		}
		if(!sum){
			cout<<"0"<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<n;++i){
			if((a[i]^sum)<a[i])
				++ans;
		}
		cout<<ans<<endl;
	}	
	return 0;
}