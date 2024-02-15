#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int K, N_size, visited[10000000];
string N, qp;
queue<string> nums;
priority_queue<string> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	N_size = N.size();
	nums.push(N);

	while (!nums.empty() && K > 0) {
		int nums_size = nums.size();
		for (int i = 0; i < nums_size; i++) {
			qp = nums.front();
			nums.pop();
			visited[stoi(qp)] = 0;

			for (int j = 0; j < N_size; j++) {
				for (int k = 0; k < j; k++) {
					string temp_string = qp;
					char temp = temp_string[j];
					if (k == 0 && temp == '0') continue;
					temp_string[j] = temp_string[k];
					temp_string[k] = temp;
					int temp_int = stoi(temp_string);
					if (visited[temp_int]) continue;
					visited[temp_int] = 1;
					nums.push(temp_string);
					if (K == 1) ans.push(temp_string);
				}
			}
		}
		K--;
	}

	if (ans.size() == 0 || K > 0) cout << -1;
	else cout << ans.top();
}