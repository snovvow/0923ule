#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string w;
		int k;
		int alpha[30] = { 0, };

		int ans3 = 987654321;
		int ans4 = -1;

		cin >> w >> k;

		for (int i = 0; i < w.size(); i++) {
			alpha[w[i] - 'a']++;
		}

		for (int i = 0; i < w.size(); i++) {
			if (alpha[w[i] - 'a'] < k) continue;

			int cnt = 0;
			for (int j = i; j < w.size(); j++) {
				if (w[i] == w[j]) cnt++;
				
				if (cnt == k) {
					ans3 = min(ans3, j - i + 1);
					ans4 = max(ans4, j - i + 1);
					break;
				}
			}
		}
		if (ans3 == 987654321 || ans4 == -1)
			cout << "-1\n";
		else
			cout << ans3 << " " << ans4 << "\n";
	}

	return 0;
}
