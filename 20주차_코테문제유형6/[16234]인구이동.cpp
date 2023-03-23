#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;


int N, L, R;
int arr[100][100];
int visited[100][100] = { 0, };
int dx[4] = { 1,-1,0,0 };	
int dy[4] = { 0,0,1,-1 };
bool bfs(int sx, int sy);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j])
					if (bfs(i, j)) flag = true;
			}
		}
		memset(visited, 0, sizeof(visited));
		if (flag) ans++;
	}
	cout << ans;
	return 0;
}

bool bfs(int sx, int sy) {
	int sum = arr[sx][sy];
	vector<pair<int,int>> v;
	queue<pair<int, int>> q;
	
	v.push_back({ sx,sy });
	q.push({ sx,sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int dif = abs(arr[nx][ny] - arr[x][y]);

			if (visited[nx][ny] == false && nx >= 0 && ny >= 0 && nx < N && ny < N && dif >=L && dif <= R) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				v.push_back({ nx,ny });
				sum += arr[nx][ny];
			}
		}
	}

	if (v.size() >= 2) {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			arr[x][y] = sum / v.size();
		}
		return true;
	}
	return false;
}
