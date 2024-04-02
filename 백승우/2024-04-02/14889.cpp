#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int y, x;
int s[20][20];

int ans = int(1e9);

int get_score(vector <int> now)
{
	int score = 0;

	for (int i = 0; i < now.size(); i++) {
		for (int j = 0; j < now.size(); j++) {
			score += s[now[i]][now[j]];
		}
	}

	return score;
}

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> s[y][x];
		}
	}

	vector <int> v;
	for (int i = 0; i < n / 2; i++) v.push_back(0);
	for (int i = 0; i < n / 2; i++) v.push_back(1);

	do {
		vector <int> start;
		vector <int> link;

		for (int i = 0; i < n; i++) {
			if (v[i]) start.push_back(i);
			else link.push_back(i);
		}

		ans = min(ans, abs(get_score(start) - get_score(link)));

	} while (next_permutation(v.begin(), v.end()));

	cout << ans;

	return 0;
}
