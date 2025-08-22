#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int l;
        cin >> l;
        int s = 0;
        while (l--){
            int i; cin >> i;
            i = (i == 0) ? 1 : i;
            s += i;
        }

        cout << s << endl;
    }
}