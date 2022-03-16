#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    int cnt = 1;
    int num = N;
    while (N / 10) {
        cnt++;
        N /= 10;
    }
    for (int i = num - 9 * cnt; i < num; i++) {
        M = i;
        for (int j = 1; j <= cnt; j++) {
            M += (i % (int)(pow(10, j))) / (int)(pow(10, j - 1));
        }
        if (num == M) {
            cout << i;
            break;
        }
        if (i == num - 1)
            cout << 0;
    }

    return 0;
}