#include <iostream>
#include <queue>

using namespace std;

int arr[1001];

int main() {
	int time = 0;
	int total = 0;
	int n, w, L;
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	queue<int> q;

	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				total -= q.front();
				q.pop();
			}
			if (total + arr[i] <= L) break;
			q.push(0);
			time++;
		}
		time++;
		q.push(arr[i]);
		total += arr[i];
	}
	cout << time + w << "\n";
	return 0;
}