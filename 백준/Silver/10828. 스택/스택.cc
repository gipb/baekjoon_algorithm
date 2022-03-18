#include<iostream>
#include<string>
using namespace std;

struct Node {
	int num;
	Node* next;
};

Node* head;
int size_stack;

void init() {
	head = NULL;
	size_stack = 0;
}

void push(int num) {
	Node* node = new Node;
	node->num = num;
	node->next = NULL;
	if (head != NULL) {
		node->next = head;
	}
	head = node;
	size_stack++;
}

void size(){
	cout << size_stack << '\n';
}

void pop() {
	if (size_stack) {
		cout << head->num << '\n';
		Node* top = head;
		head = top->next;
		delete top;
		size_stack--;
	}
	else cout << -1 << '\n';
}

void empty() {
	if (size_stack) cout << 0 << '\n';
	else cout << 1 << '\n';
}

void top() {
	if (size_stack) cout << head->num << '\n';
	else cout << -1 << '\n';
}

int main()
{
	init();
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
		else if (order == "top") top();
	}

	return 0;
}