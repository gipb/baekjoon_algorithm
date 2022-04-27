#include <iostream>
#include <vector>
using namespace std;

void Union(int ai, int bi);
int Find(int i);

vector<int> dat;

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return;
	dat[pb] = pa;
}

int Find(int i) {
	if (dat[i] == i) return i;
	return dat[i] = Find(dat[i]);
}

int main() {
	int N, E;
	cin >> N >> E;

	dat = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		dat[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	int cnt = 0;

	for (int i = 2; i <= N; i++) {
		if (Find(1) == Find(i)) cnt++;
	}

	cout << cnt;

	return 0;
}