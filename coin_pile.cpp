#include <iostream>
#include <vector>
typedef long long  ll;
using namespace std;

int main(){
    int t;
    cin >> t; // Read number of test cases

    while (t--) {
        ll a, b;
        cin >> a >> b;
        
        // Check if piles can be emptied
        if ((a + b) % 3 == 0 && 2 * min(a, b) >= max(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


}

// mai hun awaara aashik bhoolna nhi