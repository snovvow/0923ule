#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, m;
	int arr[1001][1001] = { 0, };
	int dp[1001][1001] = { 0, };

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1;i < n;i++) dp[i][0] = dp[i - 1][0] + arr[i][0];
	for (int j = 0;j < m;j++) dp[0][j] = dp[0][j-1] + arr[0][j];
	
	for (int i = 1;i < n;i++) {
		for (int j = 1;j < m;j++) {
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + arr[i][j];
		}
	}

	cout << dp[n-1][m-1];
	return 0;
}
