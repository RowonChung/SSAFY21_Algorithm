#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;
vector<int> B;
int cnt = 0;
bool compare(int a, int b){
    return a > b;
}
void tp() {

    sort(A.begin(), A.end(),compare);
    sort(B.begin(), B.end(),compare);

    cnt = 0;
   
   // int a = 0; int b = 0;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            if(A[i] > B[j]){
                cnt += B.size() - j;
               
                break;
            }
        }
    }
    
}

int main() {
  
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++){
        A.clear();
        B.clear();
        
        cin >> N >> M;
        
        for (int i = 0; i < N; ++i){
            int num1;
            cin >> num1;
            A.push_back(num1);
        }
        
        for (int i = 0; i < M; ++i){
            int num2;
            cin >> num2;
            B.push_back(num2);
        }
        
        tp();
        
        cout << cnt << "\n";
        
        
    }
}

