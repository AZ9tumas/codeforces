#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){        
        unsigned long long inpt; cin >> inpt;
        
        long long div = 10;
        int c = 0; stack<unsigned long long> solns;

        while (div > 0 && div + 1 <= inpt){
            unsigned long long cd = div + 1;
            
            if (inpt % cd == 0) {
                c++;
                solns.push(inpt / cd);
            }
            div *= 10;
        }

        cout << c << endl;
        while (!solns.empty()){
            cout << solns.top() << " ";
            solns.pop();
        }
        cout << endl;
    }

    return 0;
}