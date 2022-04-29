#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
	int value;
	int index;
};

bool cmp(Info left, Info right) {
	return left.value < right.value;
}

int main() {

	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Info> pos;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pos.push_back({ num, i });
	}

	vector<int> ans(N, 0);

	sort(pos.begin(), pos.end(), cmp);

	int cnt = 0;
	ans[pos[0].index] = 0;
	for (int i = 1; i < N; i++) {
		if (pos[i].value > pos[i - 1].value) cnt++;
		ans[pos[i].index] = cnt;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}