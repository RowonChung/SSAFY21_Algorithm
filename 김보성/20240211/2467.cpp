#include<iostream>
#include<algorithm>
using namespace std;

int n;
int ans_l,ans_r;
int arr[100000]={};
int mn =2000000000;
int pre = mn;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int left = 0;
	int right = n-1;
	while(left<right)
	{
		int dif = abs(arr[left]+arr[right]);
		if(dif<mn)
		{
			mn = dif;
			ans_l = arr[left];
			ans_r = arr[right];
		}
		if((arr[left]+arr[right])<0)
		{
			left++;
		}
		else
			right--;
	}
	cout<<ans_l<<" "<<ans_r;
}