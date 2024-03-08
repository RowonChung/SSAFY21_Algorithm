#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
int n, c;

int check(int k)
{
	int pre = arr[0];
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (pre + k <= arr[i])
		{
			pre = arr[i];
			cnt++;
		}
	}
	return cnt;
}




int main()
{
	cin >> n >> c;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	int left = 0;
	int right = arr[arr.size() - 1];
	int mid = (left + right) / 2;
	int ret = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid) >= c)
		{
			ret = max(ret, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ret << endl;
}