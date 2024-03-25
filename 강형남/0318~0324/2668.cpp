#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int visited[101];

int arr[101];

vector<int> answer;

void func(int now, int start) {
	if (visited[now]) {
		if (now == start) {
			answer.push_back(now);
		}
		return; 
	}

	visited[now] = 1;
	func(arr[now], start);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[j] = 0;
		}
		func(i, i);
	}
	cout << answer.size()<<"\n";
	for (auto i : answer) {
		cout << i << "\n";
	}

}