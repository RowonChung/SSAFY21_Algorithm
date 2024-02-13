#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

unordered_map <int, int> MID;

int N, len;
int num[1010];
int nodecnt = 0;
struct Node {
	Node* par;
	int mID, mNum;
	Node* next[3];
};

Node Nodepool[20000];
int root[20000];

void init(int N, int mId[], int mNum[]) {
	len = 0;
	nodecnt = N;
	MID.clear();
	

	for (int i = 0; i < N; i++) {
		Nodepool[i].mID = mId[i];
		Nodepool[i].mNum = mNum[i];
		len += mNum[i];
		num[i] = mNum[i];
		Nodepool[i].par = nullptr;
		MID.insert(make_pair(mNum[i], mId[i]));
		for (int j = 0; j < 3; j++) {
			Nodepool[i].next[j] = nullptr;
		}
	}
	for (int i = N; i < 20000; i++) {
		Nodepool[i].mID = -1;
		Nodepool[i].mNum = -1;
		Nodepool[i].par = nullptr;
		for (int j = 0; j < 3; j++) {
			Nodepool[i].next[j] = nullptr;
		}
	}

	return;
}

int add(int mId, int mNum, int mParent) {
	Node* parentNode = &Nodepool[MID[mParent]];
	int check = 1;
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (parentNode->next == nullptr) {
			MID.insert(make_pair(mId, nodecnt));
			Node* curNode = &Nodepool[nodecnt++];
			curNode->mID = mId;
			curNode->mNum = mNum;
			curNode->par = parentNode;
			ans = parentNode->mNum + curNode->mNum;
			while (1) {
				parentNode->mNum += mNum;
				parentNode = parentNode->par;
			}
			check = 0;
			break;
		}
	}
	if (check) 	return -1;

	return 0;
}

int remove(int mId) {
	return 0;
}

int distribute(int K) {
	return 0;
}