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
struct Person{
	char name[30],sex[7];
	double r1,r2,r;
};
bool operator<(const Person& x,const Person& y){
	return x.r>y.r;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		// vector<Person> male;
		vector<Person> fmale;
		vector<Person> all;
		vector<Person> final;
		double max1=0,max2=0;
		for(int i=0;i<n;++i){
			Person person;
			scanf("%s%s%lf%lf",person.name,person.sex,&person.r1,&person.r2);
			max1=max(max1,person.r1);
			max2=max(max2,person.r2);
			if(strcmp(person.sex,"female")==0)
				fmale.push_back(person);
			// else fmale.push_back(person);
			all.push_back(person);
		}
		for(int i=0;i<n;++i){
			all[i].r=all[i].r1/max1*300*0.3+all[i].r2/max2*300*0.7;
		}
		for(int i=0;i<fmale.size();++i){
			fmale[i].r=fmale[i].r1/max1*300*0.3+fmale[i].r2/max2*300*0.7;
		}
		sort(fmale.begin(),fmale.end());
		sort(all.begin(),all.end());
		if(fmale.size()>=1){
			for(int i=0;i<n;++i){
				if(all[i].r==fmale[0].r)
					all.erase(all.begin()+i);
			}
		}
		int limit=m;
		if(fmale.size()>=1)
			--limit;
		copy(all.begin(),all.begin()+limit,back_inserter(final));
		if(fmale.size()>=1)
			final.push_back(fmale[0]);
		sort(final.begin(), final.end());
		puts("The member list of Shandong team is as follows:");
		for(int i=0;i<m;++i){
			puts(final[i].name);
		}
	}	
	return 0;
}