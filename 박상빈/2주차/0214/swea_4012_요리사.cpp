#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int collabo[17][17];
bool isused[17] = { false, };
int answer;
int allsum = 0;

// 재귀 가능 ?
void recursion(int idx, int level)
{
	if (level == n / 2)
	{
		int asum = 0, bsum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				if (isused[i] && isused[j]) asum += collabo[i][j];
				else if (!isused[i] && !isused[j]) bsum += collabo[i][j];
			}
		}

		answer = min(answer, abs(asum - bsum));

		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (!isused[i])
		{
			isused[i] = true;
			recursion(i + 1, level + 1);
			isused[i] = false;
		}
	}


}


int main(int argc, char** argv)
{
	int t;

	cin >> t;

	for (int idx = 1; idx <= t; idx++)
	{
		cin >> n;

		answer = 21e8;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> collabo[i][j];
			}
		}

		recursion(0, 0);

		cout << "#" << idx << " " << answer << "\n";

	}



	return 0;
}