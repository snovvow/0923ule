#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1e9
using namespace std;


int N, M, K;
int dis[1001];
int roundTrip[1001];
vector<pair<int, int>> adj[1001];
void dijkstra(int s);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	//---집에서 K---//
	dijkstra(K);
	for (int i = 1; i <= N; i++) {
		roundTrip[i] = dis[i];
	}
	//---K에서 집---//
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
		roundTrip[i] += dis[K];
	}
	//---가장 오래 걸리는 학생---//
	int tmpMax = -1;
	for (int i = 1; i <= N; i++) {
		if (tmpMax < roundTrip[i])
			tmpMax = roundTrip[i];
	}
	cout << tmpMax;
	return 0;

}

void dijkstra(int s) {
	fill(dis, dis + N + 1, MAX);
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
