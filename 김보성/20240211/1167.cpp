#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair <int,int>> v[100001];
bool used[100001]={};
int n;
int len=0;
int point;

void dfs(int node, int cost)
{
	if(len<cost)
	{
		len = cost;
		point = node;
	}
	for(int i=0;i<v[node].size();i++)
	{
		if(!used[v[node][i].first])
		{
			used[v[node][i].first]=true;
			dfs(v[node][i].first,v[node][i].second+cost);
			used[v[node][i].first]=false;
		}
	}
}

int main()
{
	cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		int cost,to=0;
		cin>>to;
		while(to!=-1)
		{
			cin>>cost;
			v[k].push_back({to,cost});
			cin>>to;
		}
	}
    used[1]=true;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		used[i]=false;
    used[point]=true;
	dfs(point,0);
	cout<<len;
}