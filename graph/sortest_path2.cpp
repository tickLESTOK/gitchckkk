#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // Initialize adjacency matrix
    vector<vector<ll>> mat(n + 1, vector<ll>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; i++) {
        mat[i][i] = 0; // Set self-distances to 0 before Floyd-Warshall
    }

    // Read edges (undirected)
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b], c);
        mat[b][a] = min(mat[b][a], c); // Bidirectional edge
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    // Process queries
    vector<ll> ans;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        ll dist = mat[a][b];
        if (dist == LLONG_MAX) dist = -1; // Unreachable
        ans.push_back(dist);
    }

    // Output results
    for (auto it : ans) {
        cout << it << endl;
    }

    return 0;
}