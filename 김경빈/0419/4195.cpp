#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int TC, F;
string a, b;
unordered_map<string, string> parent;
unordered_map<string, int> num;

string find_parent(string a) {
	if (parent.count(a) == 0) {
		parent[a] = a;
		num[a] = 1;
		return a;
	}
	if (a == parent[a]) return a;

	return parent[a] = find_parent(parent[a]);
}

int union_parent(string a, string b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a == b) return num[a];

	if (a < b) {
		parent[b] = a;
		num[a] += num[b];
		num[b] = 0;
		return num[a];
	}
	else if (a > b) {
		parent[a] = b;
		num[b] += num[a];
		num[a] = 0;
		return num[b];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> F;
		for (int f = 0; f < F; f++) {
			cin >> a >> b;
			cout << union_parent(a, b) << '\n';
		}
		parent.clear();
		num.clear();
	}
}