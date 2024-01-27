#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[2000];

int gcb(int a, int b) {
	return b ? gcb(b, a % b) : a;
}

int main() {
	int t;
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (n == 1) {
			cout << "INFINITY" << endl;
		}
		else {
			vector<int> v;
			for (int i = 1; i < n; i++) {
				if (abs(arr[i] - arr[i - 1]) != 0) {
					v.push_back(abs(arr[i] - arr[i - 1]));
				}
			}
			sort(v.begin(), v.end());
			if (v.size() == 0) {
				cout << "INFINITY" << endl;
			}
			else if (v.size() == 1) {
				cout << v[0] << endl;
			}
			else {
				int temp = v[0];
				for (int i = 1; i < v.size(); i++) {
					temp = gcb(temp, v[i]);
				}
				cout << temp << endl;
			}
		}
	}
}

