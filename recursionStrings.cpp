#include <bits/stdc++.h>
using namespace std;

bool checkpal(string str, int start, int end) {
    if (start >= end) return 1;
    if (str[start] != str[end]) {
        return 0;
    }
    return checkpal(str, start+1, end-1);
}

int count (string str, int index) {
    if (index == -1) return 0;
    //vowel hoga
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u') {
        return 1 + count (str, index - 1);
    }
    //nhi hoga
    return count (str, index - 1);
}

void rev(string &str, int start, int end) {
    if (start >= end) return;
    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    rev(str, start+1, end-1);
}

void lowertoupper (string &str, int index) {
    if (index == -1) return;
    str[index] = 'A'+str[index]-'a';
    lowertoupper(str, index-1); 
}

int main() {

    //check palindrome
    // string str = "nommon";
    // cout << checkpal(str, 0, 5) << endl;

    //count vowels
    // string str = "shashwat";
    // cout << count(str,7) << endl;

    //reverse a string
    // string str = "shashwat";
    // rev(str, 0, 7);
    // cout << str << endl;

    //lower to uppercase
    string str = "shashwat";
    lowertoupper(str, 7);
    cout << str << endl;

    return 0;
}