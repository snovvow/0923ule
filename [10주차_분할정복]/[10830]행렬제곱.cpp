#include <iostream>
typedef long long ll;
using namespace std;

ll n, b;
ll arr[5][5], res[5][5];
void multi(ll a[5][5], ll b[5][5]);
void fast_pow();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		res[i][i] = 1; //단위 행렬(곱했을때 똑같음)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	fast_pow();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

void multi(ll a[5][5], ll b[5][5]) {
	ll tmp[5][5] = { 0, };

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
			tmp[i][j] %= 1000;
		}
	}
  //a배열에 a*b대입
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			a[i][j] = tmp[i][j];
}
//빠른 제곱
void fast_pow() {
	while (b) {
		if (b % 2 == 1)
			multi(res, arr);
		multi(arr, arr);
		b /= 2;
	}
}
