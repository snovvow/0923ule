#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int v, e, p;
int dis[10001];
vector<pair<int, int>> vec[10001];

void dijkstra(int s);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> v >> e >> p;
	for (int i = 1;i <= e;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
		vec[b].push_back({ a, c });
	}
	dijkstra(1);
	int start_Masan = dis[v];
	int start_Kunwoo = dis[p];
	dijkstra(p);
	int Kunwoo_Masan = dis[v];
	if (start_Kunwoo + Kunwoo_Masan == start_Masan)
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
	
	return 0;
}

void dijkstra(int s) {

	fill(dis, dis + v + 1, INF);
	priority_queue<pair<int, int>> pq; //{s와 정점 사이의 거리, 정점의 번호}
	dis[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int d = -pq.top().first; // s와 정점 사이의 거리 
		int u = pq.top().second; // 정점
		pq.pop();
		if (d > dis[u]) //d가 (시작~정점)보다 더 크면 가지 않는다(느긋한 삭제)
			continue;
		for (int i = 0; i < vec[u].size();i++) {
			int v = vec[u][i].first; // 이웃 정점
			int c = vec[u][i].second; //(u->v cost)

			if (dis[v] > dis[u] + c) { // relax
				dis[v] = dis[u] + c;
				pq.push({ -dis[v], v });
			}
		}
	}
}
