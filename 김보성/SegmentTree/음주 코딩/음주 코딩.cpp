#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int n,k;
int arr[100010]={};
int tree[400040]={};

int init(int start,int end, int node)
{
	if(start==end)
		return tree[node] = arr[start];
	int mid = (start+end)/2;
	return tree[node] = init(start,mid,node*2)*init(mid+1,end,node*2+1);
}
int update(int begin,int end, int node, int idx, int val)
{
	if(idx<begin||idx>end)
		return tree[node];
	if(begin==end)
		return tree[node] = val;
	int mid = (begin+end)/2;
	return tree[node] = update(begin,mid,node*2,idx,val)*update(mid+1,end,node*2+1,idx,val);
}

int find(int begin,int end, int node, int left,int right)
{
	if(left>end||right<begin)
		return 1;
	if(left<=begin&&right>=end)
		return tree[node];
	int mid = (begin+end)/2;
	return find(begin,mid,node*2,left,right)*find(mid+1,end,node*2+1,left,right);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n>>k)
	{
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(a==0)
				arr[i]=0;
			else if(a<0)
				arr[i] = -1;
			else
				arr[i] = 1;
		}
		init(0,n-1,1);
		char str[100001]={};
		int idx = 0;
		for(int j=0;j<k;j++)
		{
			char a;
			int b,c;
			cin>>a>>b>>c;
			if(a=='C')
			{
				if(c<0)
					c=-1;
				else if(c>0)
					c=1;
				else 
				 	c=0;
				update(0,n-1,1,b-1,c);
			}
			else if(a=='P')
			{
				int ret = find(0,n-1,1,b-1,c-1);
				if(ret<0)
					str[idx] = '-';
				else if(ret>0)
					str[idx] ='+';
				else
					str[idx]='0';
				idx++;
				//cout<<str<<'\n';
			}
		}
		cout<<str<<'\n';
	}
}