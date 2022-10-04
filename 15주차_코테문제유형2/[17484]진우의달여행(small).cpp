#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;

int N, M;
int arr[1001][1001] = { 0, };
int dp[1001][1010][4] = { 0, };
int ans = INF;

int solve(int x, int y, int prevDir);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < M; i++)
		ans = min(ans, solve(0, i, 0));
	cout << ans;

	return 0;
}

// 밑으로 내려가면서 해결
int solve(int x, int y, int prevDir) {

	if (y < 0 || y >= M) return INF;
	if (x == N) return 0;

	int result = dp[x][y][prevDir];
	if (result != 0) return result;
	else result = INF;

	if (prevDir != 1 && y != 0) {
		result = min(result, solve(x + 1, y - 1, 1) + arr[x][y]);
	}
	if (prevDir != 2) {
		result = min(result, solve(x + 1, y, 2) + arr[x][y]);
	}
	if (prevDir != 3 && y != M - 1) {
		result = min(result, solve(x + 1, y + 1, 3) + arr[x][y]);
	}

	return dp[x][y][prevDir] = result;

}
