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
    int len, k; cin >> len >> k;
    int oneCount = 0, longest = 0;
    vector<int> ones; vector<int> zeros;
    string stuff; cin >> stuff;

    for (int i = 0; i < len; i++){
        int e = (int)(stuff[i] - '0');
        // check
        if (e == 1){
            oneCount ++;
            ones.push_back(i);
        } else {
            longest = max(longest, oneCount);
            oneCount = 0;
            zeros.push_back(i);
        }
    }

    longest = max(oneCount, longest);

    // if consequtive ones > k then knock knock
    if (longest >= k) {cout << "no" << endl; return;}

    // answer always exists here
    vector<ll> finalans(len);
    for (int i : zeros){
        finalans[i] = len;
        len--;
    }
    int a = 1;
    for (int i : ones){
        finalans[i] = a++;
    }

    cout << "yes" << endl;
    for (int e : finalans) cout << e << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
