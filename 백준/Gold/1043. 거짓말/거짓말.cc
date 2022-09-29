#include <iostream>
#include <vector>
using namespace std;

void init();
void create_party();
void check_party();

int Find(int a);
void Union(int a, int b);

int N; // 사람의 수
int M; // 파티의 수

vector<int> know_truth;
vector<vector<int>> party;
vector<int> parent;
int ans;

void init() {
	cin >> N >> M;
	know_truth = vector<int>(N + 1);
	party = vector<vector<int>>(M, vector<int>());
	parent = vector<int>(N + 1, 0);

	for (int i = 0; i < N + 1; i++) {
		parent[i] = i;
	}

	ans = M;

	int truth;
	cin >> truth;
	for (int i = 0; i < truth; i++) {
		int idx;
		cin >> idx;
		know_truth[idx] = 1;
	}
}

void create_party() {
	for (int i = 0; i < M; i++) {
		int party_size;
		cin >> party_size;
		for (int j = 0; j < party_size; j++) {
			int idx;
			cin >> idx;
			party[i].push_back(idx);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 1; j < party[i].size(); j++) {
			Union(party[i][0], party[i][j]);
		}
	}
}

void check_party() {
	for (int i = 0; i < M; i++) {
		if (know_truth[Find(party[i][0])]) ans--;
	}
}

int Find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = Find(parent[a]);
	}
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa != pb) {
		parent[pb] = pa;
		if (know_truth[pb]) know_truth[pa] = 1;
		if (know_truth[pa]) know_truth[pb] = 1;
	}
}

int main() {
	init();
	create_party();
	check_party();
	cout << ans;
	return 0;
}