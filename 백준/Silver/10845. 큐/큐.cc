#include<iostream>
#include<string>
using namespace std;

struct Node {
	int num;
	Node* next;
};

Node* head;
Node* tail;
int size_queue;

void init_queue() {
	head = NULL;
	tail = NULL;
	size_queue = 0;
}

void push(int num) {
	Node* node = new Node;
	node->num = num;
	node->next = NULL;
	if (head == NULL) {
		head = node;
	}
	if (tail != NULL) {
		tail->next = node;
	}
	tail = node;
	size_queue++;
}

void pop() {
	if (!size_queue) cout << -1 << '\n';
	else {
		cout << head->num << '\n';
		Node* temp = head;
		head = temp->next;
		delete temp;
		size_queue--;
	}
}

void size() {
	cout << size_queue << '\n';
}

void empty() {
	if (size_queue) cout << 0 << '\n';
	else cout << 1 << '\n';
}

void front() {
	if (size_queue) cout << head->num << '\n';
	else cout << -1 << '\n';
}

void back() {
	if (size_queue) cout << tail->num << '\n';
	else cout << -1 << '\n';
}


int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int num;
			cin >> num;
			push(num);
		}
		else if (order == "pop") pop();
		else if (order == "size") size();
		else if (order == "empty") empty();
		else if (order == "front") front();
		else if (order == "back") back();
	}
	return 0;
}