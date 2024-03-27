#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int arr[500][500]={};
int dp[500][500]={};
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};

int dfs(int cy,int cx)
{
	if(cy==n-1&&cx==m-1)
		return 1;
	if(dp[cy][cx]!=-1)
		return dp[cy][cx];
	dp[cy][cx]=0;
	for(int i=0;i<4;i++)
	{
		int ny = cy+dy[i];
		int nx = cx+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m)
			continue;
		if(arr[ny][nx]<arr[cy][cx])
			dp[cy][cx]+=dfs(ny,nx);
	}
	return dp[cy][cx];
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			dp[i][j]=-1;
		}
	}
	cout<<dfs(0,0);
}