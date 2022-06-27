#include<iostream>

using namespace std;

int n, m;
int Parent[1001];
int Rank[1001];

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
	for (int i = 1;i <= n;i++) {
		Parent[i] = i;
		Rank[i] = 0;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) Union(i, j);
		}
	}
	int a, b;
	cin >> a;
	for (int i = 2;i <= m;i++) {
		cin >> b;
		if (Find(a) != Find(b)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
