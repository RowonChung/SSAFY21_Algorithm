#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, M, num, qp, temp1, temp2;
bool party_pos[51] = { false, }, visited[51] = { false, };
vector<int> party_men[51];
vector<int> men_party[51];
deque<int> q;

int main() {
	cin >> N >> M;
	cin >> num;
	for (int n = 0; n < num; n++) {
		cin >> temp1;
		q.push_back(temp1);
		visited[temp1] = true;
	}
	for (int m = 0; m < M; m++) {
		cin >> temp1;
		for (int t = 0; t < temp1; t++) {
			cin >> temp2;
			party_men[m].push_back(temp2);
			men_party[temp2].push_back(m);
		}
	}
	while (!q.empty()) {
		qp = q.front();
		q.pop_front();
		for (int p : men_party[qp]) {
			if (not party_pos[p]) {
				party_pos[p] = true;
				for (int m : party_men[p]) {
					if (not visited[m]) {
						visited[m] = true;
						q.push_back(m);
					}
				}
			}
		}
	}
	cout << M - count(party_pos, party_pos + sizeof(party_pos), true) << endl;
}