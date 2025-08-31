#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// helper structures
struct trie {

    trie *alph[26];
    bool isend;

    trie() {
        this->isend = false;
        for (int i = 0; i < 26; i++) {
            this->alph[i] = nullptr;
        }
    }
    ~trie() {
        for (int i = 0; i < 26; i++) delete alph[i];
    }

    string commonPrefix();

    void addword(string s){
        trie* curr = this;

        for (char c : s){
            int index = c - 'a';

            if (curr->alph[index] == nullptr){
                curr->alph[index] = new trie();
            }
            curr = curr->alph[index];
        }

        curr->isend = true;
    }

    bool search(const string s){
        trie *curr = this;


        for (char c : s){
            int index = c - 'a';
            if (curr->alph[index] == nullptr){
                return false;
            }

            curr = curr->alph[index];

        }

        return curr != nullptr && curr->isend;
    }
};

string trie::commonPrefix() {
    string f;
    trie* currNode = this;

    while (true){
        int count = 0;
        int next_index = -1;

        for (int i = 0; i < 26; i++){

            if (currNode->alph[i] != nullptr){
                count++;
                next_index = i;
            }

        }


        if (count == 1 && !currNode->isend){
            f += (char)('a' + next_index);
            currNode = currNode->alph[next_index];
        } else {
            break;
        }
    }

    return f;
}

bool isPrime(ll a){
    for (ll i = 2; i <= sqrt(a); i++){
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
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> dp(n + 1, 0);
    map<int, vector<int>> pos;
    for (int i = 1; i <= n; i++) {
        int v = a[i - 1];
        pos[v].push_back(i);
        dp[i] = dp[i - 1];

        if (pos.count(v)) {
            auto &p = pos[v];
            int cnt = p.size();
            if (cnt >= v) {
                int p1 = p[cnt - v];
                dp[i] = max(dp[i], dp[p1 - 1] + v);
            }
        }
    }
    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

