#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dis[10001];
vector<pair<int, int>> v[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, d;
	cin >> n >> d;
	for (int i = 1;i <= n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 0;i <= d;i++)
		dis[i] = i;
	for (int i = 0;i <= d;i++) {
		if(i!=0) dis[i] = min(dis[i], dis[i - 1] + 1);
		for (int j = 0;j < v[i].size();j++) 
			//지름길이 더 짧은 길인가?
			dis[v[i][j].first] = min(dis[v[i][j].first], dis[i] + v[i][j].second);
	}
	cout << dis[d];
	return 0;
}
