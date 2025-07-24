#include <iostream>
using namespace std;

int main()
{

    int a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    bool flag = true;
    bool flag1 = false;

    (a < 50) && (a < b) ? cout << flag : cout << flag1;

    return 0;
}