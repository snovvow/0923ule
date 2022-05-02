#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void wbfs();
void bfs();

int r, c;
char map[51][51];
int visited[51][51] = { 0, };
int watered[51][51] = { 0, };
pair<int, int> home;
queue<pair<int, int>> water;
queue<pair<int, int>> go;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 1;i <= r;i++) {
		for (int j = 1;j <= c;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') home = { i,j };
			if (map[i][j] == 'S') {
				go.push({ i,j });
				visited[i][j] = 1;
			}
			if (map[i][j] == '*') {
				water.push({ i,j });
				watered[i][j] = 1;
			}
		}
	}

	wbfs();
	bfs();
	if (visited[home.first][home.second] == 0) cout << "KAKTUS";
	else cout << visited[home.first][home.second] - 1;
}

void wbfs() {

	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx <= r && ny <= c && map[nx][ny] != 'X' && map[nx][ny] != 'D' && watered[nx][ny] == 0) {
				watered[nx][ny] = watered[x][y] + 1;
				water.push({ nx,ny });
			}
		}
	}
}

void bfs() {

	while (!go.empty()) {
		int x = go.front().first;
		int y = go.front().second;
		go.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx <= r && ny <= c && map[nx][ny] != 'X' && (watered[nx][ny] == 0 || (watered[nx][ny] > visited[x][y]+1)) && visited[nx][ny] == 0) {
				visited[nx][ny] = visited[x][y] + 1;
				go.push({ nx,ny });
			}
		}
	}
}

// (watered[nx][ny] == 0 || (watered[nx][ny] > visited[x][y]+1)) 물이 차지 않거나, 고슴도치가 가는 타이밍에만 안 차있으면 갈 수 있다.
