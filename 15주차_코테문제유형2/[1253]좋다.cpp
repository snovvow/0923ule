#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, cnt = 0;
	int arr[2001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
  // 투포인터
	for (int i = 0; i < N; i++) {
		int val = arr[i];
		int left = 0, right = N - 1;
		while (left < right) {
			int sum = arr[left] + arr[right];
			if (sum == val) {
				if (left == i) left++;
				else if (right == i) right--;
				else {
					cnt++;
					break;
				}
			}
			else if (sum < val) left++;
			else if (sum > val) right--;
		}
	}

	cout << cnt;

	return 0;
}
