#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, ans = 0;
int arr[51][51];
bool visited[51][51] = { false };
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };

void bfs(int sx, int sy);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (n != 0 && m != 0) {

		ans = 0;
		memset(arr, 0 ,sizeof(arr));
		memset(visited, false ,sizeof(arr));

		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++)
				cin >> arr[i][j];
		}
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				if (arr[i][j] == 1 && visited[i][j] == false) {
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		cin >> n >> m;
	}
	return 0;
}

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 8;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[nx][ny]==1 && visited[nx][ny]==false) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}
