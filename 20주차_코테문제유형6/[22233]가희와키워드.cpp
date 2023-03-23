#include <iostream>
#include <vector>
#include <unordered_set>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	string tmp;
	char separator = ',';
	unordered_set<string> se;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		se.insert(tmp);
	}

	while(m--) {
		cin >> tmp;
		string str = "";


		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == separator) {
				if (se.find(str) != se.end()) {
					se.erase(se.find(str));
				}
				str = "";
			}
			else str += tmp[i];
		}
		if (se.find(str) != se.end()) {
			se.erase(se.find(str));
		}

		
		cout << se.size() << "\n";
	}

	return 0;
}

