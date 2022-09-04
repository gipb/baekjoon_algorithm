#include <iostream>
using namespace std;

int LCM(int a, int b) {
	int gcd;
	int ta = a;
	int tb = b;
	while (ta*tb) {
		ta > tb ? ta %= tb : tb %= ta;
		if (ta == 0) gcd = tb;
		if (tb == 0) gcd = ta;
	}

	return a * b / gcd;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int limit = LCM(m, n);

		int ans = -1;
		int tmp = x;
		while (tmp <= limit) {
			if (tmp % n == y || tmp % n == (y-n)) {
				ans = tmp;
				break;
			}
			tmp += m;
		}

		cout << ans << '\n';
	}

	return 0;
}