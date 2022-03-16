#include<iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int max = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum > max && sum <= M)
                    max = sum;
            }
        }
    }

    cout << max;

    return 0;
}