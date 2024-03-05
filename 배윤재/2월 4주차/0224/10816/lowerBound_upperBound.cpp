#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int lowerBound(int start, int end, int tar)
{
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (arr[mid] < tar) start = mid + 1;
		else end = mid;
	}

	return end;
}

int upperBound(int start, int end, int tar)
{
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (arr[mid] <= tar) start = mid + 1;
		else end = mid;
	}

	return end;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int target;
		cin >> target;

		int from = lowerBound(0, n, target);
		int to = upperBound(0, n, target);

		cout << to - from << " ";
	}

}