#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n, p, e;
int ans[30];
bool flag = false;
pair<int, int> arr[1000001];
vector<int> v;
void backtracking(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> p >> e;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	backtracking(0);
	if (flag == false)cout << "-1";

	return 0;
}

void backtracking(int cnt) {
	if (flag == false && cnt == p) {
		int MIN = 0, MAX = 0;
		for (int i = 0; i < p; i++) {
			MIN += arr[v[i]].first;
			MAX += arr[v[i]].second;
		}

		if (MIN<=e && MAX>=e) {
			flag = true;
			for (int i = 0; i < p; i++) {
				ans[v[i]] = arr[v[i]].first;
			}
			int tmp = e - MIN;
			for (int i = 0; i < p; i++) {
				if (tmp >= arr[v[i]].second - arr[v[i]].first) {
					ans[v[i]] = arr[v[i]].second;
					tmp -= arr[v[i]].second - arr[v[i]].first;
				}
				else { 
					ans[v[i]] += tmp;
					tmp = 0;
				}
			}
			for (int i = 0; i < n; i++) {
				cout << ans[i] << " ";
			}
		}

	}
	for (int i = 0; i < n; i++) {
		if (flag == false && (cnt == 0 || v[cnt - 1] < i)) {
			v.push_back(i);
			backtracking(cnt + 1);
			v.pop_back();
		}
	}
}

