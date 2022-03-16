#include<iostream>
using namespace std;

int main() {
	// 입력
	int N;
	int arr[10001] = {};
	cin >> N;
	
	// 배열 만들기
	int i = 1;
	int num = 666;
	while (i <= 10000) {
		int cnt = 0;
		int temp = num;
		while (temp) {
			if (temp % 1000 == 666) cnt++;
			temp /= 10;
		}
		if (cnt) {
			arr[i] = num;
			i++;
		}
		num++;
	}

	// 출력
	cout << arr[N];

	return 0;
}