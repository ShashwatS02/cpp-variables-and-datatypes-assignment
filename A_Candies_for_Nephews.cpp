#include <iostream>
#include <vector>

using namespace std;

void resolve_case() {
    int initial_candies;
    cin >> initial_candies;
    int remainder = initial_candies % 3;
    if (remainder == 0) {
        cout << 0 << endl;
    } else {
        cout << 3 - remainder << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int scenario_count;
    cin >> scenario_count;
    while (scenario_count > 0) {
        resolve_case();
        scenario_count--;
    }

    return 0;
}