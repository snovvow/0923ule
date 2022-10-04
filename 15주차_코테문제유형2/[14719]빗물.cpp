#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int H, W, ans = 0;
	int arr[501][501] = { 0, }; // 비어있으면 0, 벽은 1, 빗물은 2
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int height;
		cin >> height;
		for (int j = 0; j < height; j++) {
			arr[i][j] = 1;
		}
	}
	for (int j = 0; j < H; j++) {
		// 앞에서부터 빗물 받기
		int prev = 0;
		for (int i = 0; i < W - 1; i++) {
			if (arr[i][j] == 1) prev = 1;
			if (arr[i][j] == 0 && prev == 1) arr[i][j] = 2;
		}
		// 뒤에서부터 빗물 빼기
		prev = 0;
		for (int i = W - 1; i >= 0; i--) {
			if (arr[i][j] == 1) prev = 1;
			if (arr[i][j] == 2 && prev == 0) arr[i][j] = 0;
			if (arr[i][j] == 2) ans++;
		}
	}

	cout << ans;

	return 0;
}
