#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int tmp;
void solve(int cnt, int num, int sum, int sign, string str);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		cin >> tmp;
		solve(1, 1, 0, 1, "1");
		cout << "\n";
	}


	return 0;
}


void solve(int cnt, int num, int sum, int sign, string str) {
	if (cnt == tmp) {
		sum += (num * sign);
		if (sum == 0) {
			cout << str << "\n";
		}
	}

	else {
		solve(cnt+1, num*10 + cnt+1, sum, sign, str + ' ' + char(cnt + 1 + '0'));
		solve(cnt+1, cnt+1, sum+(sign*num), 1, str + '+' + char(cnt + 1 + '0'));
		solve(cnt+1, cnt+1, sum+(sign*num), -1, str + '-' + char(cnt + 1 + '0'));
	}
}
