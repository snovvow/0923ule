#include<iostream>

using namespace std;

int n, k, m;
int Parent[1000001];
int Rank[1000001];

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

	int t;
	cin >> t;
	for (int x = 1;x <= t;x++) {
		cin >> n >> k;
		//초기화
		for (int i = 1;i <= n;i++) {
			Parent[i] = i;
			Rank[i] = 0;
		}
		int cnt = 0, ans = 0;
		for (int i = 0;i < k;i++) {
			int a, b;
			cin >> a >> b;
			Union(a, b);
		}
		cin >> m;
		cout << "Scenario " << x << ":\n";
		for (int i = 1;i <= m;i++) {
			int a, b;
			cin >> a >> b;
			if (Find(a) == Find(b)) cout << "1\n";
			else cout << "0\n";
		}
		cout << "\n";
	}
	return 0;
}
