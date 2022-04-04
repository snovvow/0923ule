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
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int start = 0, end = 0;
	for (int i = 0;i < n;i++) {
		if (v[i].first >= end)
			start = v[i].first;
		else 
			start = end;
		end = start + v[i].second;
	}
	cout << end;
}
