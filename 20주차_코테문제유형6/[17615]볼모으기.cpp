#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	char ball[500001];
	int Rcnt = 0, Bcnt = 0;
	int ans = 987654321;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ball[i];
		if (ball[i] == 'R') Rcnt++;
		if (ball[i] == 'B') Bcnt++;
	}
	
	int i = 0, cnt = 0;
	while (ball[i++] == 'R') cnt++;
	ans = min(ans, Rcnt - cnt);

	i = n-1, cnt = 0;
	while (ball[i--] == 'R') cnt++;
	ans = min(ans, Rcnt - cnt);

	i = 0, cnt = 0;
	while (ball[i++] == 'B') cnt++;
	ans = min(ans, Bcnt - cnt);

	i = n-1, cnt = 0;
	while (ball[i--] == 'B') cnt++;
	ans = min(ans, Bcnt - cnt);

	cout << ans;

	return 0;
}

