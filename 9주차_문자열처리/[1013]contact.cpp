#include <iostream>
#include <string>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, flag;
    string num;
    cin >> t;
    while (t--) {
        flag = 0;
        cin >> num;
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '1') {
                int num0 = 0, num1 = 0;
                while (i + 1 < num.length() && num[i + 1] == '0') {
                    i++;
                    num0++;
                }
                if (num0 < 2 || i + 1 == num.length()) {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
                while (i + 1 < num.length() && num[i + 1] == '1') {
                    i++;
                    num1++;
                }
                if (i + 1 == num.length() || num1 == 1) continue;
                if (i + 2 == num.length()) {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
                if (num[i + 1] == '0' && num[i + 2] == '0') i--;
            }
            else if (num[i] == '0') {
                if (i + 1 < num.length() && num[i + 1] == '1') i++;
                else {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) cout << "YES\n";
    }
    return 0;
}
