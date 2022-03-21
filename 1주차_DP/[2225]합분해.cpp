#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, k;
	long long dp[201][201] = { 0, };

	cin >> n >> k;

	for (int i = 0;i <= k;i++)
		dp[0][i] = 1;
	for (int i = 1;i <= n;i++) 
		dp[i][1] = 1;
	
	for (int i = 1;i <= n;i++) {
		for (int j = 2;j <= k;j++) {
			for (int x = 0;x <= i;x++) {
				dp[i][j] = (dp[i][j] + dp[x][j - 1]) % 1000000000;
			}
		}
	}

	cout << dp[n][k] % 1000000000;

	return 0;
}
