#include<iostream>
using namespace std;

int arr[15][15] = {};

void make_apart() {
    for (int i = 0; i < 15; i++)
        arr[0][i] = i;
    for (int y = 1; y < 15; y++) {
        for (int x = 0; x < 15; x++) {
            int sum = 0;
            for (int b = 0; b <= x; b++)
                sum += arr[y - 1][b];
            arr[y][x] = sum;
        }
    }
}

int main() {
    int T;
    int a, b;
    cin >> T;
    make_apart();
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }


    return 0;
}