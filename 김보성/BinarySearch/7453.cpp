#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
long long int arr[4001][4]={};
vector<long long int> v01,v23;
map<long long int, int> m23;
int n;
int main()
{
	cin>>n;
	v01.resize(n*n);
	v23.resize(n*n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
			cin>>arr[i][j];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			v01[i*n+j] = arr[i][0]+arr[j][1];
			v23[i*n+j] = arr[i][2]+arr[j][3];
			
			//m23[arr[i][2]+arr[j][3]]++;
		}
	}

	sort(v01.begin(),v01.end());
	sort(v23.begin(),v23.end());
	long long int ret=0;
	for(int i =0;i<n*n;i++)
	{
		ret = ret - (lower_bound(v23.begin(),v23.end(),-v01[i]) - v01.begin()) + (upper_bound(v23.begin(),v23.end(),-v01[i])-v01.begin());
	}
	cout<<ret;
}