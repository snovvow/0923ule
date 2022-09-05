#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	char pw[70];
	ll k, i;

	cin >> pw >> k;
	k--;

	for (i = 0; pw[i] != '\0'; i++) {
		if (pw[i] == '6' || pw[i] == '7') {
			pw[i] -= 5;
		}
	}

	while (i--) {
		if (pw[i] == '1' || pw[i] == '2') {
			if (k & 1) pw[i] += 5;
			k >>= 1;
		}
	}
	if (!k)
		cout << pw;
	else
		cout << -1;

	return 0;
}

//https://dojang.io/mod/page/view.php?id=184
//비트연산자 플래그처리
//k=1 0000
//k=2 0001
//k=3 0010
//k=4 0011
