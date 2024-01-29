#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int honeycomb[1155][1155]; // 벌집 
int visited[1155][1155]; // 방문 처리 (직전 방 번호) 
int dx[6] = {-1, 0, 1, 1, 0, -1};
int dy[6] = {0, 1, 1, 0, -1, -1};
int start, dest, sx, sy;

void make_honeycomb(){
	// 0, 1, 2 ... 줄 번호 증가 -> 6*(줄 번호 합)
	// 6((n * (n + 1)) / 2) + 1 칸이 존재 ... 577 개의 줄 존재 (1000000 이하) 
	int x=577, y=577;
	int n = 1, line = 1; // 방 번호, 라인 순서
	honeycomb[x][y] = 1; 
	while(1){
		for (int d = 0; d < 6; d++) {
			// 오른쪽 (idx : 1) 경우만 (line-1)번, 나머지는 line번 방향 반복된다. 
	        for (int t = 0; t < (d == 1 ? line-1 : line); t++) {
	            int nx = x + dx[d], ny= y + dy[d];
	            honeycomb[nx][ny] = ++n;
	            
	            // 시작 좌표 저장
				if(n == start){ sx = nx; sy = ny; } 
	            
	            if(n == 1000000) return;
	            x = nx; y = ny;
	        }
	    }
	    line++;
	}
}

int main(){
	cin >> start >> dest;
	make_honeycomb();
	
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = -1; // 직전 방 번호 없음 ... -1 
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		// 출구 도착 (방문 처리 역으로 갱신) 
		if(honeycomb[x][y] == dest){
			vector<int> ans;
			ans.push_back(dest);
			
			while(1){
				// 시작 점 도착 
				if(visited[x][y] == -1) break;
				
				for(int d=0; d<6; d++){
					int nx = x + dx[d], ny = y + dy[d];
					// 방문 처리한 경로로 갱신 
					if(honeycomb[nx][ny] == visited[x][y]){
						ans.push_back(honeycomb[nx][ny]);
						x = nx; y = ny; break;
					}
				}
			}
			
			// 경로 출력 
			for(int i=(ans.size()-1); i>=0; i--) cout << ans[i] << ' ';
			break;
		}
		
		for(int d=0; d<6; d++){
			int nx = x + dx[d], ny = y + dy[d];
			if(nx<0 || nx>1154 || ny<0 || ny>1154) continue;
			if(honeycomb[nx][ny] == 0 || visited[nx][ny] != 0) continue;
			visited[nx][ny] = honeycomb[x][y];
			q.push(make_pair(nx, ny));
		}
	}
	return 0;
}