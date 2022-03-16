#include<iostream>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 변수 선언
	int N;
	int num;
	int arr[10001] = {};
	cin >> N;

	// 입력 및 정렬
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num]++;
	}
	
	// 출력
	for (int i = 0; i < 10001; i++) {
		int j = arr[i];
		while (j) {
			cout << i << '\n';
			j--;
		}
	}

	return 0;
}