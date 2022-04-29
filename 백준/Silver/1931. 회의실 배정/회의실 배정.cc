#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
	int s, e;
};

bool cmp(Meeting left, Meeting right) {
	return left.e == right.e ? left.s < right.s : left.e < right.e;
}

int main() {
	int N;
	cin >> N;

	vector<Meeting> schedule;

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		schedule.push_back({ s,e });
	}

	// 빨리 끝나는 회의 순서대로 정렬
	// 끝나는 시간이 같다면 빨리 시작하는 회의 순서대로 정렬
	sort(schedule.begin(), schedule.end(), cmp);

	int ans = 0;

	// 회의 시작 가능 시간
	int start = 0;

	for (int i = 0; i < schedule.size(); i++) {
		// 회의 시작 가능한 시간 체크
		if (start > schedule[i].s) continue;

		// 회의 시작 가능한 시간 업데이트 및 회의 수 카운트
		start = schedule[i].e;
		ans++;
	}

	cout << ans;

	return 0;
}