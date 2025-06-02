#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // Step 1: Count frequency of each character (A-Z)
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'A']++;
    }

    // Step 2: Check if palindrome is possible
    int odd_count = 0;
    char odd_char = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd_count++;
            odd_char = i + 'A'; // Store the character with odd frequency
        }
    }

    // If more than one character has odd frequency, no palindrome is possible
    if (odd_count > 1) {
        cout << "NO SOLUTION" << endl;
    }

    // Step 3: Construct the palindrome
    else
    {string left_half = "";
    string middle = "";
    
    // Collect half of each character's frequency for the left half
    for (int i = 0; i < 26; i++) {
        int count = freq[i] / 2; // Number of times to include in left half
        for (int j = 0; j < count; j++) {
            left_half += (char)(i + 'A');
        }
    }

    // If there is a character with odd frequency, it goes in the middle
    if (odd_count == 1) {
        middle = odd_char;
    }

    // Right half is the reverse of left half
    string right_half = left_half;
    reverse(right_half.begin(), right_half.end());

    // Combine left_half + middle + right_half
    string palindrome = left_half + middle + right_half;

    // Step 4: Output the result
    cout << palindrome << endl;}

   
}