#include<iostream>
#include <string>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string S;

	cin >> S;
	int i = 0, e = S.size() - 1;
	int cnt = 0;
	bool flag = false;
	while (true) {
		//cout << i << " " << e << "\n";
		if (i >= e)break;
		if (S[i] == S[e]) {
			flag = true;
			i++; e--;
		}
		else if (!flag) {
			i++; cnt++;
		}
		else if (flag) {
			cnt++;
			i = cnt;
			e = S.size()-1;
			flag = false;
		}
	}
	cout << cnt + S.size();

	return 0;
}
