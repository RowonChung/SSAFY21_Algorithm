#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int arr[100010]={};
int tree[400040]={};

int init(int begin, int end, int node)
{
	if(begin==end)
		return tree[node] =arr[begin];
	int mid = (begin+end)/2;
	return tree[node] = min(init(begin,mid,node*2),init(mid+1,end,node*2+1));
}

int find(int begin, int end, int node, int left, int right)
{
	if(left>end||right<begin)
	{
		return -1;
	}
	if(left<=begin&&right>=end)
	{
		return tree[node];
	}
	int mid = (begin+end)/2;
	int lmin = find(begin,mid,node*2,left,right);
	int rmin = find(mid+1, end, node*2+1, left,right);
	if(lmin==-1)
		return rmin;
	else if(rmin==-1)
		return lmin;
	else
		return min(lmin,rmin);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	init(0,n-1,1);
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		cout<<find(0,n-1,1,a-1,b-1)<<'\n';
	}
}