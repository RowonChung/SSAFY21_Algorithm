#include <iostream>
using namespace std;

int N;
int height[100000];
int sum = 0;

void greedy(int day) {
	int two = 0;
	int one = 0;

	for (int i = 0;i < N;i++) {
		two += height[i] / 2;
		one += height[i] % 2;
	}

	int tmp = two - day;

	if (tmp >= 0) {
		two = day;
		one += tmp * 2;
	}

	if (two == day && one == two) cout << "YES";
	else cout << "NO";

	return;
}

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> height[i];
		sum += height[i];
	}

	if (sum % 3 != 0)
		cout << "NO";
	else
		greedy(sum/3);

	return 0;
}