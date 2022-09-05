#include <iostream>

using namespace std;
void solve(int x, int y, int size);

int n, r, c;
int cnt = -1;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> r >> c;
	solve(0, 0, (1 << n));

}

void solve(int x, int y, int size) {

	if (y == r && x == c) {
		cout << cnt + 1;
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x) {
		size /= 2;
		//왼위,오른위,왼아래,오른아래
		solve(x, y, size);
		solve(x + size, y, size);
		solve(x, y + size, size);
		solve(x + size, y + size, size);
		return;
	}
	else {
		cnt += size * size;
	}
}
