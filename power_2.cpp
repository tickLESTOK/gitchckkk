#include <iostream>
typedef long long ll;
const ll MOD = 1e9 + 7;

ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod; // Ensure base is within mod
    while (exp > 0) {
        if (exp & 1) { // If exp is odd, multiply result by base
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp >>= 1; // Divide exp by 2
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    ll ans = power(2, n, MOD);
    std::cout << ans << std::endl;
    return 0;
}