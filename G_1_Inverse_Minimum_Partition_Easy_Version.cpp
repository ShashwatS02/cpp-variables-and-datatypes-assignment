#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 4e18; 


vector<long long> tree;
int seg_tree_size;

void build(int n) {
    seg_tree_size = n + 1;
    tree.assign(4 * seg_tree_size, INF);
}

void update(int idx, long long val, int node, int start, int end) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
        update(idx, val, 2 * node, start, mid);
    } else {
        update(idx, val, 2 * node + 1, mid + 1, end);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

long long query(int l, int r, int node, int start, int end) {
    if (r < start || end < l || l > r) {
        return INF;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    long long p1 = query(l, r, 2 * node, start, mid);
    long long p2 = query(l, r, 2 * node + 1, mid + 1, end);
    return min(p1, p2);
}


void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    build(n);
    update(0, 0, 1, 0, seg_tree_size - 1);

    
    vector<pair<int, long long>> mono_stack;

    for (int i = 1; i <= n; ++i) {
        long long current_a = a[i - 1];
        int last_pos = i;

        
        while (!mono_stack.empty() && mono_stack.back().second >= current_a) {
            last_pos = mono_stack.back().first;
            mono_stack.pop_back();
        }
        mono_stack.push_back({last_pos, current_a});

        int end_range = i;
        
        for (int k = mono_stack.size() - 1; k >= 0; --k) {
            int start_range = mono_stack[k].first;
            long long min_val = mono_stack[k].second;
            
            long long cost = (current_a + min_val - 1) / min_val;

            long long min_prev_dp = query(start_range - 1, end_range - 1, 1, 0, seg_tree_size - 1);
            
            if (min_prev_dp != INF) {
                dp[i] = min(dp[i], min_prev_dp + cost);
            }
            
            end_range = start_range - 1;
        }
        update(i, dp[i], 1, 0, seg_tree_size - 1);
    }
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}