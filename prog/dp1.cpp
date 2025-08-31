
// same as min coins to make change
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll a){
    for (int i = 2; i <= sqrt(a); i++){
        if (a % i == 0) return false;
    }

    return true;
}

// helper to get unique prime factors for small numbers
unordered_set<ll> get_fac(ll num){
    unordered_set<ll> fac;

    while (num % 2 == 0){
        fac.insert(2);
        num /= 2;
    }

   for (ll d = 3; d * d <= num; d += 2){
        while (num % d == 0){
            fac.insert(d);
            num /= d;
        }
    }

    if (num > 1) fac.insert(num);
    return fac;
}

// main soln
void solve(){
    // 7 segment
    // 1 2 3 4 5 6

    ll len, seg; cin >> len >> seg;
    vector<ll> buckets;
    ll maxB = 0;

    for (int i = 0; i < len; i++){
        ll e; cin >> e; buckets.push_back(e);
        maxB = max(maxB, e);
    }

    vector<ll> dp(seg + 1, maxB);
    sort(buckets.begin(), buckets.end());
    dp[0] = 0;

    for (ll amt = 1; amt <= seg; amt++){
        // do you want to take the bucket 
        for (ll b : buckets){
            if (amt < b) continue;
             dp[amt] = min(dp[amt], 1 + dp[amt - b]);
        }
    }

    cout << dp[seg] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
