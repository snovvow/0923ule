#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, m, max = 0;
	char arr[1001][1001];
	int dp[1001][1001] = { 0, };

	cin >> n >> m;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (arr[i][j] == '1') {
				if (arr[i - 1][j] && arr[i][j - 1] && arr[i - 1][j - 1]) {
					dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
				}
				else dp[i][j] = 1;
			}
			if (max < dp[i][j])
				max = dp[i][j];
		}
	}

	cout << max * max;
	return 0;
}
