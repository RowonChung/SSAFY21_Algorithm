#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int INF = 16 * 1000000 + 1;
int DP[16][1 << 16];
int tsp(int current, int visited);
int W[16][16];
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	cout << tsp(0, 1) << endl;


}

int tsp(int current, int visited) {
	if (visited == (1 << N) - 1) { //다 방문햇을때
		return W[current][0] == 0 ? INF : W[current][0];
	}
	if (DP[current][visited] != 0) {
		return DP[current][visited];
	} //이미 방문한 노드일 때
	int min_val = INF;
	for (int i = 0; i < N; i++) {
		if ((visited & (1 << i)) == 0 && W[current][i] != 0) {
			min_val = min(min_val, tsp(i, (visited | (1 << i))) + W[current][i]);
		}
	}
	DP[current][visited] = min_val;
	return DP[current][visited];
}