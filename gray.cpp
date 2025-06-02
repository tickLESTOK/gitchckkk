#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 1 << n; // 2^n

    for (int i = 0; i < total; i++) {
        // Compute Gray code: i ^ (i >> 1)
        int gray = i ^ (i >> 1);
        
        // Convert to binary string of length n
        string binary = "";
        for (int j = n - 1; j >= 0; j--) {
            binary += (gray & (1 << j)) ? '1' : '0';
        }
        
        // Print the binary string
        cout << binary << endl;
    }

}