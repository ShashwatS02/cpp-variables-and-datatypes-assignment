#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        string a;
        cin >> n >> a;

        string ops;
        int ones = (a[0] == '1');

        for (int i = 1; i < n; ++i) {
            if (a[i] == '1') {
                ops.push_back( (ones & 1) ? '-' : '+' );
                ++ones;
            } else {
                ops.push_back('+');
            }
        }

        cout << ops << '\n';
    }
    return 0;
}
