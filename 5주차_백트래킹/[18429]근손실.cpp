#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> v;
int n, k, answer = 0;
void backTracking(int cnt, int result);
int a[10];
int visited[10];

int main() {
	int idx = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}

	backTracking(1,500);
	cout << answer;
}

void backTracking(int cnt, int result) {
	if (result >= 500) {
		if (cnt > n) {
			answer++;
			return;
		}
		for (int i = 1;i <= n;i++) {
			if (!visited[i]) {
				visited[i] = true;
				backTracking(cnt + 1, result - k + a[i]);
				visited[i] = false;
			}
		}
	}
}
