#include <iostream>
#include <vector>
using namespace std;

struct Obj {
	int w; // 무게
	int v; // 가치
};

void init();
int find_value(int num, int weight);

int N; // 물품 수
int K; // 버티는 최대 무게

vector<Obj> objs;
vector<vector<int>> value;

void init() {
	cin >> N >> K;
	value = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		objs.push_back({w,v});
	}
}

int find_value(int num, int weight) {
	if (num == 0) return value[num][weight];
	if (value[num][weight]) return value[num][weight];
	// index 가 num-1 인 물품을 포함하지 않는 경우
	int v1 = find_value(num - 1, weight);
	if (objs[num - 1].w > weight) return value[num][weight] = v1;
	// index 가 num-1 인 물품을 포함하는 경우
	int v2 = find_value(num - 1, weight - objs[num - 1].w) + objs[num - 1].v;
	
	return value[num][weight] = v1 > v2 ? v1 : v2;
}

int main() {
	init();
	int ans = find_value(N, K);
	cout << ans;
	return 0;
}