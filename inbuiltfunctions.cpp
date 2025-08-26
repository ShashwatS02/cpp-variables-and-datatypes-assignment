#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 10, b = 25;

    // 1. min
    cout << "Min of " << a << " and " << b << " is: " << min(a, b) << endl;

    // 2. max
    cout << "Max of " << a << " and " << b << " is: " << max(a, b) << endl;

    // 3. sqrt
    cout << "Square root of " << b << " is: " << sqrt(b) << endl;

    // 4. pow
    cout << a << " raised to power 2 is: " << pow(a, 2) << endl;

    // 5. abs
    int diff = a - b;
    cout << "Absolute difference between " << a << " and " << b << " is: " << abs(diff) << endl;

    return 0;
}
