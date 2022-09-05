#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K, B;
	bool broken[100001] = { false, };

	cin >> N >> K >> B;

	for (int i = 1; i <= B; i++) {
		int num;
		cin >> num;
		broken[num] = true;
	}
	// 슬라이딩 윈도우 알고리즘
	// => 일정 크기 배열을 움직임
	// => 움직일 때 맨 끝(좌우)을 연산한다.
	int cnt = 0, ans = 987654321;
	for (int i = 1; i <= K; i++) {
		if (broken[i]) cnt++;
	}
	// i-j window
	for (int j = K+1, i = 1 ; j <= N; j++, i++) {
		if (broken[i]) cnt--;
		if (broken[j]) cnt++;
		ans = min(ans, cnt);
	}

	cout << ans;

	return 0;
}
