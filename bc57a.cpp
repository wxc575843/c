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
char s[1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		int pos=0;
		while(s[pos]==')')
			++pos;
		int cnt=0;
		for(;pos<len;++pos)
			if(s[pos]==')')
				++cnt;
		cout<<cnt<<endl;
	}
	return 0;
}