#include <iostream>
#include <vector>

using namespace std;

vector<int> v[50];

int N;

int cnt = 0;

int n;

void fun(int node) {
	if (node == n)return;
	int size = v[node].size();
	if (size == 0) {
		cnt++;
		return;
	}
	for (int i = 0; i < size; i++) {
		fun(v[node][i]);
	}
}

int main() {
	cin >> N;
	int head = 0;
	
	int arr[51];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	cin >> n;
	for (int i = 0; i < N; i++) {
		if (arr[i] != -1) {
			if(n!=i&&arr[i]!=n)
			v[arr[i]].push_back(i);
		}
		else {
			head = i;
		}
	}
	
	v[n].clear();

	fun(head);
	cout << cnt;
}