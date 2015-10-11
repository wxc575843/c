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
int a[505];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		while(n--){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]+=y;
		}
		int sum=0;
		for(int i=0;i<500;++i){
			if(a[i]){
				sum+=ceil(a[i]*1.0/64);
				// cout<<"sum="<<sum<<endl;
			}
		}
		printf("%.0f\n",ceil(sum*1.0/36));
	}
	return 0;
}