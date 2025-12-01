#include <bits/stdc++.h>
using namespace std;

void checkChar() {
    char c; cin >> c;
    string key = "codeforces";
    if (count(key.begin(), key.end(), c) > 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) checkChar();
    return 0;
}
