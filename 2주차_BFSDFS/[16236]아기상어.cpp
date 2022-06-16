#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, shark_x, shark_y, shark_size = 2, shark_eat = 0, time = 0;
int arr[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int sx, int sy);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark_x = i;
				shark_y = j;
			}
		}
	}

	while (1) {
		bfs(shark_x, shark_y);
	}
	
	return 0;
}

void bfs(int sx, int sy) {
	int fish_x = 100, fish_y = 100, fish_dis = 987654321; //dis는 은근 크게 나와서 잘 설정해야함
	int visited[21][21] = { 0, };
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visited[sx][sy] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > n || ny > n || nx < 1 || ny < 1) continue;
			if (visited[nx][ny] !=0 || arr[nx][ny] > shark_size) continue;

			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });

			//--먼저 먹을 물고기 찾기
			if (arr[nx][ny] < shark_size && arr[nx][ny] != 0) {
				if (fish_dis < visited[nx][ny]) continue;
				if (fish_dis == visited[nx][ny]) {
					if (fish_x < nx) continue;
					else if (fish_x == nx && fish_y < ny) continue;
				}
				fish_x = nx;
				fish_y = ny;
				fish_dis = visited[nx][ny];
			}

		}
	}
  // 물고기 먹기
	if (fish_x != 100 && fish_y != 100) {
		time += fish_dis-1;
		shark_eat++;
		if (shark_eat >= shark_size) {
			shark_size++;
			shark_eat = 0;
		}
		arr[shark_x][shark_y] = 0;
		arr[fish_x][fish_y] = 9;
		shark_x = fish_x;
		shark_y = fish_y;
	}
	else { //못먹으면 종료
		cout << time;
		exit(0);
	}
}
