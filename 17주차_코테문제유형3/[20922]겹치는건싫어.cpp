#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K, ans = 0;
	int arr[200001];
	int numCnt[100001] = { 0, };
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0;
	for (int i = 0; i < N; i++) {
		numCnt[arr[i]]++;
		while (numCnt[arr[i]] > K) {
			numCnt[arr[start++]]--;
		}
		ans = max(ans, i - start + 1);
	}
	cout << ans;
	return 0;
}
