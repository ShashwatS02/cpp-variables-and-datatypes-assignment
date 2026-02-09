#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        i64 R, X, D; int n;
        cin >> R >> X >> D >> n;
        string s; cin >> s;
        auto down = [&](i64 &v){ v -= min<i64>(v, D); };
        long long ans = 0;
        for (char c : s) {
            if (c == '1') {                 
                ++ans; 
                down(R);
            } else {                         
                if (R < X) {                 
                    ++ans; 
                    down(R);
                }                            
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
