#include <iostream>
using namespace std;

#define ll long long

ll f(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll ret = f(a, b / 2, c);
	ret = ret * ret % c;

	if (b % 2) {
		return (ret * a) % c;
	}
	else {
		return ret;
	}
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	ll ans = f(a, b, c);
	cout << ans;

	return 0;
}