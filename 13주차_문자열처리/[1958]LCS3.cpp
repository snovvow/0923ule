#include<iostream>
#include <string>
#include<algorithm>
using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string S1, S2, S3;
	int LCS[105][105][105] = { 0, };

	cin >> S1 >> S2 >> S3;
	for (int i = 1; i <= S1.length(); i++) {
		for (int j = 1; j <= S2.length(); j++) {
			for (int k = 1; k <= S3.length(); k++) {
				if (S1[i - 1] == S2[j - 1] && S2[j - 1] == S3[k - 1]) {
					LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
				}
				else {
					LCS[i][j][k] = max(max(LCS[i - 1][j][k], LCS[i][j - 1][k]), LCS[i][j][k - 1]);
				}
			}
		}
	}
	cout << LCS[S1.length()][S2.length()][S3.length()];
	return 0;
}
