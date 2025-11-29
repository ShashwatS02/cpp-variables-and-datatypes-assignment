#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    bool yes = false;
    for(int i = 0; i + 6 < (int)s.size(); i++) {
        if((s.substr(i,7) == "0000000") || (s.substr(i,7) == "1111111")) {
            yes = true;
            break;
        }
    }
    cout << (yes ? "YES\n" : "NO\n");
}
