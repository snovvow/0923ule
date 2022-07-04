#include <iostream>
#include <string>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    int stack = 0;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P') {
            stack++;
        }
        else if (str[i] == 'A') {
            stack -= 2;
            i++;
            if (stack < 0 || i == str.length() || str[i] == 'A') {
                cout << "NP";
                return 0;
            }
            stack++;
        }
    }
    if (stack != 1) cout << "NP";
    else cout << "PPAP";
    return 0;
}
