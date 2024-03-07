#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define ll long long

ll num[1001];
bool comp(const ll& a, const ll& b) {
	if (a == 0) return false;
	if (b == 0) return true;

	string aa = to_string(a) + to_string(b);
	string bb = to_string(b) + to_string(a);

	return aa > bb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n, comp);
	string s;
	for (int i = 0; i < n; i++) s += to_string(num[i]);

	int flag = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0') flag = 1;
		if (flag) cout << s[i];
	}

	if (!flag) cout << 0;
	return 0;
}
