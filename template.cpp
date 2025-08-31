#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

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
void solve(){ }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
