#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, k;
	int arr[101] = { 0, };
	long long dp[10001] = { 0, };

	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		int a;
		cin >> arr[i];
	}

	dp[0] = 1;
	
	for (int i = 0;i < n;i++) {
		for (int j = arr[i];j <= k;j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k];

	return 0;
}
