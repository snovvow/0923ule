#include<iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int n;
	
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n % 2) {
		cout << -1;
		return 0;
	}

	cout << n << " ";
	for (int i = 2; i < n; i++) {
		if (i % 2 == 0) {
			cout << n - i + 1<< " ";
		}
		else {
			cout << i - 1 << " ";
		}
	}
	cout << 1;
	return 0;
}
