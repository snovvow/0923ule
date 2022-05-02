#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	int dp[1500001] = { 0, };
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	// dp[i]는 i번째 날짜부터 마지막 날 까지의 최대 이익
	// dp[i]는 i번째 날짜에 (상담을 받지 않는 경우 or 받는 경우)
	for (int i = n-1;i >= 0;i--) {
		if (i + v[i].first > n) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i+1], v[i].second + dp[i + v[i].first]);
	}
	cout << dp[0];
	return 0;
}
