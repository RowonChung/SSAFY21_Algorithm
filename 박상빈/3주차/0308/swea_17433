#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct AddData {
    int gender;
    int grade;
    int id;
    int score;
    bool operator<(AddData right) const {
        if (score == right.score) return id < right.id;
        return score < right.score;
    }
};

struct RemoveData {
    int gender;
    int grade;
    int id;
    int score;
    bool operator<(RemoveData right) const {
        if (score == right.score) return id > right.id;
        return score > right.score;
    }
};

priority_queue<AddData> addData[6];
priority_queue<RemoveData> removeData[6];
//            id
unordered_map<int, AddData> allData;
// score
map<int, set<int>> queryData;

// data
// 1학년 m - 0 f - 1
// 2학년 m - 2 f - 3
// 3학년 m - 4 f - 5

void init() {
    for (int i = 0; i < 6; i++)
    {
        addData[i] = {};
        removeData[i] = {};
        queryData[i].clear();
    }
    allData.clear();
    return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    int res;
    int gender;
    int idx;
    if (mGender[0] == 'm')
    {
        gender = 0;
        if (mGrade == 1)
        {
            idx = 0;
            addData[0].push({ 0, mGrade, mId, mScore });
            removeData[0].push({ 0, mGrade, mId, mScore });
        }
        else if (mGrade == 2)
        {
            idx = 2;
            addData[2].push({ 0, mGrade, mId, mScore });
            removeData[2].push({ 0, mGrade, mId, mScore });

        }
        else if (mGrade == 3)
        {
            idx = 4;
            addData[4].push({ 0, mGrade, mId, mScore });
            removeData[4].push({ 0, mGrade, mId, mScore });

        }
    }
    else
    {
        gender = 1;
        if (mGrade == 1)
        {
            idx = 1;
            addData[1].push({ 1, mGrade, mId, mScore });
            removeData[1].push({ 1, mGrade, mId, mScore });
        }
        else if (mGrade == 2)
        {
            idx = 3;
            addData[3].push({ 1, mGrade, mId, mScore });
            removeData[3].push({ 1, mGrade, mId, mScore });
        }
        else if (mGrade == 3)
        {
            idx = 5;
            addData[5].push({ 1, mGrade, mId, mScore });
            removeData[5].push({ 1, mGrade, mId, mScore });
        }
    }

    allData[mId] = { gender, mGrade, mId, mScore };
    queryData[mScore].insert(mId);

    while (!addData[idx].empty())
    {
        AddData now = addData[idx].top();

        if (allData.find(now.id) != allData.end())
        {
            res = now.id;
            break;
        }
        else addData[idx].pop();
    }

    return res;
}

int remove(int mId) {

    if (allData.find(mId) != allData.end())
    {
        // 데이터가 있는 경우
        int res = 0;
        int idx;
        AddData now = allData[mId];
        // 지우고
        allData.erase(mId);
        queryData[now.score].erase(mId);

        // 접근하는데
        // 이미 지워진 학생이면 포함 X
        if (now.gender == 0)
        {
            if (now.grade == 1) idx = 0;
            else if (now.grade == 2) idx = 2;
            else idx = 4;
        }
        else
        {
            if (now.grade == 1) idx = 1;
            else if (now.grade == 2) idx = 3;
            else idx = 5;
        }

        // 아직 남아있는 학생들 중에서
        while (!removeData[idx].empty())
        {
            RemoveData next = removeData[idx].top();

            if (allData.find(next.id) != allData.end())
            {
                res = next.id;
                break;
            }
            else removeData[idx].pop();
        }

        return res;
    }
    else return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {

    // 점수가 mscore 이상이어야한다
    // upperbound ?
    auto originiter = queryData.lower_bound(mScore);

    for (originiter; originiter != queryData.end(); originiter++)
    {
        for (auto iter = originiter->second.begin(); iter != originiter->second.end(); iter++)
        {
            AddData now = allData[*iter];
            char gender;
            if (now.gender == 0) gender = 'm';
            else gender = 'f';

            bool gradeokay = false;
            bool genderokay = false;
            for (int i = 0; i < mGradeCnt; i++) if (mGrade[i] == now.grade) gradeokay = true;
            for (int i = 0; i < mGenderCnt; i++) if (mGender[i][0] == gender) genderokay = true;

            if (gradeokay && genderokay) return *iter;
        }
    }

    return 0;
}
