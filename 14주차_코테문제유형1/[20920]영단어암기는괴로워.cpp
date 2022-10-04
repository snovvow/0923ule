#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

int N, M;
map<string, int> mp;
vector<string> v;
bool compare(string a, string b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		if (a.size() < M) continue;
		if (mp.find(a) == mp.end()) {
			mp[a] = 1;
			v.push_back(a);
		}
		mp[a]++;
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}

bool compare(string a, string b) {
	if (a.size() == b.size() && mp[a] == mp[b]) {
		return a < b;
	}
	else if (mp[a] == mp[b]) {
		return a.size() > b.size();
	}
	return mp[a] > mp[b];
}
