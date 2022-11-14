#include<iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int n;
	
	cin >> n;

	// 최댓값 nC2
	cout << n * (n - 1) / 2 << "\n";
	// 차가 다르게 출력
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		cout << tmp << " ";
		tmp *= 2;
	}

	// 최솟값
	cout << "\n" << n - 1 << "\n";
	// 등차수열을 출력하면 된다.
	tmp = 1;
	for (int i = 0; i < n; i++) {
		cout << tmp << " ";
		tmp++;
	}
}
