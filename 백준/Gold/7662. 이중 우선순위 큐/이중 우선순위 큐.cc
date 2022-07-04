#include<iostream>
#include<vector>
using namespace std;

void swap(int* a, int* b);
int check_min_max(int i);
void push(int num);
void max_up(int i);
void min_up(int i);

// down 동작은 grandchild 뿐 아니라 child도 확인해야 함!
void max_down(int i);
void min_down(int i);

int find_target(int i, int type);

void del_max();
void del_min();
int find_max();
int find_min();

vector<int> mmh;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// min_node 1 max_node 0
int check_min_max(int i) {
	int ret = 0;
	i += 1;
	while (i) {
		i >>= 1;
		ret++;
	}
	return ret % 2;
}

void push(int num) {
	int index = mmh.size();
	mmh.push_back(num);
	if (!index) return;

	int tar_index = (index - 1) / 2;

	// min_node
	if (check_min_max(index)) {
		if (mmh[tar_index] < mmh[index]) {
			swap(&mmh[tar_index], &mmh[index]);
			max_up(tar_index);

		}
		else min_up(index);
	}

	// max_node
	else {
		if (mmh[tar_index] > mmh[index]) {
			swap(&mmh[tar_index], &mmh[index]);
			min_up(tar_index);
		}
		else max_up(index);
	}
}

// up => check the grandparents node

void max_up(int i) {
	if (i < 3) return;
	int tar_index = (i - 3) / 4;
	if (mmh[tar_index] < mmh[i]) {
		swap(&mmh[tar_index], &mmh[i]);
		max_up(tar_index);
	}
}

void min_up(int i) {
	if (i < 3) return;
	int tar_index = (i - 3) / 4;
	if (mmh[tar_index] > mmh[i]) {
		swap(&mmh[tar_index], &mmh[i]);
		min_up(tar_index);
	}
}

// down => check the children and grandchildren node

void max_down(int i) {
	int tar_index = 2 * i + 1;
	if (tar_index >= mmh.size()) return;
	tar_index = find_target(i, 0);
	if (tar_index == -1) return;

	if (mmh[i] < mmh[tar_index]) {
		swap(&mmh[i], &mmh[tar_index]);
		if (tar_index >= 4 * i + 3) {
			int p_tar = (tar_index - 1) / 2;
			if (mmh[tar_index] < mmh[p_tar]) {
				swap(&mmh[tar_index], &mmh[p_tar]);
			}
			max_down(tar_index);
		}
	}
}

void min_down(int i) {
	int tar_index = 2 * i + 1;
	if (tar_index >= mmh.size()) return;
	tar_index = find_target(i, 1);
	if (tar_index == -1) return;

	if (mmh[i] > mmh[tar_index]) {
		swap(&mmh[i], &mmh[tar_index]);
		if (tar_index >= 4 * i + 3) {
			int p_tar = (tar_index - 1) / 2;
			if (mmh[tar_index] > mmh[p_tar]) {
				swap(&mmh[tar_index], &mmh[p_tar]);
			}
			min_down(tar_index);
		}
	}
}

int find_target(int i, int type) {
	int tmp[] = { 2 * i + 1, 2 * i + 2,
		4 * i + 3, 4 * i + 4, 4 * i + 5, 4 * i + 6 };
	int ret = -1;
	// min_node
	if (type) {
		// find minimum node
		for (int t = 0; t < 6; t++) {
			if (tmp[t] >= mmh.size()) return ret;
			if (ret == -1) ret = tmp[t];
			if (mmh[ret] > mmh[tmp[t]]) ret = tmp[t];
		}
	}
	// max_node
	else {
		// find maximum node
		for (int t = 0; t < 6; t++) {
			if (tmp[t] >= mmh.size()) return ret;
			if (ret == -1) ret = tmp[t];
			if (mmh[ret] < mmh[tmp[t]]) ret = tmp[t];
		}
	}
	return ret;
}

void del_max() {
	if (!mmh.size()) return;
	if (mmh.size() < 3) {
		mmh.pop_back();
		return;
	}

	int index = mmh.size() - 1;
	if (mmh[1] > mmh[2]) {
		swap(&mmh[1], &mmh[index]);
		mmh.pop_back();

		max_down(1);
	}
	else {
		swap(&mmh[2], &mmh[index]);
		mmh.pop_back();

		max_down(2);
	}
}

void del_min() {
	if (!mmh.size()) return;
	int index = mmh.size() - 1;
	swap(&mmh[0], &mmh[index]);
	mmh.pop_back();

	min_down(0);
}

int find_max() {
	if (mmh.size() > 2) return mmh[1] > mmh[2] ? mmh[1] : mmh[2];
	if (mmh.size() <= 2) return mmh.back();
}

int find_min() {
	return mmh.front();
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		mmh.clear();
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char op;
			int num;
			cin >> op >> num;
			if (op == 'I') {
				push(num);
			}
			else if (num == 1) del_max();
			else del_min();
		}

		if (mmh.size()) {
			cout << find_max() << ' ' << find_min() << '\n';
		}
		else cout << "EMPTY\n";

	}
	return 0;
}