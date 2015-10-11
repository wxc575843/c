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

bool eq(double x,double y){
	if(fabs(x-y)<1e-6)
		return true;
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<double> num;
		for(int i=0;i<n;++i){
			double tem;
			cin>>tem;
			num.push_back(tem);
		}
		if(n==2 && num[0]==0.0){
			puts("No");
			continue;
		}
		bool flag=true;
		for(int i=1;i<n-1;++i){
			if(num[i-1]*num[i+1]!=num[i]*num[i]){
				flag=false;
				break;
			}
		}
		puts(flag?"Yes":"No");
	}	
	return 0;
}