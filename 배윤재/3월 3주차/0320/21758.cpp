#include <iostream>
using namespace std;

int honey[100001];
int sumHoney = 0;
int maxHoney = 0;

int main() {
	int n;
	cin >> n;

	int temp = 0;

	for (int i = 0; i < n; i++) {
		cin >> honey[i];
		temp += honey[i];
	}


	// 1. 왼쪽 끝에 벌통, 오른쪽 끝에 벌
	int sumHoney = temp;

	sumHoney -= honey[n - 1];
	for (int i = 1; i < n - 1; i++) {
		
		sumHoney -= honey[i];
		sumHoney += honey[i - 1];

		maxHoney = max(maxHoney, sumHoney);

		sumHoney += honey[i];
	}
	sumHoney += honey[n - 1];

	sumHoney = temp;

	// 2. 오른쪽 끝에 벌통, 왼쪽 끝에 벌
	sumHoney -= honey[0];
	for (int i = n - 2; i >= 1; i--) {

		sumHoney -= honey[i];
		sumHoney += honey[i + 1];

		maxHoney = max(maxHoney, sumHoney);

		sumHoney += honey[i];
	}
	sumHoney += honey[0];

	// 3. 양쪽 끝에 벌
	sumHoney = 0;
	int one = honey[1], two = 0;

	for (int i = n - 2; i >= 1; i--) two += honey[i];

	for (int i = 2; i < n; i++) {
		sumHoney = one + two;

		maxHoney = max(maxHoney, sumHoney);

		one += honey[i];
		two -= honey[i - 1];
	}

	cout << maxHoney;
}
