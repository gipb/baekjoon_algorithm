#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<int>> table;
vector<int> dat;
int limit;
int min_value = 21000000;
vector<int> start;
vector<int> link;
int last=0;

void calc() {
	start.clear();
	link.clear();
	for (int i = 0; i < N; i++) {
		if (dat[i]) start.push_back(i);
		else link.push_back(i);
	}

	int sStart = 0;
	int sLink = 0;
	for (int r = 0; r < limit; r++) {
		for (int c = 0; c < limit; c++) {
			sStart += table[start[r]][start[c]];
			sLink += table[link[r]][link[c]];
		}
	}

	int sub = sStart > sLink ? sStart - sLink : sLink - sStart;

	if (min_value > sub) min_value = sub;
}

void dfs(int level) {
	if (level == limit) {
		calc();
		return;
	}
	for (int i = last; i < N; i++) {
		if (dat[i]) continue;
		int temp = last;
		last = i;
		dat[i] = 1;
		dfs(level + 1);
		dat[i] = 0;
		last = temp;
	}
}

void init() {
	table = vector<vector<int>>(N, vector<int>(N, 0));
	dat = vector<int>(N, 0);
}

int main()
{
	// 사람 수 입력
	cin >> N;
	// 능력치 테이블 초기화 & 능력치 입력
	init();
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) cin >> table[r][c];
	}

	// 팀 정원
	limit = N / 2;

	dfs(0);

	cout << min_value;

	return 0;
}