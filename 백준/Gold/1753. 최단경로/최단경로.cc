#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void init();
void dijkstra(int start);

struct Info {
	int to;
	int dist;
};

struct cmp {
	bool operator() (Info left, Info right) {
		return left.dist > right.dist;
	}
};

int V; // node 수
int E; // edge 수
int S; // 시작 노드
vector<vector<Info>> edges;
vector<int> cost;


void init() {
	cin >> V >> E;
	cin >> S;
	edges = vector<vector<Info>>(V + 1, vector<Info>());
	cost = vector<int>(V + 1, 0);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v,w});
	}
}

void dijkstra(int start) {
	priority_queue<Info, vector<Info>, cmp> pq;
	int len = edges[start].size();
	for (int i = 0; i < len; i++) {
		Info tmp = edges[start][i];
		pq.push({tmp});
	}

	while (!pq.empty()) {
		Info now = pq.top();
		pq.pop();

		if (cost[now.to]) continue;
		cost[now.to] = now.dist;
		
		int l = edges[now.to].size();
		for (int i = 0; i < l; i++) {
			Info tmp = edges[now.to][i];
			pq.push({tmp.to, tmp.dist + cost[now.to]});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	dijkstra(S);
	for (int i = 1; i <= V; i++) {
		if (i == S) {
			cout << 0 << '\n';
			continue;
		}
		if (!cost[i]) {
			cout << "INF\n";
			continue;
		}
		cout << cost[i] << '\n';
	}
	return 0;
}