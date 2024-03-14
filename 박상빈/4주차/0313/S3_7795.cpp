#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int t, n, m;
int A[20001];
int B[20001];

int solution()
{
	int answer = 0;
	int aidx = 0, bidx = 0;

	while (true)
	{
		if (aidx >= n || bidx >= m) break;

		if (A[aidx] > B[bidx])
		{
			answer += (m - bidx);
			aidx++;
		}
		else
		{
			bidx++;
		}
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int idx = 0; idx < t; idx++)
	{
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}

		for (int i = 0; i < m; i++)
		{
			cin >> B[i];
		}

		sort(A, A + n, greater<>());
		sort(B, B + m, greater<>());

		cout << solution() << "\n";
	}

	return 0;
}