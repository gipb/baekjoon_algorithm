#include <iostream>
#include <map>
using namespace std;

#define ll long long int
#define D 1000000007

map<ll, ll> dp;

ll Fibo(ll n) {
	if (dp[n]) return dp[n];
	if (n == 0) return dp[0] = 0;
	if (n == 1) return dp[1] = 1;
	if (n == 2) return dp[2] = 1;
	if (n % 2) {
		ll a = n / 2;
		return dp[n] = ((Fibo(a)*Fibo(a)) % D + (Fibo(a + 1)*Fibo(a + 1)) % D) % D;
	}
	ll a = n / 2;
	return dp[n] = ((Fibo(a + 1)*Fibo(a)) % D + (Fibo(a)*Fibo(a - 1)) % D) % D;
}

int main() {
	ll n;
	cin >> n;
	cout << Fibo(n);
	return 0;
}