#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, ans = 0;
int arr[301][301];
bool visited[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void dfs(int x, int y);
void melt();

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
	
	while (1) {
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				if (arr[i][j] != 0 && visited[i][j] == false) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt >= 2) {		//분리
			cout << ans;
			return 0;
		}
		if (q.empty()) {	//분리X
			cout << 0;
			return 0;
		}
		melt();
		ans++;
	}

	return 0;
}

void dfs(int x, int y) {
	visited[x][y] = true;
	q.push({ x, y });
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && ny > 0 && nx <= n && ny <= m && arr[nx][ny] != 0 && visited[nx][ny] == false)
			dfs(nx, ny);
	}
}

void melt() {
	int temp[301][301] = { 0, };
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m && arr[nx][ny] == 0) {
				temp[x][y]++;
			}
		}
	}
	//한번에 녹이기
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (arr[i][j] != 0) {
				arr[i][j] -= temp[i][j];
				if (arr[i][j] < 0)
					arr[i][j] = 0;
			}
		}
	}
}
