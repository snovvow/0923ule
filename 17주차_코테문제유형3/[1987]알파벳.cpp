#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[26];
int R, C, Max = 0;
char map[21][21];
void backTracking(int x, int y, int cnt);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	backTracking(0, 0, 1);
	cout << Max;

	return 0;
}

void backTracking(int x, int y, int cnt) {
	if (Max < cnt) Max = cnt;

	visited[map[x][y]-'A'] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

		if (!visited[map[nx][ny] - 'A']) 
			backTracking(nx, ny, cnt + 1);
	}
	visited[map[x][y] - 'A'] = false;
}
