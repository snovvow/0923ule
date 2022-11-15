#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, start = 987654321, end = 0;
	int pole[1001] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		cin >> pole[tmp];
		if (tmp < start) start = tmp;
		if (tmp > end) end = tmp;
	}
	int tmpMax = 0;
	int ans = 0, idx = 0;
	for (int i = start; i <= end; i++) {
		if (pole[i] >= tmpMax) {
			ans += idx * tmpMax;
			tmpMax = pole[i];
			idx = 1;
		}
		else {
			idx++;
		}
	}
	tmpMax = 0, idx = 0;
	for (int i = end; i >= start; i--) {
		if (pole[i] > tmpMax) {
			ans += idx * tmpMax;
			tmpMax = pole[i];
			idx = 1;
		}
		else {
			idx++;
		}
	}
	ans += tmpMax;
	cout << ans;

	return 0;
}
