#include <iostream>
#include <cstring>
using namespace std;

void change_wheel(int turn_dir[4]);
void check_dir(int index, int turn, int turn_dir[4]);

string wheel[4];	// 바퀴 상태 배열

void change_wheel(int turn_dir[4]) {
	for (int i = 0; i < 4; i++) {
		if (!turn_dir[i]) continue;
		if (turn_dir[i] > 0) {
			wheel[i] = wheel[i].substr(7,1) + wheel[i].substr(0, 7);
		}
		else {
			wheel[i] = wheel[i].substr(1, 7) + wheel[i].substr(0, 1);
		}
	}
}

void check_dir(int index, int turn, int turn_dir[4]) {
	int wi = index - 1;
	turn_dir[wi] = turn;

	// 처음 주어진 톱니바퀴보다 인덱스가 큰 톱니바퀴들 방향 결정
	int tmp = wi;
	for (int i = 1; wi + i < 4; i++) {
		if (wheel[tmp][2] == wheel[wi + i][6]) break;
		turn_dir[wi + i] = 0 - turn_dir[tmp];
		tmp++;
	}
	
	// 인덱스가 작은 톱니바퀴 방향 결정
	tmp = wi;
	for (int i = 1; wi - i >= 0; i++) {
		if (wheel[tmp][6] == wheel[wi - i][2]) break;
		turn_dir[wi - i] = 0 - turn_dir[tmp];
		tmp--;
	}
}

int main() {
	int K;				// 회전 수

	for (int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int index, turn;
		cin >> index >> turn;

		int turn_dir[4] = {};
		check_dir(index, turn, turn_dir);
		change_wheel(turn_dir);
	}

	// 점수 계산
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == '1') answer += (1 << i);
	}

	cout << answer;

	return 0;
}