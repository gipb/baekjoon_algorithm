#include <iostream>
#include <vector>
using namespace std;

void init();
int search_m(int start, int end);
bool check_valid(int m);

vector<int> money;

int N; // 지방의 수
int total; // 총 예산
int max_money = 0; // 최대 예산

void init() {
	cin >> N;
	money = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		if (max_money < money[i]) max_money = money[i];
	}
	cin >> total;
}

int search_m(int start, int end) {
	if (start >= end) {
		if (check_valid(end)) return end;
		else return end - 1;
	}
	int mid = (start + end) / 2;
	bool isValid = check_valid(mid);
	if (isValid) return search_m(mid+1, end);
	else return search_m(start, mid);
}

bool check_valid(int m) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += money[i] > m ? m : money[i];
		if (ret > total) return false;
	}
	return true;
}

int main() {
	init();
	int ans = search_m(0, max_money);
	cout << ans;
	return 0;
}