#include <iostream>
#include <vector>
using namespace std;

void init();
void dfs(int from, int level);

int V; // 노드의 수
vector<vector<pair<int, int>>> nodes;
vector<int> used;

int start_node = 1;
int end_node;
int cost = 0;
int max_cost = 0;
int ans = 0;

void init() {
	cin >> V;
	nodes = vector<vector<pair<int, int>>>(V + 1, vector < pair<int, int>>());
	used = vector<int>(V + 1, 0);

	for (int i = 0; i < V; i++) {
		int from;
		cin >> from;
		int to;
		cin >> to;
		while (to != -1) {
			int dist;
			cin >> dist;
			nodes[from].push_back({to, dist});
			cin >> to;
		}
	}
}

void dfs(int from, int level) {
	int len = nodes[from].size();
	int flag = 0;
	for (int i = 0; i < len; i++) {
		int to = nodes[from][i].first;
		if (used[to]) continue;
		flag = 1;
		int dist = nodes[from][i].second;
		cost += dist;
		used[to] = 1;
		dfs(to, level + 1);
		used[to] = 0;
		cost -= dist;
	}
	if (!flag) {
		if (start_node == 1) {
			if (max_cost < cost) {
				max_cost = cost;
				end_node = from;
			}
		}
		else {
			if (ans < cost) {
				ans = cost;
			}
		}
	}
}

int main() {
	init();
	used[1] = 1;
	dfs(start_node, 0);
	used[1] = 0;
	start_node = end_node;
	used[start_node] = 1;
	dfs(start_node, 0);
	used[start_node] = 0;
	cout << ans;
	return 0;
}