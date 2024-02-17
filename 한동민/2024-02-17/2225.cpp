#include <iostream>
using namespace std;

int arr[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			arr[i][j] = 1;
		}
	}
	for (int i = 2; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000000;
		}
	}
	int n, k;
	cin >> n >> k;
	cout << arr[k][n];
}
