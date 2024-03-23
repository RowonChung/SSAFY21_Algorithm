#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

ll arr[100010];
int n;
int str, dst;
ll mini = ll(1e18), mini_str, mini_dst;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	str = 0;
	dst = n - 1;

	while (str < dst) {
		if (arr[str] + arr[dst] > 0) {
			if (abs(mini) > abs(arr[str] + arr[dst])) {
				mini = arr[str] + arr[dst];
				mini_str = arr[str];
				mini_dst = arr[dst];
			}
			dst--;
		}
		else if (arr[str] + arr[dst] < 0) {
			if (abs(mini) > abs(arr[str] + arr[dst])) {
				mini = arr[str] + arr[dst];
				mini_str = arr[str];
				mini_dst = arr[dst];
			}
			str++;
		}
		else if (arr[str] + arr[dst] == 0) {
			mini_str = arr[str];
			mini_dst = arr[dst];
			break;
		}
	}
	cout << mini_str << " " << mini_dst;
}

