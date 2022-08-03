#include <iostream>
#include <map>
using namespace std;

int N; // 숫자 카드의 개수
int M; // 확인할 숫자 카드의 개수

map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		m[num]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		cout << (m[num] > 0 ? 1 : 0) << ' ';
	}
	return 0;
}