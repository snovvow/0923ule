#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<char> str;
vector<string> answer;

bool visited[10];
char c[10];
int k;

void backtracking(int cnt);
bool cal();

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> k;
	for (int i = 0;i < k;i++) {
		cin >> c[i];
	}

	backtracking(0);
	cout << answer[answer.size()-1] << "\n" << answer[0] << "\n";

	return 0;
}

// 맞는 순서인지 계산
bool cal() {
	for (int i = 0;i < k;i++) {
		if (c[i] == '<') {
			if (str[i] > str[i + 1]) return false;
		}
		else if (c[i] == '>') {
			if (str[i] < str[i + 1]) return false;
		}
	}
	return true;
}

// 백트래킹
void backtracking(int cnt) {
	if (cnt == k + 1) {
		if (cal()) {
			string str_tmp = "";
			for (int i = 0;i < str.size();i++)
				str_tmp += str[i];
			answer.push_back(str_tmp);
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		str.push_back(i + '0');
		backtracking(cnt + 1);
		str.pop_back();
		visited[i] = false;
	}
}
