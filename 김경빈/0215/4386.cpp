#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

struct star {
	int s1, s2;
	double cost;

	bool operator<(star right) const {
		return cost < right.cost;
	}
};
int n, line, parent[100], visited[100][100];
double stars[100][2], ans;
vector<star> v;

int find_parent(int s) {
	if (parent[s] == s) return s;
	return parent[s] = find_parent(parent[s]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stars[i][0] >> stars[i][1];
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			double temp_cost;
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			if (stars[i][0] == stars[j][0]) {
				temp_cost = abs(stars[i][1] - stars[j][1]);
			}
			else if (stars[i][1] == stars[j][1]) {
				temp_cost = abs(stars[i][0] - stars[j][0]);
			}
			else {
				temp_cost = sqrt(pow(stars[i][0] - stars[j][0], 2) + pow(stars[i][1] - stars[j][1], 2));
			}
			v.push_back({ i, j, temp_cost });
		}
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		star temp = v[i];
		int parent_s1 = find_parent(temp.s1);
		int parent_s2 = find_parent(temp.s2);
		if (parent_s1 == parent_s2) continue;
		ans += temp.cost;
		if (parent_s1 < parent_s2) parent[parent_s2] = parent_s1;
		else parent[parent_s1] = parent_s2;
		line++;
		if (line == n - 1) break;
	}
	cout << ans;
}