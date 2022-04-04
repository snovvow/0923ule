#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, pcnt = 0;
	char num[500001];
	cin >> n >> k >> num;

	deque<int> dq; //역순 출력 할때 stack말고 deque 쓰기
	for (int i = 0;i < n;i++) {
		while (!dq.empty() && dq.back() < num[i] - '0'&& k - pcnt) {
			dq.pop_back();
			pcnt++;
		}
		dq.push_back(num[i] - '0');
	}
	for (int i = 0;i < n-k;i++) {
		cout << dq.front();
		dq.pop_front();
	}
  //stack으로 풀면, 맨 뒤 숫자 지워야 할 때 또 처리 해줘야 함-> deque가 좋다
}
