#include<iostream>
#include<vector>
using namespace std;

int arr[9][9]={};
vector< pair<int, int> > v;
int n=0;
bool made = false;

bool check(int cy,int cx,int num){
	for(int i=0;i<9;i++)
	{
		if(arr[cy][i]==num)
			return false;
		if(arr[i][cx]==num)
			return false;
		if(arr[(cy/3)*3+i/3][(cx/3)*3+i%3]==num)
			return false;
	}
	return true;
}

void dfs(int depth)
{
	if(made)
		return;
	if(depth == n)
	{
		made = true;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				cout<<arr[i][j]<<' ';
			cout<<endl;
		}
		return ;
	}
	for(int i=1;i<10;i++)
	{
		if(made)
			return;
		int ny = v[depth].first;
		int nx = v[depth].second;
		if(check(ny,nx,i))
		{
			arr[ny][nx] = i;
			dfs(depth+1);
			arr[ny][nx] = 0;
		}
	}
}

int main()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>arr[i][j];
			if(!arr[i][j])
			{
				v.push_back(make_pair(i,j));
				n++;
			}
		}
	}
	dfs(0);
}