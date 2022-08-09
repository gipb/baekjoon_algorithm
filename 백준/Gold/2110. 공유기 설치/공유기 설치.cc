#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void init();
int search_l(ll start, ll end);
bool check_valid(int l);

int N; // 집의 수
int C; // 공유기의 수

vector<int> house; // 집의 위치 저장 배열

int limit;

void init() {
	cin >> N >> C;

	house = vector<int>(N, 0);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		house[i] = x;
	}
	sort(house.begin(), house.end());
	limit = house[N - 1];
}

int search_l(ll start, ll end) {
	if (start >= end) {
		if (check_valid(end)) return end;
		else return end - 1;
	}
	int mid = (start + end) / 2;
	bool isValid = check_valid(mid);
	if (isValid) return search_l(mid + 1, end);
	else return search_l(start, mid);
}

bool check_valid(int l) {
	int cnt = 1;
	int pre_index = 0;
	for (int i = 1; i < N; i++) {
		if (house[i] - house[pre_index] < l) continue;
		pre_index = i;
		cnt++;
		if (cnt == C) return true;
	}

	return false;
}

int main() {
	init();
	int ans = search_l(0, limit);
	cout << ans;
	return 0;
}