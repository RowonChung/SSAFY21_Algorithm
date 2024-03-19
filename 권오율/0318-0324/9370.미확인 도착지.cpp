#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
	int from, to, val;

	bool operator< (const Line& r) const {
		if (val < r.val) return false;
		if (val > r.val) return true;
		return false;
	}
};

priority_queue<Line> Lines;
vector <int> Candidates, ans;

// n 노드 수, m 간선 수, t 후보 수
int n, m, t;
// s 시작점, g h 경로점
int s, g, h;
int arr[2020][2020];
int distS[2020], distG[2020], distH[2020];
int tcs, each;


int main() {
	cin >> tcs;
	while (each++ < tcs) {
		


		// 입력
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int from, to, val;
			cin >> from >> to >> val;
			arr[from][to] = val;
			arr[to][from] = val;
		}
		for (int i = 0; i < t; i++) {
			int val;
			cin >> val;
			Candidates.push_back(val);
		}

		// 거리 초기화
		for (int i = 1; i <= n; i++) {
			distS[i] = 1e9;
			distG[i] = 1e9;
			distH[i] = 1e9;
		}

		//S에서 전체 거리 계산 > dijkstra
		distS[s] = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[s][i] == 0) continue;
			Lines.push({ s, i, arr[s][i] });
		}
		while (!Lines.empty()) {
			Line curr = Lines.top();
			Lines.pop();

			// to > i로 확인
			for (int i = 1; i <= n; i++) {
				if (arr[curr.to][i] == 0) continue;
				int nextVal = distS[curr.to] + arr[curr.to][i];
				if (distS[i] <= nextVal) continue;
				distS[i] = nextVal;
				Lines.push({ curr.to, i, arr[curr.to][i] });
			}

			// from > i로 확인
			for (int i = 1; i <= n; i++) {
				if (arr[curr.from][i] == 0) continue;
				int nextVal = distS[curr.from] + arr[curr.from][i];
				if (distS[i] <= nextVal) continue;
				distS[i] = nextVal;
				Lines.push({ curr.from, i, arr[curr.from][i] });
			}
		}

		//G에서 전체 거리 계산
		distG[g] = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[g][i] == 0) continue;
			Lines.push({ g, i, arr[g][i] });
		}
		while (!Lines.empty()) {
			Line curr = Lines.top();
			Lines.pop();

			for (int i = 1; i <= n; i++) {
				if (arr[curr.to][i] == 0) continue;
				int nextVal = distG[curr.to] + arr[curr.to][i];
				if (distG[i] <= nextVal) continue;
				distG[i] = nextVal;
				Lines.push({ curr.to, i, arr[curr.to][i] });
			}
			for (int i = 1; i <= n; i++) {
				if (arr[curr.from][i] == 0) continue;
				int nextVal = distG[curr.from] + arr[curr.from][i];
				if (distG[i] <= nextVal) continue;
				distG[i] = nextVal;
				Lines.push({ curr.from, i, arr[curr.from][i] });
			}
		}

		//H에서 전체 거리 계산
		distH[h] = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[h][i] == 0) continue;
			Lines.push({ h, i, arr[h][i] });
		}
		while (!Lines.empty()) {
			Line curr = Lines.top();
			Lines.pop();

			for (int i = 1; i <= n; i++) {
				if (arr[curr.to][i] == 0) continue;
				int nextVal = distH[curr.to] + arr[curr.to][i];
				if (distH[i] <= nextVal) continue;
				distH[i] = nextVal;
				Lines.push({ curr.to, i, arr[curr.to][i] });
			}
			for (int i = 1; i <= n; i++) {
				if (arr[curr.from][i] == 0) continue;
				int nextVal = distH[curr.from] + arr[curr.from][i];
				if (distH[i] <= nextVal) continue;
				distH[i] = nextVal;
				Lines.push({ curr.from, i, arr[curr.from][i] });
			}
		}


		// 경유 거리 = 최단 거리 확인
		for (auto el : Candidates) {
			int isSame = 0;
			// S > H > G > Candidate
			int SHGC = distS[h] + distH[g] + distG[el];
			if (SHGC == distS[el]) isSame = 1;

			// S > G > H > Candidate
			int SGHC = distS[g] + distG[h] + distH[el];
			if (SGHC == distS[el]) isSame = 1;

			// 같으면 ans에 정답
			if (isSame == 1) ans.push_back(el);
		}
		sort(ans.begin(), ans.end());
		for (auto el : ans) {
			cout << el << " ";
		}

		//초기화
		Lines = {};
		Candidates.clear(), ans.clear();
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				arr[i][j] = 0;
			}
		}
	}
}
