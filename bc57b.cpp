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
int x[100006],y[100006];
bool hx[100006],hy[100006];
int n,m,k,q;

int lowbit(int s)
{
     return s&(-s);    
}

int sumx(int s)
{
    int sum=0;
    while(s>0)
    {
         sum+=x[s];
         s=s-lowbit(s);
    }    
    return sum;
}

int sumy(int s)
{
    int sum=0;
    while(s>0)
    {
         sum+=y[s];
         s=s-lowbit(s);
    }    
    return sum;
} 

void addx(int i,int s)
{
     while(i<=n)
     {
          x[i]=x[i]+s;
          i=i+lowbit(i);
     }

}

void addy(int i,int s)
{
     while(i<=m)
     {
          y[i]=y[i]+s;
          i=i+lowbit(i);
     }
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(hx,false,sizeof(hx));
		memset(hy,false,sizeof(hy));
		
		scanf("%d%d%d%d",&n,&m,&k,&q);
		while(k--){
			int a,b;
			scanf("%d%d",&a,&b);
			hx[a]=true;
			hy[b]=true;
			// cout<<"h"<<endl;
		}

		for(int i=1;i<=n;++i){
			if(hx[i])
				addx(i,1);
		}
		for(int i=1;i<=m;++i)
			if(hy[i])
				addy(i,1);
		while(q--){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int sx=sumx(x2)-sumx(x1-1),sy=sumy(y2)-sumy(y1-1);
			if(sx==x2-x1+1 || sy==y2-y1+1)
				puts("Yes");
			else puts("No");
		}
	}
	return 0;
}