#include<iostream>
using namespace std;


void star(char** arr, int num, int y, int x) {
	if (num == 1) {
		arr[y][x] = '*';
		return;
	}
	int offset = num / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			star(arr, offset, y + offset * i, x + offset * j);
		}
	}
	
}

int main() {
	// 입력
	int num;
	cin >> num;

	// 배열 할당
	char** arr = new char* [num];
	for (int i = 0; i < num; i++) {
		arr[i] = new char[num];
	}

	// 재귀 호출
	star(arr, num, 0, 0);

	// 출력
	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			if (arr[y][x] != '*') {
				cout << ' ';
				continue;
			}
			cout << arr[y][x];
		}
		cout << endl;
	}

	// 할당 해제
	for (int i = 0; i < num; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}