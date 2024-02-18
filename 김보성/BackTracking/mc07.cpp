#include<iostream>
#include<algorithm>
using namespace std;

int height[10]={};
int combi[10]={};
bool used[10]={};
int cnt=0;
int n,k;

void dfs(int depth)
{
	if(depth==n)
	{
		cnt++;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			if(depth)
			{
				if(abs(combi[depth-1]-height[i])<=k&&combi[depth-1]!=height[i])
				{
					used[i] = true;
					combi[depth] = height[i];
					dfs(depth+1);
					used[i] = false;
				}
			}
			else
			{
				used[i] = true;
				combi[depth] = height[i];
				dfs(depth+1);
				used[i] = false;
			}
		}
	}
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>height[i];
	dfs(0);
	cout<<cnt;
}
