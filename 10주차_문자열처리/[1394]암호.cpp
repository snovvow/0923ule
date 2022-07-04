#include <iostream>
#include <string>
#define MOD 900528

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long ans = 0;
    long long k = 1;
    string arr, pw;
    cin >> arr >> pw;

    for (int i = pw.length()-1; i >= 0; i--) {
        for (int j = 0; j < arr.length(); j++) {
            if (pw[i] == arr[j]) {
                ans = (ans + (k * (j + 1))) % MOD;
                k = (k * arr.length()) % MOD;
            }
        }
    }
    cout << ans % MOD;
    return 0;
}
//pow는 더블형
