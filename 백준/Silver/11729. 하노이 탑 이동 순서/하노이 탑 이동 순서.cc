#include<iostream>
#include<cmath>
using namespace std;

int cnt = 0;

void hanoi(int num, int a, int b) {
	if (num == 1) {
		cnt++;
		cout << a << ' ' << b << '\n';
		return;
	}
	int c = 6 - a - b;
	hanoi(num - 1, a, c);
	cout << a << ' ' << b << '\n';
	cnt++;
	hanoi(num - 1, c, b);
}

int main() {
	int N;
	cin >> N;
	cout << (int)(pow(2, N) - 1) << '\n';
	hanoi(N, 1, 3);
	return 0;
}