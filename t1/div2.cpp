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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    unordered_set<ll> candidates = get_fac(a[0]);
    unordered_set<ll> temp_facs = get_fac(a[0] + k);
    candidates.insert(temp_facs.begin(), temp_facs.end());

    ll target_prime = -1;
    for (ll p : candidates) {
        bool possible = true;
        for (ll val : a) {
            if ((val % p != 0) && ((val + k) % p != 0)) {
                possible = false;
                break;
            }
        }
        if (possible) {
            target_prime = p;
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        ll final_val = (a[i] % target_prime != 0) ? a[i] + k : a[i];
        cout << final_val;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
