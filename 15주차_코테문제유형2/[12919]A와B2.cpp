#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;

void ABBA(string a, string b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	string a, b;
	cin >> a >> b;
	ABBA(a, b);
	cout << 0;
	return 0;
}

void ABBA(string a, string b) {
	string tmp;
	if (a == b) {
		cout << 1;
		exit(0);
		return;
	}
	if (a.size() >= b.size()) 
		return;

	if (b[b.size() - 1] == 'A') {
		tmp = b;
		tmp.pop_back();
		ABBA(a, tmp);
	}
	if (b[0] == 'B') {
		tmp = b;
		tmp.erase(0,1);
		reverse(tmp.begin(), tmp.end());
		ABBA(a, tmp);
	}
}
