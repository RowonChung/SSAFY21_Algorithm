#include<iostream>
#include<algorithm>
using namespace std;

bool used[10]={};
int arr[10]={};
int n;
int mx;

int check(int idx)
{
	int l = idx-1;
	int r = idx+1;
	while(l>=0)
	{
		if(!used[l])
			break;
		l--;
	}
	while(r<n)
	{
		if(!used[r])
			break;
		r++;
	}
	if(l>=0&&r<n)
		return arr[l]*arr[r];
	else if(r<n)
		return arr[r];
	else if(l>=0)
		return arr[l];
	else
		return arr[idx];
}

void dfs(int depth, int score)
{
	if(depth==n)
	{
		mx = max(mx,score);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i] = true;
			dfs(depth+1,score+check(i));
			used[i] = false;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		cin>>n;
		mx = 0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			used[i] = false;
		}
		dfs(0,0);
		printf("#%d %d\n",tc,mx);
	}
}