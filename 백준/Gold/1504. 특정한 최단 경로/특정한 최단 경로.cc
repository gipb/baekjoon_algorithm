#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long int

void init();
void dijkstra(int start);
int find_next(int node);
ll find_ans();

int N; // node 수
int E; // edge 수
vector<vector<int>> graph;
vector<vector<ll>> cost;
vector<int> used;

int v1, v2; // 중간 지점

void init() {
	cin >> N >> E;
	graph = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	cost = vector<vector<ll>>(N + 1, vector<ll>(N + 1, 0));
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	cin >> v1 >> v2;
}

void dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		cost[start][i] = (ll)graph[start][i];
	}

	used = vector<int>(N + 1, 0);
	used[start] = 1;

	while (true) {
		int next = find_next(start);
		if (next == -1) break;
		used[next] = 1;
		for (int i = 1; i <= N; i++) {
			if (!graph[next][i]) continue;
			ll new_cost = cost[start][next] + (ll)graph[next][i];
			if ((new_cost < cost[start][i]) || !cost[start][i]) {
				cost[start][i] = new_cost;
			}
		}
	}
}

int find_next(int node) {
	int ret = -1;
	ll min_cost = LLONG_MAX;
	for (int i = 1; i <= N; i++) {
		if (used[i] || !cost[node][i]) continue;
		if (min_cost > cost[node][i]) {
			min_cost = cost[node][i];
			ret = i;
		}
	}
	return ret;
}

ll find_ans() {
	if (v1 == 1 && v2 == N) return cost[1][N] ? cost[1][N] : -1;
	if (v1 == 1) {
		if (cost[1][v2] && cost[v2][N]) return cost[1][v2] + cost[v2][N];
		else return -1;
	}
	if (v2 == N) {
		if (cost[1][v1] && cost[v1][N]) return cost[1][v1] + cost[v1][N];
		else return -1;
	}

	ll ans1 = -1;
	ll ans2 = -1;
	if (cost[1][v1] && cost[v1][v2] && cost[v2][N]) {
		ans1 = cost[1][v1] + cost[v1][v2] + cost[v2][N];
	}
	if (cost[1][v2] && cost[v2][v1] && cost[v1][N]) {
		ans2 = cost[1][v2] + cost[v2][v1] + cost[v1][N];
	}

	if (ans1 == -1 && ans2 == -1) return -1;
	if (ans1 == -1) return ans2;
	if (ans2 == -1) return ans1;
	return ans1 > ans2 ? ans2 : ans1;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	dijkstra(1);
	dijkstra(v1);
	dijkstra(v2);
	
	ll ans = find_ans();
	cout << ans;

	return 0;
}