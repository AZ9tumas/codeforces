#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int lenA; cin >> lenA;
        string a; cin >> a;
        int lenB; cin >> lenB;
        string b; cin >> b;

        string order; cin >> order;
        int count = 0;
        string c = a;

        int startTracker = 0;
        int endTracker = b.length() - 1;

        while ((count++) < lenB){
            char thing = order[count - 1];
            if (thing == 'D'){
                // behind
                c += b[count - 1];
                endTracker --;
            } else if (thing == 'V'){
                c = b[count - 1] + c;
                startTracker ++;
            }
        }

        cout << c << endl;
    }

    return 0;
}
