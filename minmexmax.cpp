#include <bits/stdc++.h>
using namespace std;

void ans(vector<int> arr){

    string f = "yes";
    int a = -1;
    for (int i : arr){
        if (i == 0 || (a > -1 && i > -1 && a != i)) { f = "no"; break; }
        a = i != -1 ? i : a;
    }

    cout << f << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int len;
        cin >> len;
        vector<int> arr;
        while (len--){
            int i; cin >> i; arr.push_back(i);
        }
        ans(arr);
    }

    return 0;
}