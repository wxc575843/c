#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#define MAXN 1005
using namespace std;
double city[MAXN][2];
int vis[MAXN];//在open表中为1
int clos[MAXN];
int path[MAXN];//记录前一个节点
int A = 144;
double orig_cost[MAXN];
double f[MAXN];
struct Link{
	int end;
	double cost;
	Link(int a=0,double b=0.0):end(a),cost(b){}
};
vector<Link> vLink[MAXN];
void output_path(int pos)
{
	if (path[pos] != 1)
		output_path(path[pos]);
	printf("%d->", path[pos]);
}
double dist(int sp, int ep)
{
	double x = city[sp][0] - city[ep][0];
	double y = city[sp][1] - city[ep][1];
	return sqrt(double(x*x + y*y));
}
struct cmp{
	bool operator()(const int &x, const int &y)
	{
		return f[x]>f[y];
	}
};
double Ecil_A(int src,int targ)
{
	priority_queue<int,vector<int>,cmp> QL;//open表
	QL.push(src);
	f[src] = dist(src, targ);
	while (!QL.empty())
	{
		int origp = QL.top();
		if (origp == targ)
			return orig_cost[targ];
		QL.pop();
		vis[origp] = 0;
		clos[origp] = 1;
		for (int i = 0; i < (int)vLink[origp].size(); i++)
		{
			int currp = vLink[origp][i].end;
			double tmp_cost = orig_cost[origp] + vLink[origp][i].cost;
			if (tmp_cost < orig_cost[currp])
				orig_cost[currp] = tmp_cost;
			double tmp_f = tmp_cost + dist(currp, targ);
			if (vis[currp] == 0 && clos[currp] == 0)//既不在open表中，也不在close表中
			{
				f[currp] = tmp_f;
				QL.push(currp);
				vis[currp] = 1;
				path[currp] = origp;
			}
			else if (vis[currp] == 1 && clos[currp] == 0)//在open表中
			{
				if (tmp_f < f[currp])
				{
					f[currp] = tmp_f;
					path[currp] = origp;
				}
			}
			else if (vis[currp] == 0 && clos[currp] == 0)//在close表中
			{
				if (tmp_f < f[currp])
				{
					f[currp] = tmp_f;
					clos[currp] = 0;
					QL.push(currp);
					vis[currp] = 1;
				}
			}
		}
	}
	return orig_cost[targ];
}
int main()
{
	freopen("Cities(144).txt", "r", stdin);
	double px, py;
	int pcnt;
	while (scanf("%d %lf %lf\n", &pcnt, &px, &py) != EOF)
	{
		city[pcnt][0] = px;
		city[pcnt][1] = py;
	}
	for (int i = 2; i <= pcnt; i++)
	{
		orig_cost[i] = 1e10;
		f[i] = 1e10;
	}
	memset(vis, 0, sizeof(vis));
	memset(clos, 0, sizeof(clos));
	memset(path, 0, sizeof(path));
	freopen("Cities(144)link.txt", "r", stdin);
	int lstart, lend;
	while (scanf("%d %d\n", &lstart, &lend) != EOF)
	{
		double c = dist(lstart, lend);
		vLink[lstart].push_back( Link( lend, c ));
		vLink[lend].push_back( Link( lstart, c ));
	}
	double ans = Ecil_A(1, A);
	if (ans < 1e10)
		output_path(A);
	printf("%d\n%f\n", A, ans);
	return 0;
}