#include <iostream>

using namespace std;
void solve(int x, int y, int size);

int n, blue = 0, white = 0;
bool paper[200][200];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	solve(0, 0, n);
	cout << white << "\n" << blue;
}

void solve(int x, int y, int size) {
	if (size == 1) {
		paper[x][y] ? blue++ : white++;
		return;
	}

	bool flag = paper[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (flag != paper[i][j]) {
				size /= 2;
				solve(x, y, size);
				solve(x+size, y, size);
				solve(x, y+size, size);
				solve(x+size, y+size, size);
				return;
			}
		}
	}
	flag ? blue++ : white++;
	return;
}
