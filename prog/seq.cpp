#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

// helper structures
struct trie {

    trie *alph[26];
    bool isend;

    trie() {
        this->isend = false;
        for (ll i = 0; i < 26; i++) {
            this->alph[i] = nullptr;
        }
    }
    ~trie() {
        for (ll i = 0; i < 26; i++) delete alph[i];
    }

    string commonPrefix();

    void addword(string s){
        trie* curr = this;

        for (char c : s){
            ll index = c - 'a';

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
            ll index = c - 'a';
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
        ll count = 0;
        ll next_index = -1;

        for (ll i = 0; i < 26; i++){

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
    ll a1, k; cin >> a1 >> k;

    for (ll i = 1; i < k; i++){
        string a1s = to_string(a1);
        ll minc = (ll)'9', maxc = 0;
        for (char c : a1s){
            ll indx = c - '0';
            minc = min(minc, indx);
            maxc = max(maxc, indx);
        }

        if (minc == 0){
            // done
            cout << a1 << endl;
            return;
        }

        a1 = a1 + minc * maxc;
    }

    cout << a1 << endl;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
