#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    bool all_upper=true;
    for(int i=1;i<(int)s.size();i++) if(islower(s[i])) all_upper=0;
    if(all_upper){
        for(auto &c:s) c=(islower(c)?toupper(c):tolower(c));
        cout<<s;
    }else cout<<s;
}
