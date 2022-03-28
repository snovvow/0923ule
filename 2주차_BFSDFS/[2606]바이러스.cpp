#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[101];
bool visited[101] = { false };
int bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs();
}

int bfs() {
	int cnt = 0;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0;i < graph[node].size();i++) {
			int next = graph[node][i];
			if (visited[next] == false) {
				q.push(next);
				visited[next] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
