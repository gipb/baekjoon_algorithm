#include<iostream>
using namespace std;

int N;
int temp[1000000] = {};

void Merge(int* arr, int start, int mid, int end) {
	int index = start;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] > arr[j]) {
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
	else {
		for (i; i <= mid; i++) {
			temp[index] = arr[i];
			index++;
		}
	}
	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}

void Merge_sort(int* arr, int start, int end) {
	int mid = (end + start) / 2 ;
	if (start < end) {
		Merge_sort(arr, start, mid);
		Merge_sort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
};

int main() {
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	Merge_sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}

	delete[] arr;
	return 0;
}