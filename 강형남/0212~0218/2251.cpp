#include <iostream>
#include<set>
using namespace std;

int visited[200][200][200];

int full[3];
set<int> se;

void fun(int a, int b, int c) {
	if (visited[a][b][c] == 1) {
		return;
	}
	if (a == 0) {
		se.insert(c);
	}
	visited[a][b][c] = 1;
	if (a != 0) {
		//b에 붓기
		int available = full[1] - b;
		int next_a = a - available;
		if (next_a < 0) {
			next_a = 0;
		}
		int next_b = b + (a - next_a);
		if (next_b > full[1]) {
			next_b = full[1];
		}
		fun(next_a, next_b, c);
		//c에 붓기
		available = full[2] - c;
		next_a = a - available;
		if (next_a < 0) {
			next_a = 0;
		}
		int next_c = c + (a - next_a);
		if (next_c > full[2]) {
			next_c = full[2];
		}
		fun(next_a, b, next_c);
	}
	if (b != 0) {
		//a에 붓기
		int available = full[0] - a;
		int next_b = b - available;
		if (next_b < 0) {
			next_b = 0;
		}
		int next_a = a + (b - next_b);
		if (next_a > full[0]) {
			next_a = full[0];
		}
		fun(next_a, next_b, c);
		//c에 붓기
		 available = full[2] - c;
		next_b = b - available;
		if (next_b < 0) {
			next_b = 0;
		}
		int next_c = c + (b - next_b);
		if (next_c > full[2]) {
			next_c = full[2];
		}
		fun(a, next_b, next_c);
	}
	if (c != 0) {

		int available = full[0] - a;
		int next_c = c - available;
		if (next_c < 0) {
			next_c = 0;
		}
		int next_a = a + (c - next_c);
		if (next_a > full[0]) {
			next_a = full[0];
		}
		fun(next_a, b, next_c);
		//b
		available = full[1] - b;
		next_c = c - available;
		if (next_c < 0) {
			next_c = 0;
		}
		int next_b = b + (c - next_c);
		if (next_b > full[1]) {
			next_b = full[1];
		}
		fun(a, next_b, next_c);
	}


}

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> full[i];
	}

	fun(0, 0, full[2]);

	for (auto i : se) {
		cout << i << " ";
	}
}