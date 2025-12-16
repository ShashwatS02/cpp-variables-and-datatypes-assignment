#include <iostream>
using namespace std;

int main() {
    int n, val = 0;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op.find('+') != string::npos) val++;
        else val--;
    }
    cout << val << '\n';
}
