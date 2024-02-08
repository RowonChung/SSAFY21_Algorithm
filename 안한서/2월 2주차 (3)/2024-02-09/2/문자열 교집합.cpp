#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n, m; cin >> n >> m;
		unordered_map<string, int> um;
		for (int i = 0; i < n + m; i++) {
			string s; cin >> s;
			um[s]++;
		}

		int ans = 0;
		for (auto curr : um) {
			// cout << curr.first << ' ' << curr.second << '\n';
			if (curr.second > 1) ans++;
		}

		cout << "#" << tc << " " << ans << "\n";

	}
	return 0;
}