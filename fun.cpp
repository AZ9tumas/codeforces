#include <bits/stdc++.h>
using namespace std;

#define INT long long

int main(){
    INT t;
    cin >> t;
    while (t--){
        INT n; cin >> n;

        // menu
        auto cost = [&](INT x){return pow(3, x + 1) + x * (pow(3, x - 1));};
        
        INT least = 0;
        while (pow(3, least) < n) least ++;
        if (pow(3, least) > n) least--;

        INT s = 0;
        INT leftover = n;
        while (leftover > 0 && least > -1){
            INT corresponding_cost = cost(least);
            INT quantity = (leftover / pow(3, least));
            s += quantity * corresponding_cost;
            leftover -= quantity * pow(3, least);
            least --;
        }

        cout << s << endl;
    }

    return 0;
}