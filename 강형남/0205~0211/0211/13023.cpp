#include<iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> v[2001];
int visited[2001];
bool finished = false;

void fun(int level, int node) {
	if (level == 4) {
		finished = true;
		return;
	}
	visited[node] = true;
	int size = v[node].size();
	
	for (int i = 0; i < size; i++) {
		if(visited[v[node][i]]==1)continue;
		fun(level + 1, v[node][i]);
		
	}
	visited[node] = 0;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		fun(0, i);
		if (finished)break;
	}
	if (finished) {
		cout << 1;
	}
	else {
		cout << 0;
	}

}