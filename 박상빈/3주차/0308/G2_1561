#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int rides[10001];
int answer;

bool judgement(long long time)
{
	long long cnt = 0;
	int maxi = -21e8;
	int idx = 0;
	for (int i = 0; i < m; i++)
	{
		cnt += (time / rides[i]);
	}

	if (cnt >= n - m)
	{
		return true;
	}
	else return false;
}

long long bs(long long start, long long end)
{
	long long mid;
	long long res = 21e12;

	while (start <= end)
	{
		mid = (start + end) / 2;

		// 판별
		if (judgement(mid))
		{
			res = min(mid, res);
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	if (n > m)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> rides[i];
		}

		long long time = bs(1, 60000000000);

		
		int cnt = m;
		for (int i = 0; i < m; i++)
		{
			cnt += (time - 1) / rides[i];
		}

		int idx = 0;

		while (cnt < n) {
			if (time % rides[idx++] == 0) cnt++;
		}

		cout << idx;
	}
	else
	{
		cout << n;
	}

	return 0;
}