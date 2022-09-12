#include<iostream>
#include <string>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string S, E, Q;
	set<string> present;
	ll cnt = 0;

	cin >> S >> E >> Q;

	while (1) {
		string time, name;
		cin >> time >> name;
		if (time == "" && name == "") break;

		if (time <= S) {
			present.insert(name);
		}
		if (E <= time && time <= Q) {
			if (present.find(name) != present.end()) {
				present.erase(name);
				//또 체크 방지
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
