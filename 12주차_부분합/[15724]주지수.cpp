#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, K;
	int arr[1025][1025] = { 0, };
	long long dp[1025][1025] = { 0, };

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	// 누적합하기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	// 답
	cin >> K;
	for (int i = 1; i <= K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--;
		cout << dp[x2][y2] - dp[x1][y2] - dp[x2][y1] + dp[x1][y1] << "\n";
	}

	return 0;
}
