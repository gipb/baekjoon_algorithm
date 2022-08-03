#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void init();
int btn_cnt();
void dfs(int level);
int min(int a, int b);
int abs(int a);

int N; // 채널
int M; // 고장난 버튼의 수
int broken[10] = {};
vector<int> channel;

int channel_size = 0;
int channel_path = 0;
int dfs_ret = INT_MAX;

void init() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		broken[num] = 1;
	}

	// 자릿 수 별 숫자 저장
	int tmp = N;
	int cnt = 0;
	while (tmp) {
		cnt++;
		tmp /= 10;
	}

	// 0이 들어오는 경우 한자리 수! (반례)
	if (N == 0) cnt = 1;
	channel = vector<int>(cnt, 0);
	channel_size = cnt;

	tmp = N;
	for (int i = 0; i < cnt; i++) {
		channel[cnt - 1 - i] = tmp % 10;
	}
}

int btn_cnt() {
	// 숫자 버튼을 안누르는 경우
	int cnt1 = abs(100 - N);

	// 모든 숫자 버튼 고장일 경우 리턴
	if (M == 10) return cnt1;

	// 고장난 버튼이 없는 경우
	if (M == 0) {
		int cnt2 = channel_size;
		return cnt2 > cnt1 ? cnt1 : cnt2;
	}

	// 높은 자릿수에서 내려오는 것 체크
	int cnt3 = 0;
	int num3 = 0;
	
	for (int i = 1; i < 10; i++) {
		if (broken[i]) continue;
		if (broken[0]) {
			for (int j = 0; j <= channel_size; j++) {
				num3 *= 10;
				num3 += i;
			}
			break;
		}
		else {
			num3 = i;
			for (int j = 0; j < channel_size; j++) {
				num3 *= 10;
			}
			break;
		}
	}

	cnt3 = abs(num3 - N) + channel_size + 1;

	// 낮은 자릿수에서 올라가는 것 체크
	int cnt4 = INT_MAX;
	if (channel_size > 1) {
		int num4 = 0;

		for (int i = 9; i >= 0; i--) {
			if (broken[i]) continue;
			for (int j = 0; j < channel_size - 1; j++) {
				num4 *= 10;
				num4 += i;
			}
			break;
		}

		cnt4 = abs(N - num4) + channel_size - 1;
	}
	// 같은 자릿수 체크

	dfs(0);
	int cnt5 = dfs_ret;

	return min(min(cnt1, cnt3), min(cnt4, cnt5));
}

void dfs(int level) {
	if (level == channel_size) {
		int cnt = channel_size + abs(N - channel_path);
		dfs_ret = min(dfs_ret, cnt);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (broken[i]) continue;
		channel_path *= 10;
		channel_path += i;
		dfs(level + 1);
		channel_path -= i;
		channel_path /= 10;
	}
}

int min(int a, int b) {
	return a > b ? b : a;
}

int abs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	init();
	int ans = 0;
	
	ans = btn_cnt();

	cout << ans;

	return 0;
}