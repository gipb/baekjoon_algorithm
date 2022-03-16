#include<iostream>
using namespace std;

struct Position {
	int x;
	int y;
};

Position* temp;

void Merge(Position* arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int index = start;
	while (i <= mid && j <= end) {
		if (arr[i].x > arr[j].x) {
			temp[index] = arr[j];
			j++;
		}
		else if (arr[i].x < arr[j].x) {
			temp[index] = arr[i];
			i++;
		}
		else if (arr[i].y > arr[j].y) {
			temp[index] = arr[j];
			j++;
		}
		else {
			temp[index] = arr[i];
			i++;
		}
		index++;
	}
	if (i > mid) {
		for (j; j <= end; j++) {
			temp[index] = arr[j];
			index++;
		}
	}
	else if (j > end) {
		for (i; i <= mid; i++) {
			temp[index] = arr[i];
			index++;
		}
	}
	for (int k = start; k <= end; k++) {
		arr[k] = temp[k];
	}
}

void Merge_sort(Position* arr, int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		Merge_sort(arr, start, mid);
		Merge_sort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}

int main() {
	// 할당 및 개수 입력
	int N;
	cin >> N;
	Position* arr = new Position[N];
	temp = new Position[N];

	// 좌표 입력
	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	// 정렬
	Merge_sort(arr, 0, N - 1);

	// 출력
	for (int i = 0; i < N; i++) {
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}

	// 할당 해제
	delete[] temp;
	delete[] arr;

	return 0;
}