#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans = 0;
bool map[30][30] = { false, };
void backtracking(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	backtracking(1, 1);
	cout << ans;
	return 0;
}

void backtracking(int x, int y) {
	if (y > m) {
		x++; y = 1;
	}

	if (x > n) {
		ans++;
		return;
	}
	
	//채우고 다음칸
	if (!map[x - 1][y - 1] || !map[x - 1][y] || !map[x][y - 1]) {
		map[x][y] = true;
		backtracking(x, y + 1);
		map[x][y] = false;
	}
	//안채우고 다음칸
	backtracking(x, y + 1);
	return;
}
