#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int len;
        cin >> len;
        int mx = 0, i = 0;
        int c = 0;
        while (len--){
            int curr; cin >> curr;
            if (mx < curr){
                i = c;
                mx = curr;
            }

            c++;
        }

        if (i == c - 1|| i == 0) cout << "no" << endl;
        else cout << "yes" << endl;
    }

    return 0;
}