#include <iostream>
#include <vector>
using namespace std;

int n, m;
int graph[50][50];
int tempGraph[50][50];

struct Node {
    int y;
    int x;
    bool operator==(Node right) const {
        if (y == right.y and x == right.x) return true;
        return false;
    }
};

vector <Node> cloud;
vector <Node> increases;

/* PRINT */
void gprint()
{
    cout << "printGraph\n";
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) cout << graph[y][x] << " ";
        cout << '\n';
    }
}

void cprint()
{
    cout << "printClouds\n";
    for (auto now : cloud) {
        cout << now.y << "&" << now.x << '\n';
    }
}

void print_all()
{
    gprint();
    cprint();
}

// 0. 초기 구름 세팅
void init()
{
    cloud.push_back({ n - 2,0 });
    cloud.push_back({ n - 2,1 });
    cloud.push_back({ n - 1,0 });
    cloud.push_back({ n - 1,1 });
}

// 1. 구름 이동
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
void move(int d, int s)
{
    for (int i = 0; i < s; i++) {
        vector <Node> temp;
        for (auto now : cloud) {
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];

            if (ny == -1) ny = n - 1;
            if (nx == -1) nx = n - 1;
            if (ny == n) ny = 0;
            if (nx == n) nx = 0;
            temp.push_back({ ny, nx });
        }
        cloud = temp;
    }
}

// 2. 비 내리기
void rainy()
{
    for (auto now : cloud) {
        graph[now.y][now.x] += 1;
    }
}

// 3. 구름 삭제 (물 증가로 이관)
void clear()
{
    increases.clear();
    increases = cloud;
    cloud.clear();
}

// 4. 물복사버그 마법
int cy[4] = { -1,-1,1,1 };
int cx[4] = { -1,1,-1,1 };
void magic()
{
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) tempGraph[y][x] = graph[y][x];
    }

    for (auto now : increases) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int ny = now.y + cy[i];
            int nx = now.x + cx[i];

            if (ny < 0 or ny >= n or nx < 0 or nx >= n) continue;
            if (tempGraph[ny][nx] > 0) cnt += 1;
        }
        graph[now.y][now.x] += cnt;
    }
}
// 5. 구름 재지정
void new_cloud()
{
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            Node now = { y, x };
            bool flag = false;
            for (auto increase : increases) {
                if (increase == now) flag = true;
            }
            if (flag) continue;
            if (graph[now.y][now.x] < 2) continue;

            cloud.push_back(now);
            graph[now.y][now.x] -= 2;
        }
    }
}

// last. 정답
int answer()
{
    int ans = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            ans += graph[y][x];
        }
    }
    return ans;
}


int main()
{
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) cin >> graph[y][x];
    }

    // 0 => okay
    init();


    int d, s;
    for (int i = 0; i < m; i++) {
        cin >> d >> s;
        // 1 => okay
        move(d - 1, s);
        // 2 => okay
        rainy();
        // 3 => okay
        clear();
        // 4 => okay
        magic();
        // 5 => okay
        new_cloud();
    }

    cout << answer();

    return 0;
}
