#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, ans = 987654321;
int map[25][25];
bool visited[25];
void backtracking(int cnt, int result);

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> map[i][j];
        }
    }
    
    backtracking(0,1);
    cout << ans;
    return 0;
}

void backtracking(int cnt, int next) {
    if (cnt == n/2) { 
        int start = 0, link = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if (visited[i]==true && visited[j]==true) //start
                    start += map[i][j];
                if (visited[i]==false && visited[j]==false) //link
                    link += map[i][j];
            }
        }
        ans = min(ans, abs(start-link));
        return;
    }
    for (int i = next;i <= n;i++){
        visited[i] = true;
        backtracking(cnt+1, i+1);
        visited[i] = false;
    }
}
