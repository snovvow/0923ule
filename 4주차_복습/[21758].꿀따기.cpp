#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int sum[100001] = { 0, };
	int arr[100001];
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		sum[i] += sum[i-1] + arr[i];
	}
	int ans = 0;
	// 벌 벌 집
	for (int i = 2;i <= n;i++) {
		int bee1 = sum[n] - arr[1] - arr[i];
		int bee2 = sum[n] - sum[i];
		ans = max(ans, bee1 + bee2);
	}
	// 집 벌 벌
	for (int i = 1;i <= n-1;i++) {
		int bee1 = sum[n] - arr[n] - arr[i];
		int bee2 = sum[i - 1];
		ans = max(ans, bee1 + bee2);
	}
	// 벌 집 벌
	for (int i = 1;i <= n;i++) {
		int bee1 = sum[i] - arr[1];
		int bee2 = sum[n] - sum[i - 1] - arr[n];
		ans = max(ans, bee1 + bee2);
	}
	cout << ans;
	return 0;
}
