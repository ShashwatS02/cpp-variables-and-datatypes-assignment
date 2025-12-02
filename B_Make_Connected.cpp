#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring> // For memset

using namespace std;

int n_size;
vector<string> grid_layout;
bool visited_cells[105][105];
bool initial_black_cells[105][105];

// Helper to check bounds
bool is_valid(int r, int c) {
    return r >= 0 && r < n_size && c >= 0 && c < n_size;
}

// Helper to check if a cell in a boolean array is true
bool check_status(int r, int c, bool arr[105][105]) {
    if (!is_valid(r, c)) {
        return false;
    }
    return arr[r][c];
}

// The new "is_safe" check based on the asymmetric rules from samples
// We are adding (r, c) to our 'visited' component.
// Does this new cell create a violation?
bool is_safe_to_add(int r, int c) {
    // 1. Check for Vertical 3-in-a-row
    // Check (r-2, c), (r-1, c), (r, c)
    if (check_status(r - 1, c, visited_cells) && check_status(r - 2, c, visited_cells)) return false;
    // Check (r-1, c), (r, c), (r+1, c)
    if (check_status(r - 1, c, visited_cells) && check_status(r + 1, c, visited_cells)) return false;
    // Check (r, c), (r+1, c), (r+2, c)
    if (check_status(r + 1, c, visited_cells) && check_status(r + 2, c, visited_cells)) return false;

    // 2. Check for Horizontal 4-in-a-row
    // Check (r, c-3)...(r, c)
    if (check_status(r, c - 1, visited_cells) && check_status(r, c - 2, visited_cells) && check_status(r, c - 3, visited_cells)) return false;
    // Check (r, c-2)...(r, c+1)
    if (check_status(r, c - 2, visited_cells) && check_status(r, c - 1, visited_cells) && check_status(r, c + 1, visited_cells)) return false;
    // Check (r, c-1)...(r, c+2)
    if (check_status(r, c - 1, visited_cells) && check_status(r, c + 1, visited_cells) && check_status(r, c + 2, visited_cells)) return false;
    // Check (r, c)...(r, c+3)
    if (check_status(r, c + 1, visited_cells) && check_status(r, c + 2, visited_cells) && check_status(r, c + 3, visited_cells)) return false;
    
    return true;
}


bool run_solve() {
    cin >> n_size;
    grid_layout.assign(n_size, "");
    int initial_black_count = 0;
    pair<int, int> start_pos = {-1, -1};

    for (int i = 0; i < n_size; ++i) {
        cin >> grid_layout[i];
        for (int j = 0; j < n_size; ++j) {
            initial_black_cells[i][j] = false;
            visited_cells[i][j] = false;
            if (grid_layout[i][j] == '#') {
                initial_black_count++;
                initial_black_cells[i][j] = true;
                if (start_pos.first == -1) {
                    start_pos = {i, j};
                }
            }
        }
    }

    if (initial_black_count == 0) {
        return true; // Can always paint one
    }

    // --- Pre-check the initial grid for impossible states ---
    // This logic must match the BFS's "is_safe" logic
    for (int i = 0; i < n_size; ++i) {
        for (int j = 0; j < n_size; ++j) {
            if (initial_black_cells[i][j]) {
                // Check for initial Vertical 3-in-a-row
                if (check_status(i - 1, j, initial_black_cells) && check_status(i - 2, j, initial_black_cells)) return false;
                
                // Check for initial Horizontal 4-in-a-row
                if (check_status(i, j - 1, initial_black_cells) && check_status(i, j - 2, initial_black_cells) && check_status(i, j - 3, initial_black_cells)) return false;
            }
        }
    }

    // --- Run the BFS ---
    int black_cells_reached = 0;
    queue<pair<int, int>> q;
    
    q.push(start_pos);
    visited_cells[start_pos.first][start_pos.second] = true;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;

        if (initial_black_cells[r][c]) {
            black_cells_reached++;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (!is_valid(nr, nc) || visited_cells[nr][nc]) {
                continue;
            }

            // We can move to *any* unvisited cell (black or white)
            // as long as adding it is safe.
            visited_cells[nr][nc] = true; // Temporarily mark as part of component
            if (is_safe_to_add(nr, nc)) {
                q.push({nr, nc});
            } else {
                visited_cells[nr][nc] = false; // Unmark, this path is invalid
            }
        }
    }

    return black_cells_reached == initial_black_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t_cases;
    cin >> t_cases;
    while (t_cases--) {
        if (run_solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}