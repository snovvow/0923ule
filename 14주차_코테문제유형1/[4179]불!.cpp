#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int R, C;
pair<int, int> start;
char map[1001][1001];
int fire_map[1001][1001];
bool visit[1001][1001];

queue<pair<int, int>> fireq;

int dx[4] = { 0, 0, 1,-1 };
int dy[4] = { 1,-1, 0, 0 };

void Firebfs();
int Pbfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'F') {
				fireq.push({ i,j });
				fire_map[i][j] = 0;

			}
			else if (map[i][j] == 'J') {
				start = { i,j };
				fire_map[i][j] = 987654321;
			}
			else {
				fire_map[i][j] = 987654321;
			}
		}
	}
	Firebfs();
	int ans = Pbfs();
	if (ans == -1)cout << "IMPOSSIBLE";
	else cout << ans;
	return 0;
}

void Firebfs() {
	while (!fireq.empty()) {
		int x = fireq.front().first;
		int y = fireq.front().second;
		fireq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((0 <= nx && nx < R) && (0 <= ny && ny < C)) {
				if (map[nx][ny] != '#') {
					if (fire_map[nx][ny] > fire_map[x][y] + 1) {
						fire_map[nx][ny] = fire_map[x][y] + 1;
						fireq.push(pair<int, int>(nx, ny));
					}
				}
			}
		}
	}
}

int Pbfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ start,0 });
	visit[start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
			return time + 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((0 <= nx && nx < R) && (0 <= ny && ny < C)) {
				if (map[nx][ny] != '#' && visit[nx][ny] == false) {
					if (fire_map[nx][ny] > time + 1) {
						visit[nx][ny] = true;
						q.push({{ nx, ny }, time + 1});
					}
				}
			}
		}
	}
	return -1;
}
