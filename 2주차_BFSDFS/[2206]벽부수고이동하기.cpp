#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
char arr[1001][1001];
int dis[1001][1001][2] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs();

//가중치가 없는 그래프의 최단거리(bfs 응용!)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> arr[i][j];
		}
	}
	bfs();
	if (dis[n][m][0] == 0 && dis[n][m][1] == 0) //도착X
		cout << -1;
	else {
		if (dis[n][m][1] == 0)                    //부수거나 안부수고 가야만 하는 경우
			cout << dis[n][m][0];
		else if(dis[n][m][0] == 0)
			cout << dis[n][m][1];
		else cout << min(dis[n][m][0], dis[n][m][1]); //경로가 둘 다 존재, 작은 값을 선택
	}
	return 0;
}

void bfs() {
	queue<pair<pair<int, int>,int>> q;
	q.push({ { 1,1 },0 });
	dis[1][1][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int flag = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m) {	//범위 안
				if (arr[nx][ny] == '0' && dis[nx][ny][flag]==0) {			//벽을 부수지 않은 경우
					dis[nx][ny][flag] = dis[x][y][flag] + 1;
					q.push({ {nx,ny},flag });
				}
				if (arr[nx][ny] == '1' && flag == 0 && dis[nx][ny][1]==0) {	//벽을 부수는 경우
					dis[nx][ny][1] = dis[x][y][0] + 1;
					q.push({ {nx,ny},1});
				}
			}
		}
	}
}
