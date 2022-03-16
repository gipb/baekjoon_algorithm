#include<iostream>
#include<vector>
using namespace std;

struct Work {
	int time;
	int benefit;
};

int N;
vector<Work> schedule;
int max_benefit = 0;
int benefit = 0;

void work(int index) {
	if (benefit > max_benefit) {
		max_benefit = benefit;
	}
	for (index; index < N; index++) {
		Work now = schedule[index];
		if (index + now.time > N) continue;
		benefit += now.benefit;
		work(index + now.time);
		benefit -= now.benefit;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t, p;
		cin >> t >> p;
		schedule.push_back({ t,p });
	}

	work(0);
	cout << max_benefit;

	return 0;
}