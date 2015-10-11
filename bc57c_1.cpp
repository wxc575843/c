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
double c[100005];
int lowbit(int x){
	return x&(-x);
}

int sum(int i){
	int ans=0;
	while(i){
		ans+=c[i];
		i-=lowbit(i);
	}
	return ans;
}

void add(int )

int main(){
	
	return 0;
}