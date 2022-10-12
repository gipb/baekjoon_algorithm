#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int pi; // 부모 노드 인덱스
	int li; // 왼쪽 자식 노드 인덱스
	int ri; // 오른쪽 자식 노드 인덱스
};

void init();
void preorder(char node);
void inorder(char node);
void postorder(char node);

vector<Node> tree;
vector<int> used;

int N;

void init() {
	cin >> N;

	tree = vector<Node>(100); // 알파벳을 바로 활용하기 위해
	for (int i = 0; i < N; i++) {
		char p, l, r;
		cin >> p >> l >> r;
		if (p == 'A') tree[p].pi = -1;
		if (l == '.') tree[p].li = -1;
		else {
			tree[p].li = l;
			tree[l].pi = p;
		}
		if (r == '.') tree[p].ri = -1;
		else {
			tree[p].ri = r;
			tree[r].pi = p;
		}
	}
}

void preorder(char node) {
	cout << node;
	if (tree[node].li != -1) preorder(tree[node].li);
	if (tree[node].ri != -1) preorder(tree[node].ri);
}

void inorder(char node) {
	if (tree[node].li != -1) inorder(tree[node].li);
	cout << node;
	if (tree[node].ri != -1) inorder(tree[node].ri);
}

void postorder(char node) {
	if (tree[node].li != -1) postorder(tree[node].li);
	if (tree[node].ri != -1) postorder(tree[node].ri);
	cout << node;
}

int main() {
	init();

	used = vector<int>(100, 0);
	preorder('A');
	cout << '\n';

	used = vector<int>(100, 0);
	inorder('A');
	cout << '\n';
	
	used = vector<int>(100, 0);
	postorder('A');
	cout << '\n';

	return 0;
}