#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
char c[20];
char tmp[20];
int pw[2] = { 0, }; // pw[0] = 모음의 개수, pw[1] = 자음의 개수

void backtracking(int pre, int cnt);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> c[i];
	}
	sort(c, c + m);
	backtracking(-1, 0);
	return 0;
}

void backtracking(int pre, int cnt) {
	if (cnt == n) {
		if (pw[0] >= 1 && pw[1] >= 2) { // 조건 만족
			for (int i = 0;i < n;i++) {
				cout << tmp[i];
			}
			cout << "\n";
		}
		return;
	}
	if (pre == m - 1) { // 암호 미완성
		return;
	}

	for (int i = pre + 1;i < m;i++) {
		tmp[cnt] = c[i];
		if (tmp[cnt] == 'a' || tmp[cnt] == 'e' || tmp[cnt] == 'i' || tmp[cnt] == 'o' || tmp[cnt] == 'u') {
			pw[0]++;
			backtracking(i, cnt + 1);
			pw[0]--;
		}
		else {
			pw[1]++;
			backtracking(i, cnt + 1);
			pw[1]--;
		}
	}
}
