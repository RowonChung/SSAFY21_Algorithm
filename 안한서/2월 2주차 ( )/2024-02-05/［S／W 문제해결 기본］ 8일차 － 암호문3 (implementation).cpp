#include <iostream>
#include <vector>
using namespace std;
const int NODE_MAX = 5000;

struct Node {
	int data;
	Node* prev;
	Node* next;

	// <node pool>
	// Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* head;
Node* tail;
int len;
// <node pool>
// vector<Node*> nodeArr;

void init_list() {
	// 메모리 할당
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));

	head->prev = nullptr;
	head->next = tail;
	tail->prev = head;
	tail->next = nullptr;
	len = 0;

	// <node pool>
	// head = new Node(NULL);
	// tail = new Node(NULL);
	// len = 0;
	// nodeArr.resize(NODE_MAX, nullptr);
}

Node* create_node(int data) {
	Node* node = new Node;
	node->data = data;
	node->prev = nullptr;
	node->next = nullptr;
	return node;

	// <node pool>
	// nodeArr[len] = new Node(data);
	// return nodeArr[len++];
}

void insert(int loc, vector<int> &datas) {
	int st = 0; // datas 배열 idx 시작점
	if (loc == 0) {
		if (len != 0) {
			Node* node = create_node(datas[0]);
			head->prev = node;
			node->next = head;
			head = node;
		}
		else{ 
			head = create_node(datas[0]);
			head->next = tail;
		}
		len++;
		st++;
	}

	Node* curr = head;
	for (int i = 1; i < loc; i++) curr = curr->next;

	for (int i = st; i < datas.size(); i++) {
		Node* node = create_node(datas[i]);

		node->next = curr->next;
		curr->next->prev = node;
		node->prev = curr;
		curr->next = node;
		curr = node;
		len++;
	}

	if (curr->next == nullptr || curr->next == tail) tail = curr;
}

void add(int data) {
	Node* curr = tail;
	Node* node = create_node(data);
	node->prev = curr;
	curr->next = node;
	tail = node;
	len++;
}

void remove(int loc, int cnt) {
	Node* curr = head;
	if (loc == 0) {
		for (int i = 0; i < cnt; i++) curr = curr->next;
		head = curr;
		head->prev = nullptr;
		len -= cnt;
		return;
	}

	for (int i = 1; i < loc; i++) curr = curr->next;
	Node* linker = curr;

	for (int i = 0; i < cnt; i++) curr = curr->next;

	linker->next = curr->next;
	curr->next->prev = linker;

	if(linker->next == nullptr || linker->next == tail) tail = linker;
	len -= cnt;
}

int main() {
	for (int test_case = 1; test_case < 11; test_case++) {
		init_list();

		int n; cin >> n;
		vector<int> datas(n);
		for (int i = 0; i < n; i++) cin >> datas[i];
		insert(0, datas);

		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			char command; cin >> command;
			int x, y, s;
			if (command == 'I') {
				cin >> x >> y;
				vector<int> pws;
				for (int idx = 0; idx < y; idx++) {
					cin >> s;
					pws.push_back(s);
				}
				insert(x, pws);
			}
			else if (command == 'A') {
				cin >> y;
				for (int idx = 0; idx < y; idx++) {
					cin >> s;
					add(s);
				}
			}
			else {
				cin >> x >> y;
				remove(x, y);
			}
		}

		cout << "#" << test_case << ' ';
		Node* curr = head;
		for (int i = 0; i < 10; i++) {
			cout << curr->data << ' ';
			curr = curr->next;
		}

		cout << '\n';
	}
	return 0;
}
