#include<iostream>

using namespace std;
int arr[1000001];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		long long int result = 0;
		int max = n;
		for(int i = n - 1; i>=1;i--)
		{
			if(arr[i]>arr[max])
				max = i;
			else
				result += arr[max] - arr[i];
		}
		cout<<result<<endl;

	}
	return 0;
}