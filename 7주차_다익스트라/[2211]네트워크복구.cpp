#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int v, e;
int dis[1001];
int root[1001] = { 0, }; //i번째 노드에 갱신된 최단거리로 가기위한 전 노드
vector<pair<int, int>> rootV; //1부터 v까지 거리 추적해서 루트를 모두 저장
vector<pair<int, int>> vec[1001];

void dijkstra(int s);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> v >> e;
	for (int i = 1;i <= e;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b, c });
		vec[b].push_back({ a, c });
	}
	dijkstra(1);
	for (int i = 1;i <= v;i++) { //1부터 v까지 거리 추적해서 루트를 모두 저장
		int k = i;
		while (root[k] != 0) {
			rootV.push_back({ k,root[k] });
			k = root[k];
		}
	}
  // 중복루트는 제외
	sort(rootV.begin(), rootV.end());
	rootV.erase(unique(rootV.begin(), rootV.end()), rootV.end());
  // 출력
	cout << rootV.size() << "\n";
	for (int a = 0;a < rootV.size();a++) {
		cout << rootV[a].first <<" "<< rootV[a].second << "\n";
	}
	return 0;
}

void dijkstra(int s) {

	fill(dis, dis + v + 1, INF);
	priority_queue<pair<int, int>> pq;
	dis[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int d = -pq.top().first; 
		int u = pq.top().second; 
		pq.pop();
		if (d > dis[u]) 
			continue;
		for (int i = 0; i < vec[u].size();i++) {
			int v = vec[u][i].first; 
			int c = vec[u][i].second; 

			if (dis[v] > dis[u] + c) { 
				dis[v] = dis[u] + c;
				root[v] = u; //루트저장
				pq.push({ -dis[v], v });

			}
		}
	}
}
