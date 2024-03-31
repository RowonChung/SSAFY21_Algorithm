#include <iostream>
#include <string>
#include <deque>
#include <cmath>
using namespace std;

deque<int> gear[4];
int k;

int ans = 0;

int direction[4];
bool used[4];

void clear()
{
	for (int i = 0; i < 4; i++) used[i] = false;
}

void operate(int g, int d)
{
	direction[g] = d;
	used[g] = true;

	if (g - 1 >= 0 and !used[g - 1]) {
		if (d == 0) operate(g - 1, 0);
		else if (gear[g][6] == gear[g - 1][2]) operate(g - 1, 0);
		else operate(g - 1, -d);
	}

	if (g + 1 < 4 and !used[g + 1]) {
		if (d == 0) operate(g + 1, 0);
		else if (gear[g][2] == gear[g + 1][6]) operate(g + 1, 0);
		else operate(g + 1, -d);
	}
}

void rotate()
{
	for (int i = 0; i < 4; i++) {
		if (direction[i] == 0)
			continue;
		// 시계
		if (direction[i] == 1) {
			int temp = gear[i].back();
			gear[i].pop_back();
			gear[i].push_front(temp);
		}
		// 반시계
		else {
			int temp = gear[i].front();
			gear[i].pop_front();
			gear[i].push_back(temp);
		}
	}
}

int answer()
{
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {
			ans += pow(2, i);
		}
	}
	return ans;
}

int main()
{
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			gear[i].push_back(s[j] - '0');
		}
	}

	cin >> k;

	int v, d;
	for (int i = 0; i < k; i++) {
		clear();

		cin >> v >> d;
		int num = v - 1;
		operate(num, d);
		rotate();
	}

	cout << answer();

	return 0;
}
