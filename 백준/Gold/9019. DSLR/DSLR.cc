#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Info {
	int n;
	string ops;
};

void init();
void input();
void bfs();
void print_answer();

Info(*op[4])(int, string);
Info D(int num, string str);
Info S(int num, string str);
Info L(int num, string str);
Info R(int num, string str);

int T; // 테스트 케이스 수
int a; // 초기 값
int b; // 최종 값
vector<string> ans; // 답

vector<string> DB(10000);

void init() {
	op[0] = D;
	op[1] = S;
	op[2] = L;
	op[3] = R;
}

void input() {
	cin >> a >> b;
}

void bfs() {
	queue<Info> q;
	int used[10000] = {};

	q.push({a,""});
	DB[a] = "";
	used[a] = 1;
	while (!q.empty()) {
		Info now = q.front();
		q.pop();

		

		for (int i = 0; i < 4; i++) {
			Info tmp = op[i](now.n, now.ops);
			if (used[tmp.n]) continue;
			if (tmp.n == b) {
				ans.push_back(tmp.ops);
				return;
			}
			DB[tmp.n] = tmp.ops;
			used[tmp.n] = 1;
			q.push(tmp);
		}
	}
}

void print_answer() {
	for (int i = 0; i < T; i++) {
		cout << ans[i] << '\n';
	}
}

Info D(int num, string str) {
	Info ret;
	ret.n = (2 * num) % 10000;
	ret.ops = str + "D";
	return ret;
}

Info S(int num, string str) {
	Info ret;
	ret.n = num > 0 ? num - 1 : 9999;
	ret.ops = str + "S";
	return ret;
}

Info L(int num, string str) {
	Info ret;
	ret.n = ((10 * num) + (num / 1000)) % 10000;
	ret.ops = str + "L";
	return ret;
}

Info R(int num, string str) {
	Info ret;
	ret.n = ((num % 10) * 1000 + num / 10);
	ret.ops = str + "R";
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	init();
	for (int t = 0; t < T; t++) {
		input();
		bfs();
	}

	print_answer();
	
	return 0;
}