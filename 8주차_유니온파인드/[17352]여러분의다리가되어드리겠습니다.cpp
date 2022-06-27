#include<iostream>

using namespace std;

int n, m;
int Parent[300001];
int Rank[300001];

int Find(int x) {
	if (x == Parent[x])
		return x;

	return Parent[x] = Find(Parent[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return false;

	if (Rank[x] > Rank[y]) {
		Parent[y] = x;
	}
	else {
		if (Rank[x] == Rank[y])
			Rank[y]++;
		Parent[x] = y;
	}
	return true;
}



int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	//초기화
	for (int i = 1;i <= n;i++) {
		Parent[i] = i;
		Rank[i] = 0;
	}
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n-2; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 2; i <= n; i++) {
		if (Union(1, i)) {
			cout << "1 " << i;
			break;
		}
	}
	return 0;
}
