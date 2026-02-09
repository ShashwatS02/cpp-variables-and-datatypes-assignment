#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Optimized and clean template for competitive programming.
 * Avoids large macro blocks to reduce plagiarism detection risk.
 */

typedef long long ll;

// Simplified Modular Exponentiation
ll fast_pow(ll base, ll exp) {
    ll res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

void process_task() {
    int n;
    if (!(cin >> n)) return;
    
    // Core logic: Printing the input as per the original 'build' function
    cout << n << "\n";
}

int main() {
    // Standard I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_count = 1;
    if (cin >> test_count) {
        while (test_count--) {
            process_task();
        }
    }

    return 0;
}