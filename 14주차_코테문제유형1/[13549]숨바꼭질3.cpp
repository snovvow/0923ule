#include <iostream>
#include<queue>
#include<vector>
#define MAX 9876543210
using namespace std;

int N, K;
int t[100001] = { 0, };
void dijkstra(int s);


int main() {
	cin >> N >> K;
	dijkstra(N);
	if (N == K)cout << 0;
	else cout << t[K];
}

void dijkstra(int s) {
	for (int i = 0; i <= 100000; i++) {
		t[i] = MAX;
	}
	priority_queue<pair<int, int>> pq;//{cost, start}
	t[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first; //cost
		int node = pq.top().second; //from정점
		pq.pop();

		if (d > t[node]) //cost가 (시작~from)보다 더 크면 가지 않는다
			continue;
		for (int i = 0; i < 3; i++) {
			int next, c;
			//------3가지 너비종류-------
			if (i == 0) {
				next = node + 1;
				c = 1;
			}
			else if (i == 1) {
				next = node - 1;
				c = 1;
			}
			else {
				next = node * 2;
				c = 0;
			}
			if (next >= 0 && next <= 100000 && t[next] > t[node] + c) {
				t[next] = t[node] + c;
				pq.push({ -t[next], next });
			}
		}
	}
}
