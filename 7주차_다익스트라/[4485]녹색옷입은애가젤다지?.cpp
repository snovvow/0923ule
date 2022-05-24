#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, num = 1;
int map[126][126] = { 0, };
int dis[126][126];

void dijkstra(int sx, int sy);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (true) {
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cin >> map[i][j];
			}
		}
		dijkstra(0, 0);
		cout << "Problem " << num++ << ": " << dis[n - 1][n - 1] << "\n";
	}
	
	
	return 0;
}

void dijkstra(int sx, int sy) {

	fill(&dis[0][0], &dis[n-1][n], INF);
	priority_queue<pair<int, pair<int, int>>> pq; //{s와 정점 사이의 거리, 정점의 번호}
	dis[sx][sy] = map[sx][sy];
	pq.push({ -dis[sx][sy], {sx, sy} });

	while (!pq.empty()) {
		int d = -pq.top().first; 
		int ux = pq.top().second.first; 
		int uy = pq.top().second.second; 
		pq.pop();
		if (d > dis[ux][uy]) 
			continue;
		for (int i = 0; i < 4;i++) {
			int vx = ux + dx[i];
			int vy = uy + dy[i];
			if (vx >= 0 && vy >= 0 && vx < n && vy < n) {
				int c = map[vx][vy];

				if (dis[vx][vy] > dis[ux][uy] + c) { // relax
					dis[vx][vy] = dis[ux][uy] + c;
					pq.push({ -dis[vx][vy], {vx,vy} });
				}
			}
		}
	}
}
