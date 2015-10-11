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
int h[10005],w[10005];
const double EPS=1e-6;
double maxn=0;

double f(int n){
    double l=0.0,r=maxn;
    double m=(l+r)/2.0;
    double sum=0.0,now=0.0;
    for(int i=0;i<n;++i)
        sum+=1.0/3.0*w[i]*w[i]*h[i];
    while(r-l>EPS){
        m=(l+r)/2.0;
        now=0.0;
        for(int i=0;i<n;++i)
            now+=1.0/3.0*w[i]*w[i]*h[i]*pow((h[i]-m)/h[i],3);
        if(now<sum/2.0)
            r=m;
        else l=m;
    }
    return m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        maxn=0;
        for(int i=0;i<n;++i){
            scanf("%d",&h[i]);
            maxn=max(maxn,(double)h[i]);
        }
        for(int i=0;i<n;++i)
            scanf("%d",&w[i]);
        int ans=f(n);
        printf("%d\n",ans);
    }
    return 0;
}