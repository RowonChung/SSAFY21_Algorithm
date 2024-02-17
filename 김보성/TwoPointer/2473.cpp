#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	long long arr[5000]={};
	int n;
	long long ret[3] ={};
	long long mn = 3000000000;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int end = n-1; end>1;end--)
	{
		int l = 0;
		int r = end -1;
		while(l<r)
		{
			long long sum = arr[l]+arr[r]+arr[end];
			if(abs(sum)<mn)
			{
				mn = abs(sum);
				ret[0] = arr[l];
				ret[1] = arr[r];
				ret[2] = arr[end];
			}
			if(sum <= 0)
				l++;
			else
				r--;
		}
	}
	for(int i=0;i<3;i++)
		cout<<ret[i]<<' ';
}