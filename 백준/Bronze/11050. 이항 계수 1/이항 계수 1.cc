#include<iostream>
using namespace std;

int main() {
    int arr[11][11] = {};
    int N, K;
    cin >> N>> K;

    for (int y = 0; y < 11; y++) {
        for (int x = 0; x <= y; x++) {
            if (x == 0 || x == y)
                arr[y][x] = 1;
            else
                arr[y][x] = arr[y - 1][x - 1] + arr[y - 1][x];
        }
    }

    cout << arr[N][K];
    return 0;

}