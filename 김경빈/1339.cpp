#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;

vector<int> v(26);

int main() {	
	int N, ans = 0, mul = 9;
	string str[10];
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> str[n];
	}
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < int(str[n].size()); i++) {
			v[str[n][i] - 'A'] += pow(10, str[n].size() - i - 1);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i <= 9; i++) {
		ans += v[25 - i] * (9 - i);
	}
	cout << ans;


	return 0;
}