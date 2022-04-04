#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a, b;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		v.push_back({ a, 1 });	//시작점에서는 현재 겹치는 선분의 개수 늘어남
		v.push_back({ b,-1 });	//끝점에서는 겹치는 선분의 갯수 줄어든다.
	}
	sort(v.begin(), v.end());

	int cnt = 0, ans = 0;
	for (int i = 0;i < 2*n;i++) {
		cnt = cnt + v[i].second;
		ans = max(ans, cnt);
	}
	cout << ans;
}
