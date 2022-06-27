#include<iostream>

using namespace std;

int n, m;
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

	cin >> n >> m;
	//초기화
	for (int i = 0;i < n;i++) {
		Parent[i] = i;
		Rank[i] = 0;
	}
	int cnt = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		cnt++;
		int a, b;
		cin >> a >> b;
		if (!Union(a, b) && ans==0) {
			ans = cnt;
		}
	}
	cout << ans;
	return 0;
}
