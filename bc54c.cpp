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
struct Num{
	int a[10005],digit;
	Num(string tem){
		memset(a,0,sizeof(0));
		digit=tem.length();
		for(int i=0,len=tem.length();i<len;++i){
			a[i]=tem[i]-'0';
		}
	}
	Num& operator=(const Num &r){
		copy(r.a,r.a+r.digit,a);
		return *this;
	}
	friend Num operator*(const Num x,const Num y){
		Num ans("0");
		for(int i=0;i<100;++i){
			for(int j=0;j<100;++j){
				ans.a[i+j]+=ans.a[i]*ans.a[j];
			}
		}
		for(int i=0;i<10004;++i){
			ans.a[i+1]+=ans.a[i]/10;
			ans.a[i]%=10;
		}
		for(int i=10004;i>=0;--i){
			if(ans.a[i]){
				ans.digit=i+1;
				break;
			}
		}
		return ans;
	}
	void print(){
		for(int i=digit-1;i>=0;--i)
			cout<<a[i];
	}
};

bool eq(const Num &x,const Num &y){
	if(x.digit!=y.digit) return false;
	for(int i=0;i<x.digit;++i)
		if(x.a[i]!=y.a[i])
			return false;
	return true;
}

int main(){
	Num x=string("2"),y=string("3"),z=string("5");
	z=x*y;
	z.print();
	cout<<endl;
	return 0;
}