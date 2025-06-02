#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int main(){
string ans;
    cin >> ans;
    int n = ans.size();
    
    // Count frequency of each character
    map<char, int> freq;
    for (char c : ans) {
        freq[c]++;
    }
    
    // Calculate distinct permutations: n! / (freq1! * freq2! * ...)
    ll cnt = 1;
    for (int i = 1; i <= n; i++) {
        cnt *= i; // Compute n!
    }
    for (auto& p : freq) {
        for (int i = 1; i <= p.second; i++) {
            cnt /= i; // Divide by freq_i!
        }
    }
    sort(ans.begin(),ans.end());
    cout<<cnt<<endl;
    cout<<ans<<endl;
    
    while(next_permutation(ans.begin(), ans.end())){
        cout<<ans<<endl;
    }

}