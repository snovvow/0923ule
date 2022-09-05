#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, ans = -1;
	int arr[100004] = { 0, };
	int dp[100004] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	// 누적합
	dp[0] = arr[0]; dp[1] = arr[1];
	for (int i = 2; i < N; i++) {
		dp[i] = dp[i - 2] + arr[i];
	}

	int a = dp[N - 2]; // 정훈
	int b = dp[N - 1]; // 상대

	// 정훈 차례 밑장빼기
	ans = max(a, b);
	for (int i = 0; i < N; i = i + 2) {
		a = dp[i] + dp[N - 1] - dp[i + 1];
		ans = max(ans, a);
	}

	// 상대방 차례 밑장빼기
	ans = max(ans, dp[0] + dp[N - 3]);
	for (int i = 2; i < N; i = i + 2) {
		a = dp[i] + dp[N - 3] - dp[i - 1];
		ans = max(ans, a);
	}

	cout << ans;

	return 0;
}
