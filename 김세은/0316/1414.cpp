#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string tarr[51];
int result;

struct Node {
    int i, j;
    int price;
};

vector <Node> line;
int arr[53];
int nline = 0;

bool compare(Node a, Node b){
    return a.price < b.price;
}

void init(){
    for(int i = 0; i < 53; i++) arr[i] = i;
}

int find(int tar) {
    if (arr[tar] == tar) return tar;
    int ret = find(arr[tar]);
    arr[tar] = ret;
    return ret;
}

void setUnion(int a, int b) {
    int t1 = find(a);
    int t2 = find(b);
    if (t1 == t2) return;
    arr[t2] = t1;
}

int main(){
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> tarr[i];
    }
    
    int total = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tarr[i][j] >= 'a' && tarr[i][j] <= 'z'){
                line.push_back({i,j,tarr[i][j] - 'a' + 1});
                total += tarr[i][j] - 'a' + 1;
            }
            if(tarr[i][j] >= 'A' && tarr[i][j] <= 'Z'){
                line.push_back({i,j,tarr[i][j] - 'A' + 27});
                total += tarr[i][j] - 'A' + 27;
            }
        }
    }
    
    init();
    
    // line에 저장
    sort(line.begin(), line.end(), compare);
    
    for (Node sel : line) {
        //사이클 있?
        int a = sel.i;
        int b = sel.j;
        int price = sel.price;
        
        //검사
        if (find(a) == find(b)) continue;
        setUnion(a, b); // 그룹 지어주기
        total -= price;
        
        //result += price;
        nline += 1;
        if(nline == N - 1)
            break;
        
    }
        
    if(nline == N - 1)
        cout << total;
    else
        cout << -1;
    
}