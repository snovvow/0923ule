#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, ans = 0;
int arr[1001][1001];
int visited[1001][1001] = { 0, }; //토마토가 익는 시간
int dx[4] = { 1,-1,0,0 };	//bfs 방향
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;	//pair은 토마토의 위치

void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	bfs();

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			ans = max(ans, visited[i][j]);
		}
	}
	cout << ans;
	return 0;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[nx][ny]==0 ) {	//범위 안 && 안익은 토마토
				q.push({ nx,ny });
				arr[nx][ny] = 1;
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}
