#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// macros
#define nl cout << endl;
#define say(t) cout << t << endl;

void solve(){
    int len; cin >> len;
    map<int, int> tr;
    bool damn = false;
    while (len--){
        int x; cin >> x;
        tr[x] ++;
        if (tr[x] == 2) {damn = true;}
    }

    cout << (damn ? "yes" : "no") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}