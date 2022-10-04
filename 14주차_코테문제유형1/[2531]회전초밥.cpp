#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, d, k, c, tmp;
	vector<int> v;
	int check[3001] = { 0, };
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	check[c] = 1;

	int cnt = 1, ans = -1;
	// 첫 번째 창문
	for (int i = 0; i < k; i++) {
		if (!check[v[i]]) { 
			check[v[i]]++;
			cnt++;
		}
		else check[v[i]]++;
	}
	// 슬라이딩 윈도우
	for (int i = 0; i < N; i++) {
		int j = i + k;

		// 슬라이딩 윈도우 왼쪽
		if (check[v[i]] == 1 && v[i] != c) { 
			check[v[i]]--;
			cnt--;
		}
		else check[v[i]]--;

		//슬라이딩 윈도우 오른쪽
		if (!check[v[j % N]]) { 
			check[v[j % N]]++;
			cnt++;
		}
		else check[v[j % N]]++;
		ans = max(ans, cnt);
	}

	cout << ans;
	return 0;
}
