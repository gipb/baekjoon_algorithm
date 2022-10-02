#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void init();
void dijkstra(int node);
int find_next_min(int node);

int N; // 마을, 학생 수 (node)
int M; // 도로 수 (edge)
int X; // 모이는 곳

vector<vector<int>> MAP;
vector<vector<int>> cost;
vector<int> visited;
int ans = 0;

void init() {
	cin >> N >> M >> X;

	MAP = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	cost = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		MAP[from][to] = time;
	}
}

void dijkstra(int node) {
	// 연결되어 있는 노드 먼저 갱신
	for (int i = 1; i <= N; i++) {
		if (i == node) continue;
		cost[node][i] = MAP[node][i];
	}

	visited = vector<int>(N + 1, 0);

	visited[node] = 1;
	int now = node;
	while (true) {
		// 현재 노드에서 가장 가까운 다음 노드 탐색
		int next = find_next_min(node);
		if (next == -1) break;
		visited[next] = 1;

		// 이미 X까지의 거리가 확정되었다면 다른 곳은 볼 필요 없다.
		if (next == X) return;

		// 그 노드에서 다른 노드들까지의 최소 거리 갱신
		for (int i = 1; i <= N; i++) {
			if (visited[i] || !MAP[next][i]) continue;
			int new_cost = cost[node][next] + MAP[next][i];
			if (!cost[node][i] || cost[node][i] > new_cost) {
				cost[node][i] = new_cost;
			}
		}
	}
}

int find_next_min(int node) {
	int ret = -1;
	int min_cost = INT_MAX;
	for (int i = 1; i <= N; i++) {
		if (visited[i] || !cost[node][i])continue;
		if (min_cost > cost[node][i]) {
			min_cost = cost[node][i];
			ret = i;
		}
	}
	return ret;
}

int main() {
	init();
	// dijkstra를 통해 각 노드간 최소 거리 갱신
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
	}
	// 최대 경로 출력
	for (int i = 1; i <= N; i++) {
		int time = cost[i][X] + cost[X][i];
		if (ans < time) ans = time;
	}

	cout << ans;
	return 0;
}