#include <iostream>
#include <algorithm>

// This line requires a compiler that supports 128-bit integers, like GCC or Clang.
using int128 = __int128_t;

// Checks if the journey is possible in 'total_turns'.
bool is_possible(long long total_turns, int128 h, int128 d) {
    if (total_turns < d) {
        return false;
    }

    int128 rests_available = total_turns - d;
    int128 num_sequences = rests_available + 1;

    int128 q = d / num_sequences;
    int128 rem = d % num_sequences;

    int128 cost_big = (q + 1) * (q + 2) / 2;
    int128 cost_small = q * (q + 1) / 2;
    
    int128 rests_needed = 0;
    int128 current_h = h;

    // Calculate rests needed for the 'rem' longer move sequences
    if (rem > 0) {
        int128 C = cost_big;
        int128 k = rem;
        if (current_h > C) {
            int128 can_do_without_rest = (current_h - 1) / C;
            if (k <= can_do_without_rest) {
                current_h -= k * C;
            } else {
                current_h -= can_do_without_rest * C;
                rests_needed += C - current_h + 1;
                current_h = 1;
                rests_needed += (k - can_do_without_rest - 1) * C;
            }
        } else {
            rests_needed += C - current_h + 1;
            current_h = 1;
            rests_needed += (k - 1) * C;
        }
    }
    
    // Calculate rests needed for the remaining shorter move sequences
    if ((num_sequences - rem) > 0 && cost_small > 0) {
        int128 C = cost_small;
        int128 k = num_sequences - rem;
        if (current_h > C) {
            int128 can_do_without_rest = (current_h - 1) / C;
            if (k > can_do_without_rest) {
                current_h -= can_do_without_rest * C;
                rests_needed += C - current_h + 1;
                rests_needed += (k - can_do_without_rest - 1) * C;
            }
        } else {
            rests_needed += C - current_h + 1;
            rests_needed += (k - 1) * C;
        }
    }

    return rests_needed <= rests_available;
}

void solve() {
    long long h, d;
    std::cin >> h >> d;

    // Set a practical upper bound for the binary search
    long long low = d, high = 2LL * d + h, ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (is_possible(mid, h, d)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}