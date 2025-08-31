#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define ll long long

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
        } else break;
    }

    return f;
}

// main soln
auto solve(){
    ll n, a, b;
    cin >> n >> a >> b;

    if ((b % 2 == n % 2) && (a < b || a % 2 == b % 2)) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
