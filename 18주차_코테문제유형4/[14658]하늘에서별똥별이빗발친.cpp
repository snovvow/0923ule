#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, l, k;
	cin >> n >> m >> l >> k;
	vector<pair<int, int>> v;
	int maxStar = -1;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			int cnt = 0;
			//트램펄린의 왼쪽 위 지정
			int x = v[i].first;
			int y = v[j].second;

			//별을 순회하면서 트램펄린 안에 들어오는 지 체크
			for (int k = 0; k < v.size(); k++) {
				int nx = v[k].first;
				int ny = v[k].second;
				if ((x <= nx && nx <= x + l) && (y <= ny && ny <= y + l)) cnt++;
			}

			maxStar = max(maxStar, cnt);
		}
	}
	
	cout << k - maxStar;
	return 0;
}
