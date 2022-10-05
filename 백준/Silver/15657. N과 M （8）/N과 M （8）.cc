#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void init();
void dfs(int level, int last);

int N;
int M;
vector<int> nums; // 숫자 저장 배열
vector<int> seq; // 수열 저장 배열

void init() {
	cin >> N >> M;
	nums = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
}

void dfs(int level, int last) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = last; i < N; i++) {
		seq.push_back(nums[i]);
		dfs(level + 1, i);
		seq.pop_back();
	}
}

int main() {
	init();
	dfs(0,0);
	return 0;
}