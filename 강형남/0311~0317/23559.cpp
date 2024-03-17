#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, X;

struct node {
	int five;
	int one;
	int distance;
};

bool comp(node left, node right) {
	if (left.distance > right.distance)return true;
	else return false;
}


int main() {
	cin >> N >> X;
	vector<node> v;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		answer += b;
		v.push_back({ a,b,abs(a - b) });
		X -= 1000;
	}
	sort(v.begin(), v.end(), comp);



	for (int i = 0; i < N; i++) {
		if (X >= 4000 && v[i].five - v[i].one >= 0) {
			X -= 4000;
			answer += v[i].five - v[i].one;
		}
	}
	cout << answer;

}
