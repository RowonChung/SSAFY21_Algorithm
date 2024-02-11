#include <bits/stdc++.h>
using namespace std;

int n, m;
int depth[50001];
int parent[50001][20];
vector<int> alist[50001];

// 깊이 및 첫 번째 부모 연결 
void dfs(int curr){
	for(int nxt : alist[curr]){
		if(depth[nxt] == -1){
			parent[nxt][0] = curr;
			depth[nxt] = depth[curr] + 1;
			dfs(nxt);
		}
	}
	return;
}

int LCA(int a, int b){
	if(depth[a] < depth[b]) swap(a, b);
	
	int diff = (depth[a] - depth[b]);
	for(int i=0; diff!=0; i++){
		if(diff%2) a = parent[a][i];
		diff/=2;
	}
	
	// 깊이 같아지면
	if(a != b){
		// 점프할 수 있는 최대 거리부터 탐색 
		for(int i = 19; i>=0; i--){
			// Tree 범위이고, 부모가 다르면 점프 
			if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		// 최대로  점프한 곳의 바로 위 -> LCA 
		a = parent[a][0];
	} 
	return a; 
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// cout << fixed; cout.precision(n);
	
	cin >> n;
	for(int i=0; i<50001; i++){
		for(int j=0; j<20; j++) parent[i][j] = -1;
	}
	for(int i=0; i<=n; i++) depth[i] = -1;
	depth[1] = 0;
	
	for(int i=0; i<(n-1); i++){
		int p, c; cin >> p >> c;
		alist[p].push_back(c);
		alist[c].push_back(p);
	}
	dfs(1);
	
	// 2^j 번째 부모 연결 
	for(int i=1; i<20; i++){
		for(int j=2; j <= n; j++){
			if(parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
		}	
	}
	
	cin >> m;
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		cout << LCA(a, b) << '\n';
	} 
	return 0;
}