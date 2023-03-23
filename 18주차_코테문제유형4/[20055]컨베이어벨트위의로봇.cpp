#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, ans = 1;
int arr[201] = { 0, };
bool robot[101] = { false, };

void step1();
void step2();
void step3();
void step4();

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 1; i <= 2*n; i++) {
		cin >> arr[i];
	}

	step1();
	
	return 0;
}

void step1() {
	// 컨베이어 회전

	arr[0] = arr[2 * n];
	for (int i = 2*n; i > 0; i--) {
		arr[i] = arr[i-1];
	}
	for (int i = n; i > 0; i--) {
		robot[i] = robot[i-1];
	}
	robot[n] = false;
	step2();
}

void step2() {
	// 로봇 움직이기
	for (int i = n-1; i > 0; i--) {
		if (robot[i] == true && robot[i+1] == false && arr[i + 1] > 0) {
			robot[i] = false;
			if (i + 1 != n) robot[i + 1] = true;
			arr[i + 1]--;
		}
	}
	step3();
}

void step3() {
	// 로봇 올리기
	if (arr[1] > 0) {
		robot[1] = true;
		arr[1]--;
	}
	step4();
}

void step4() {
	// 내구도 체크
	int cnt = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (arr[i] == 0) cnt++;
	}
	if (cnt >= k) {
		cout << ans;
		return;
	}
	ans++;
	step1();
}
