#include<iostream>
#include<vector>
#include<queue>
#define MAX 1e9
using namespace std;
void dijkstra(int s);

int V, E;
int dis[100005];
vector<pair<int, int>> adj[100005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dijkstra(1);
	cout << dis[V] << "\n";

	return 0;
}

void dijkstra(int s) {
	fill(dis, dis + V + 1, MAX);
	priority_queue<pair<int, int>> pq;
	dis[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (d > dis[u]) 
			continue;

		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int c = adj[u][i].second;

			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				pq.push({ -dis[v], v });
			}
		}
	}
}
