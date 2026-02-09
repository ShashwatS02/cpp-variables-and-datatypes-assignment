#include <bits/stdc++.h>
using namespace std;

#define int long long
#define prt(x) cout << x << '\n';

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    char min_char = sorted_s[0];

    int pos = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == min_char) {
            pos = i;
            break;
        }
    }

    string res;
    for (int i = n - 1; i >= 0; i--) {
        if (i != pos) res.push_back(s[i]);
    }
    res.push_back(min_char);
    reverse(res.begin(), res.end());

    prt(res);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}
