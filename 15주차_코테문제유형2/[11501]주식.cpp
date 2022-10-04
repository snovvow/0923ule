#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define INF 1e9
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> v;
		long long ans = 0;
		int tmp, max_price = -1;

		for (int i = 0; i < N; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = N-1; i >= 0; i--) {
			max_price = max(max_price, v[i]);
			ans += max_price - v[i];
		}
		cout << ans << "\n";
	}

	return 0;
}
