#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
    int answer = 0;

    // 맵 사용 key : 품목 이름 , value : 개수
    unordered_map<string, int> wanted;
    unordered_map<string, int> slidingwindow;
    
    for(int i=0;i<want.size();i++) {
        wanted[want[i]] = number[i];
        slidingwindow[want[i]] = 0;
    }
    
    // 10개
    // 쉽게 비교하기 위해서 want에 있는 품목만 넣어놓고 체크
    for(int i=0;i<9;i++) if (slidingwindow.count(discount[i])) slidingwindow[discount[i]]++;
    
    int startidx = 0;
    int lastidx = 9;

    int idx = 9;
    for(;idx<discount.size();idx++)
    {
        if (slidingwindow.count(discount[idx])) slidingwindow[discount[idx]]++;
        // 정답 맵 wanted와 슬라이딩 윈도우 맵 두개를 비교
        if (slidingwindow == wanted) answer++;
        if (slidingwindow.count(discount[idx - 9])) slidingwindow[discount[idx - 9]]--;
    }
    
    return answer;
}