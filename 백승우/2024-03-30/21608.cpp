#include <iostream>
#include <queue>
using namespace std;

int n;
int graph[20][20];

int like_graph[20 * 20 + 1][4];

/*PRINT*/
void gPrint() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) cout << graph[y][x] << " ";
		cout << "\n";
	}
}

struct Node {
	int y;
	int x;
	bool operator<(Node right) const {
		if (y < right.y) return true;
		if (y == right.y and x < right.x) return true;
		return false;
	}
	bool operator>(Node right) const {
		if (y > right.y) return true;
		if (y == right.y and x > right.x) return true;
		return false;
	}
};

struct Info {
	int fan_cnt;
	int blank_cnt;
	Node pos;

	bool operator<(const Info& right) const {
		if (fan_cnt != right.fan_cnt) return fan_cnt < right.fan_cnt;
		if (blank_cnt != right.blank_cnt) return blank_cnt < right.blank_cnt;
		return pos > right.pos;
	}

};

bool is_fan(int guess, int* likes)
{
	for (int i = 0; i < 4; i++) {
		if (guess == likes[i]) return true;
	}
	return false;
}

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
Info get_info(Node pos, int* likes)
{
	int fan_cnt = 0;
	int blank_cnt = 0;

	for (int i = 0; i < 4; i++) {
		int ny = pos.y + dy[i];
		int nx = pos.x + dx[i];
		if (ny < 0 or ny >= n or nx < 0 or nx >= n) continue;

		if (graph[ny][nx] == 0) blank_cnt += 1;
		else {
			if (is_fan(graph[ny][nx], likes)) fan_cnt += 1;
		}
	}

	return { fan_cnt, blank_cnt, pos };
}

int how_happy(int target, Node pos)
{
	int fan_cnt = 0;

	for (int i = 0; i < 4; i++) {
		int ny = pos.y + dy[i];
		int nx = pos.x + dx[i];
		if (ny < 0 or ny >= n or nx < 0 or nx >= n) continue;
		if (is_fan(graph[ny][nx], like_graph[target])) fan_cnt += 1;
	}

	if (fan_cnt == 0) return 0;
	else if (fan_cnt == 1) return 1;
	else if (fan_cnt == 2) return 10;
	else if (fan_cnt == 3) return 100;
	else if (fan_cnt == 4) return 1000;
}

int main()
{
	int ans = 0;

	cin >> n;

	int target;
	int likes[4];
	for (int each = 0; each < n * n; each++) {
		// 입력: 타겟과 팬들
		cin >> target;
		for (int i = 0; i < 4; i++) {
			cin >> likes[i];
			like_graph[target][i] = likes[i];
		}

		// 자리 배치 시작
		priority_queue <Info> pq;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (graph[y][x]) continue;
				Info now = get_info({ y, x }, likes);
				pq.push(now);
			}
		}

		Info final = pq.top();

		graph[final.pos.y][final.pos.x] = target;
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			ans += how_happy(graph[y][x], { y,x });
		}
	}

	cout << ans;

	return 0;
}
