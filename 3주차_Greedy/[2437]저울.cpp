#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, arr[1001] = { 0, };
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	if (arr[0] != 1) { //시작이 1이 아니면 무조건 답이 1
		cout << 1;
		return 0;
	}
	int ans = 1; //ans는 현재 추로 만들 수 있는 최대 무게
	for (int i = 1;i < n;i++) {
		if (arr[i] - ans > 1) {
      //현재 만들 수 있는 최대 무게와 다음 추 사이의 차이가 1이상 나면 못만드는 수 찾을 수 있음
			cout << ans + 1;
			return 0;
		}
		ans += arr[i];
	}
	cout << ans + 1;
}
