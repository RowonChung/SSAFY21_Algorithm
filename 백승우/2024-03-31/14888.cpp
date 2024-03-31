#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nums[11];
int operators[4];
int ans_min = int(1e9);
int ans_max = -1 * int(1e9);

void dfs(int result, int index)
{
	if (index == n) {
		ans_max = max(ans_max, result);
		ans_min = min(ans_min, result);

		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			operators[i]--;
			if (i == 0) dfs(result + nums[index], index + 1);
			else if (i == 1) dfs(result - nums[index], index + 1);
			else if (i == 2) dfs(result * nums[index], index + 1);
			else dfs(result / nums[index], index + 1);
			operators[i]++;
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < 4; i++) cin >> operators[i];

	dfs(nums[0], 1);

	cout << ans_max << '\n' << ans_min;

	return 0;
}
