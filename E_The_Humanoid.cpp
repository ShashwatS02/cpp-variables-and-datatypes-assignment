#include <bits/stdc++.h>
using namespace std;

static long long capMul(long long x, int m){
    const long long LIM = (long long)4e18;
    if (x >= LIM / m) return LIM;
    return x * m;
}

static int sim(const vector<long long>& a, array<int,3> mul, long long h){
    int n = (int)a.size();
    int used = 0, i = 0;
    while(i < n){
        if(h > a[i]){
            h += a[i] / 2;
            ++i;
        }else{
            if(used == 3) break;
            h = capMul(h, mul[used++]);
        }
    }
    return i;
}

static void solve(){
    int n; long long h;
    cin >> n >> h;
    vector<long long> v(n);
    for(auto &x: v) cin >> x;
    sort(v.begin(), v.end());

    int best = 0;
    best = max(best, sim(v, {2,2,3}, h));
    best = max(best, sim(v, {2,3,2}, h));
    best = max(best, sim(v, {3,2,2}, h));

    cout << best << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}
