#include <iostream>
#include <vector>
using namespace std;

void init();
int search_length(int start, int end);
bool check(int n);

int N; // 나무의 수
int M; // 필요한 길이
int max_h = 0; // 가장 높은 나무 높이

vector<int> tree; // 나무의 높이를 저장할 배열

void init() {
	cin >> N >> M;
	tree = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (tree[i] > max_h) max_h = tree[i];
	}
}

// 이분 탐색
int search_length(int start, int end) {
	if (start >= end) return end-1;

	// 중간 값을 설정한다.
	int mid = (start + end) / 2;

	// 중간 값이 문제의 조건에 맞는지 판단
	bool isValid = check(mid);

	// 문제의 조건에 맞다면 더 높은 높이에서 조건에 맞는지 확인
	if (isValid) return search_length(mid+1, end);

	// 조건에 맞지 않다면 더 낮은 높이에서 조건에 맞는지 확인
	else return search_length(start, mid);
}

bool check(int n) {
	long long cnt = 0;

	// 문제 조건 충족 여부 확인
	for (int i = 0; i < N; i++) {
		if (tree[i] <= n) continue;
		cnt += (tree[i] - n);
		if (cnt >= M) return true;
	}
	return false;
}

int main() {
	// initialize
	init();

	// 이분 탐색을 이용한 탐색
	int ans = search_length(0, max_h);
	
	// 출력
	cout << ans;
	return 0;
}
