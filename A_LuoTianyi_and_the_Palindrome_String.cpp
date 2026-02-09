#include <bits/stdc++.h>
using namespace std;
#define int long long

void process() {
    string s; cin >> s;
    int cnt = 0, len = s.length();
    for (int i = 1; i < len; ++i) if (s[i] != s[0]) cnt = 1;
    cout << (cnt ? len-1 : -1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) process();
    return 0;
}
