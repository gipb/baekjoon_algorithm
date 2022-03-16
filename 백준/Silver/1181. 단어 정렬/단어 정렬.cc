#include<iostream>
#include<cstring>
using namespace std;

int N;
char** temp;

void Merge(char** arr, int start, int mid, int end) {
	int i = start;
	int j = mid+1;
	int index = start;
	while (i <= mid && j <= end) {
		int len_i = strlen(arr[i]);
		int len_j = strlen(arr[j]);
		if (len_i > len_j) {
			temp[index] = arr[j];
			j++;
		}
		else if (len_i < len_j) {
			temp[index] = arr[i];
			i++;
		}
		else {
			int flag = 0;
			for (int k = 0; k < len_i; k++) {
				if (arr[i][k] == arr[j][k]) continue;
				if (arr[i][k] > arr[j][k]) {
					temp[index] = arr[j];
					j++;
					flag = 1;
					break;
				}
				else if (arr[i][k] < arr[j][k]){
					temp[index] = arr[i];
					i++;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				temp[index] = arr[i];
				i++;
			}
			
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
	for (int p = start; p <= end; p++) 
		arr[p] = temp[p];
}

void Merge_sort(char** arr, int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		Merge_sort(arr, start, mid);
		Merge_sort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}

int main() {
	// 입력 및 할당
	cin >> N;
	char** arr = new char* [N];
	temp = new char* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new char[51];
		temp[i] = new char[51];
	}
	for (int i = 0; i < N; i++) cin >> arr[i];

	// 정렬
	Merge_sort(arr, 0, N - 1);

	// 출력
	for (int i = 0; i < N; i++) {
		if (i >= 1 && !strcmp(arr[i - 1], arr[i])) continue;
		cout << arr[i] << "\n";
	}

	// 할당 해제
	for (int i = 0; i < N; i++) {
		delete[] arr[i];		
	}

	delete[] temp;
	delete[] arr;
	return 0;
}