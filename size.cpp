#include <iostream>
using namespace std;

int main()
{

    int a = sizeof(char);
    int b = sizeof(short);
    int c = sizeof(int);
    int d = sizeof(long);
    int e = sizeof(long long);
    int f = sizeof(float);
    int g = sizeof(double);
    int h = sizeof(long double);
    int i = sizeof(bool);

    cout << "Size of fundamental data types:" << endl
         << "The sizeof(char): " << a << " bytes" << endl
         << "The sizeof(short): " << b << " bytes" << endl
         << "The sizeof(int): " << c << " bytes" << endl
         << "The sizeof(long): " << d << " bytes" << endl
         << "The sizeof(long long): " << e << " bytes" << endl
         << "The sizeof(float): " << f << " bytes" << endl
         << "The sizeof(double): " << g << " bytes" << endl
         << "The sizeof(long double): " << h << " bytes" << endl
         << "The sizeof(bool): " << i << " bytes";
    return 0;
}