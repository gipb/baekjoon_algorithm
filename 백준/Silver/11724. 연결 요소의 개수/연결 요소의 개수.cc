#include <iostream>
#include <vector>
using namespace std;

vector<int> dat;

int Find(int a) {
	if (dat[a] == a) return a;
	return dat[a] = Find(dat[a]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	
	if (pa != pb) dat[pb] = pa;
}

int main() {

	int N, M; // node의 수 , edge 의 수
	cin >> N >> M;

	dat = vector<int>(N + 1, 0);
	for (int i = 0; i < N + 1; i++) {
		dat[i] = i;
	}

	// Union - Find 활용
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	// 그룹 정보 정리
	for (int i = 1; i <= N; i++) {
		Find(i);
	}

	vector<int> group(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		group[dat[i]] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (group[i]) ans++;
	}

	cout << ans;

	return 0;
}