#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	int arr[100001] = { 0, };

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0, end = 0;
	int sum = 0, MinSum = 987654321;
	for (int i = 0; i < n; i++) {
		end = i;
		sum += arr[i];
		while (sum >= s && start<=end) {
			MinSum = min(MinSum, end - start + 1);
			sum -= arr[start];
			start++;
		}
	}
	if (MinSum == 987654321) cout << 0;
	else cout << MinSum;

	return 0;
}
