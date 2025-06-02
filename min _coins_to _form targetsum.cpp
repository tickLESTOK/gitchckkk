#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

// Recursive DP function to compute minimum coins
int minRequiredCoin(int i, int target, vector<int>& num, vector<vector<int>>& dp, vector<vector<int>>& choices) {
    if (target == 0) return 0;
    if (i == 0) {
        if (target % num[0] == 0) {
            choices[0][target] = 1; // Take coin at index 0
            return target / num[0];
        }
        return 1e9;
    }
    if (dp[i][target] != -1) return dp[i][target];

    // Don't take the coin at index i
    int not_take = minRequiredCoin(i - 1, target, num, dp, choices);
    // Take the coin at index i
    int take = 1e9;
    if (num[i] <= target) {
        take = 1 + minRequiredCoin(i, target - num[i], num, dp, choices);
    }

    // Store the choice that leads to the minimum
    if (take < not_take) {
        choices[i][target] = 1; // Take coin at index i
        dp[i][target] = take;
    } else {
        choices[i][target] = 0; // Don't take coin at index i
        dp[i][target] = not_take;
    }

    return dp[i][target];
}

// Function to reconstruct coins used and their frequencies
void reconstructCoins(int i, int target, vector<int>& num, vector<vector<int>>& choices, vector<int>& coins_used) {
    if (target == 0 || i < 0) return;
    if (i == 0) {
        if (target % num[0] == 0) {
            int count = target / num[0];
            for (int k = 0; k < count; k++) {
                coins_used.push_back(num[0]);
            }
        }
        return;
    }

    if (choices[i][target] == 1) {
        // Took the coin at index i
        coins_used.push_back(num[i]);
        reconstructCoins(i, target - num[i], num, choices, coins_used);
    } else {
        // Did not take the coin at index i
        reconstructCoins(i - 1, target, num, choices, coins_used);
    }
}

// Function to compute frequencies of coins used
unordered_map<int, int> getCoinFrequencies(vector<int>& coins_used) {
    unordered_map<int, int> freq;
    for (int coin : coins_used) {
        freq[coin]++;
    }
    return freq;
}

// Main function to compute minimum coins and print coins with frequencies
void minimumElements(vector<int>& num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    vector<vector<int>> choices(n, vector<int>(x + 1, -1)); // Tracks take/not-take decisions

    int ans = minRequiredCoin(n - 1, x, num, dp, choices);
    if (ans >= 1e9) {
        cout << "Target sum cannot be formed with given coins." << endl;
        return;
    }

    // Reconstruct the coins used
    vector<int> coins_used;
    reconstructCoins(n - 1, x, num, choices, coins_used);

    // Compute frequencies
    unordered_map<int, int> freq = getCoinFrequencies(coins_used);

    // Print results
    cout << "Minimum number of coins needed: " << ans << endl;
    cout << "Coins used: ";
    for (int coin : coins_used) {
        cout << coin << " ";
    }
    cout << endl;
    cout << "Coin frequencies:" << endl;
    for (const auto& pair : freq) {
        cout << "Coin " << pair.first << ": " << pair.second << " time(s)" << endl;
    }
}

// Example usage
int main() {
    vector<int> num = {1, 3, 4};
    int x = 6;
    minimumElements(num, x);
    return 0;
}