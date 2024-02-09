#include <iostream>
using namespace std;

int visited[9] = {0};
int result[9];
string path;
int N,M;
void run(int level) {
    if (level == M) {
        
        for (int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] != 1) {
            visited[i] = 1;
            result[level] = i;
            run(level + 1);
            visited[i] = 0;
        }
    }
}

int main() {
   
    cin >> N >> M;

    run(0);

    return 0;
}
