#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v;

int arr[11][11];
bool visited[11][11] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m, h;
int home_x, home_y;
int maxx = 0;

void backtracking(int x, int y, int hp, int milk);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> h;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				home_x = i;home_y = j;
			}
			if (arr[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}
	backtracking(home_x, home_y, m, 0);
	cout << maxx;

	return 0;
}
void backtracking(int x, int y, int hp, int milk) {
	int dis = abs(x - home_x) + abs(y - home_y);
	if (hp == 0)
		return;
	if (dis <= hp) {
		if (maxx < milk) maxx = milk;
	}

	for (int i = 0;i < v.size();i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		int distance = abs(nx - x) + abs(ny - y);
		if (!visited[nx][ny] && distance <= hp) {
			visited[nx][ny] = true;
			backtracking(nx, ny, hp - distance + h, milk + 1);
			visited[nx][ny] = false;
		}
	}
}
