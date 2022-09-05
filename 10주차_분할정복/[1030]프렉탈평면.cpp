#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s, n, k, r1, r2, c1, c2;
int solve(int size, int x, int y);

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    int size = 1;
    while (s--) size *= n;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            cout << solve(size, i, j);
        }
        cout << "\n";
    }
}

int solve(int size, int x, int y) {
    if (size == 1)
        return 0;

    // 가운데 까만부분 구하기 (n-k)/2 <= @@ < (n-k)/2 + k (= (n+k)/2)
    size /= n;
    if (x >= size * (n - k) / 2 && x < size * (n + k) / 2 && y >= size * (n - k) / 2 && y < size * (n + k) / 2)
        return 1;
    
    return solve(size, x % size, y % size);
}
