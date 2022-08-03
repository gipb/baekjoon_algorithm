#include <iostream>
#include <vector>
using namespace std;

void init();
int search_length(long long start, long long end);
bool check(long long l);

int K; // 이미 가지고 있는 랜선의 개수
int N; // 필요한 랜선의 개수
int max_l = 0; // 최대 길이

vector<int> lan;

void init() {
	cin >> K >> N;
	lan = vector<int>(K, 0);
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		if (max_l < lan[i]) max_l = lan[i];
	}
}

int search_length(long long start, long long end) {
	// 탈출 조건
	if (start >= end) {
        if(check(end)) return end;
        return end - 1;
    }
	long long mid = (start + end) / 2;
	
	// 조건에 유효한지 체크
	bool isValid = check(mid);

	// 유효할 경우 최댓값이 더 있는지 체크
	if (isValid) return search_length(mid + 1, end);

	// 유효하지 않을 경우 더 작은 길이 체크
	else return search_length(start, mid);
}

bool check(long long l) {
	long long cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += (lan[i] / l);
		if (cnt >= N) return true;
	}
	return false;
}

int main() {
	//initialize
	init();

	// 이분 탐색을 이용한 정답 찾기
	int ans = search_length(1, max_l);

	// 출력
	cout << ans;
	return 0;
}