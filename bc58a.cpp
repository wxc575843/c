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
int a[600],b[600];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int suma=0,sumb=0;
		for(int i=0;i<m;++i)
			suma+=a[i];
		for(int i=n-1;i>=n-m;--i)
			sumb+=b[i];
		if(suma>sumb)
			puts("YES");
		else puts("NO");
	}
	return 0;
}