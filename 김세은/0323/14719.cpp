#include <iostream>
#include <queue>
using namespace std;
//1. 젤 높은 거에서 하나씩 내려오면
//같은거 2개가 연결되는게 있으면 세고
// 센거는 합해야지
//센거는 제거 표시 숫자가 n과 같은거는 제거 안함

int H,W;
struct Node{
    int num;
    int c = 0;
};
int waters = 0;
Node blocks[500];
struct cmp{
    bool operator()(int a, int b){
        return a>b;
    }
};

priority_queue<int, vector<int>, cmp> q;
void wsum(){
    
    while(!q.empty()){
        int idx1 = q.top();
        q.pop();
        int idx2 = q.top();
        
        for(int i = idx1 + 1; i < idx2; i++){
            if(blocks[i].c != 1){
                waters += H - blocks[i].num;
                blocks[i].c = 1;
            }
        }
    }
    
    
}
int main(){
    
    cin >> H >> W;
    
    for(int i = 0; i < W; i++){
        cin >> blocks[i].num;
    }
    
    while(H != 0){
        for(int i = 0; i < W; i++){
            if(blocks[i].num >= H){
                q.push(i);
            }
        }
        if(q.size() >= 2)
            wsum();
        H--;
    }
    cout << waters;
}