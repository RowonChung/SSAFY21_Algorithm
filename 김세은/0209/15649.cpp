#include <iostream>
using namespace std;

int visited[9] = {0};
int result[9];
int N,M;
void run(int level) {
    if (level == M) {
        
        for (int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
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
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
                              
    cin >> N >> M;

    run(0);

    return 0;
}
