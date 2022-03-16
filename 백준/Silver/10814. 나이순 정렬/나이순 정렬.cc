#include<iostream>
using namespace std;

struct Member {
	int id;
	int age;
	char name[101];
};

Member* temp;

void Merge(Member* arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int index = start;
	while (i <= mid && j <= end) {
		if (arr[i].age > arr[j].age) {
			temp[index] = arr[j];
			j++;
		}
		else if (arr[i].age < arr[j].age) {
			temp[index] = arr[i];
			i++;
		}
		else if (arr[i].id > arr[j].id) {
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

void Merge_sort(Member* arr, int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		Merge_sort(arr, start, mid);
		Merge_sort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}

int main() {
	// 입력 및 할당
	int N;
	cin >> N;
	Member* arr = new Member[N];
	temp = new Member[N];
	for (int i = 0; i < N; i++) {
		arr[i].id = i;
		cin >> arr[i].age >> arr[i].name;
	}

	// 정렬
	Merge_sort(arr, 0, N - 1);

	// 출력
	for (int i = 0; i < N; i++) {
		cout << arr[i].age << ' ' << arr[i].name << '\n';
	}

	// 할당 해제
	delete[] arr;
	delete[] temp;

	return 0;
}