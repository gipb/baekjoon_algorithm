#include<iostream>
#include<math.h>
using namespace std;

typedef long long ll;

int main() {
    ll M = 1234567891;
    int r = 31;
    int L;
    ll ans = 0;
    cin >> L;
    char* str = new char[L+1];
    cin >> str;

    for (int i = 0; i < L; i++) {
        int j = str[i] - 'a'+1;
        ll p = 1;
        for (int k = 1; k <= i; k++) {
            p *= r;
            if (p > M)
                p %= M;
        }
        ans += j*p;
    }
    cout << ans % M;

    return 0;
}