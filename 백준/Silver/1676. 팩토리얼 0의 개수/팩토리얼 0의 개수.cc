#include <iostream>
using namespace std;

int main() {

	int N;
	// 소인수 2의 개수는 항상 5보다 많기에 5만 카운트한다.
	int cnt_5 = 0;
	cin >> N;

	while (N) {
		int tmp = N;
		while (1) {
			if (tmp % 5) break;
			tmp /= 5;
			cnt_5++;
		}
		N--;
	}

	cout << cnt_5;

	return 0;
}