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
map<int,int> h;
int a[100006];


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        h.clear();
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        for(int i=0;i<n;++i){
            int tem;
            scanf("%d",&tem);
            h[a[i]]=tem;
        }
        int ans=0,len=0;
        while(!h.empty()){
            int tem=h.begin()->first;
            if(tem==h[tem]){
                ++ans;
                len=0;
                h.erase(tem);
                continue;
            }
            while(h.find(h[tem])!=h.end()){
                int t=tem;
                tem=h[tem];
                ++len;
                h.erase(t);
            }
            h.erase(tem);
            ans+=len;
            len=0;
            // cout<<h.size();
        }
        cout<<ans<<endl;	
    }
    return 0;
}