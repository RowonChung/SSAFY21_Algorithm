#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[51];
deque<int> dq;

int cnt = 0;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
}

int find(int num)
{
	for (int i = 0; i < dq.size(); i++)
	{
		if (dq[i] == num)
		{
			return i;
		}
	}

	return -1;
}

void solve()
{
	for (int i = 0; i < m; i++)
	{
		int now = arr[i];

		while (find(now) != -1) {
			// 1. 첫번째인 경우
			if (dq.front() == now)
			{
				dq.pop_front();
				break;
			}

			else {
				// 2. 왼쪽에 더 가까운 경우
				if (find(now) <= (dq.size() / 2)) {
					int before = dq.front();
					dq.pop_front();
					dq.push_back(before);
					cnt++;
				}
				// 3. 오른쪽에 더 가까운 경우
				else {
					int after = dq.back();
					dq.pop_back();
					dq.push_front(after);
					cnt++;
				}
			}
		}
	}
}

int main()
{
	input();

	solve();

	cout << cnt;
	
	return 0;
}