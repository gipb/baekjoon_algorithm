#include<iostream>
#include<string>
using namespace std;

struct Node {
	int num;
	Node* prev;
	Node* next;
};

Node* head;
Node* tail;
int size_deque;

void init() {
	head = NULL;
	tail = NULL;
	size_deque = 0;
}

void push_front(int num) {
	Node* node = new Node;
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	if (head != NULL) {
		node->next = head;
		head->prev = node;
	}
	if (tail == NULL) {
		tail = node;
	}
	head = node;
	size_deque++;
}

void push_back(int num) {
	Node* node = new Node;
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	if (tail != NULL) {
		tail->next = node;
		node->prev = tail;
	}
	if (head == NULL) {
		head = node;
	}
	tail = node;
	size_deque++;
}

void pop_front() {
	if (!size_deque) cout << -1 << '\n';
	else {
		cout << head->num << '\n';
		Node* temp = head;
		head = temp->next;
		if(head != NULL) head->prev = NULL;
		delete temp;
		size_deque--;
	}
}

void pop_back() {
	if (!size_deque) cout << -1 << '\n';
	else {
		cout << tail->num << '\n';
		Node* temp = tail;
		tail = temp->prev;
		if(tail != NULL) tail->next = NULL;
		delete temp;
		size_deque--;
	}
}

void size() {
	cout << size_deque << '\n';
}

void empty() {
	if (size_deque) cout << 0 << '\n';
	else cout << 1 << '\n';
}

void front() {
	if (size_deque) cout << head->num << '\n';
	else cout << -1 << '\n';
}

void back() {
	if (size_deque) cout << tail->num << '\n';
	else cout << -1 << '\n';
}

int main()
{
	init();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string text;
		cin >> text;
		if (text == "push_front") {
			int num;
			cin >> num;
			push_front(num);
		}
		else if (text == "push_back") {
			int num;
			cin >> num;
			push_back(num);
		}
		else if (text == "pop_front") pop_front();
		else if (text == "pop_back") pop_back();
		else if (text == "size") size();
		else if (text == "empty") empty();
		else if (text == "front") front();
		else if (text == "back") back();
	}

	return 0;
}