#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> pa(n), pb(n); // Permutations for A and B
    int e = n - (a + b); // Number of equal rounds
    // Step 1: Equal rounds
    for (int i = 0; i < e; i++) {
        pa[i] = pb[i] = i + 1; // Both play 1, 2, ..., e
    }
    // Step 2: A's win rounds
    int pos = e;
    int low = e + 1; // Lowest available number
    int high = n; // Highest available number
    for (int i = 0; i < a; i++) {
        pa[pos] = high--; // A gets highest numbers
        pb[pos] = low++; // B gets lowest numbers
        pos++;
    }
    // Step 3: B's win rounds
    for (int i = 0; i < b; i++) {
        pb[pos] = high--; // B gets highest remaining numbers
        pa[pos] = low++; // A gets lowest remaining numbers
        pos++;
    }
    // Output the permutations
    for (int x : pa) cout << x << " ";
    cout << endl;
    for (int x : pb) cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}