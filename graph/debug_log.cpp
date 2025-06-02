#include <iostream>
#include <vector>
using namespace std;

int findDeveloperWithLog(int n, vector<int>& logReceiver, long long k) {
    // Convert to 0-based indexing
    vector<int> receiver(n);
    for (int i = 0; i < n; i++) {
        receiver[i] = logReceiver[i] - 1;
    }

    // Step 1: Detect cycle using Floyd's algorithm
    int slow = 0, fast = 0;
    do {
        slow = receiver[slow];
        fast = receiver[receiver[fast]];
    } while (slow != fast);

    // Step 2: Find start of cycle
    int start = 0;
    slow = 0;
    while (slow != fast) {
        slow = receiver[slow];
        fast = receiver[fast];
        start++;
    }

    // Step 3: Find cycle length
    int cycleLength = 1;
    fast = receiver[slow];
    while (slow != fast) {
        fast = receiver[fast];
        cycleLength++;
    }

    // Step 4: If k < start, just simulate from beginning
    if (k < start) {
        int current = 0;
        for (long long i = 0; i < k; i++) {
            current = receiver[current];
        }
        return current + 1; // back to 1-based
    }

    // Step 5: Simulate to the start of the cycle
    int current = 0;
    for (int i = 0; i < start; i++) {
        current = receiver[current];
    }

    // Step 6: Now move (k - start) steps within the cycle
    k = (k - start) % cycleLength;
    for (long long i = 0; i < k; i++) {
        current = receiver[current];
    }

    return current + 1; // back to 1-based
}
int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> logReceiver(n);
    for (int i = 0; i < n; i++) {
        cin >> logReceiver[i];
    }

    cout << findDeveloperWithLog(n, logReceiver, k) << endl;
    return 0;
}
