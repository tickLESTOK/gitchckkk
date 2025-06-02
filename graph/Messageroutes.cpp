#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Optimize I/O
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Adjacency list for the graph
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // BFS setup
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1); // To reconstruct path
    queue<int> q;
    q.push(1); // Start from Uolevi's computer (node 1)
    visited[1] = true;

    bool found = false;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == n) { // Reached Maija's computer
            found = true;
            break;
        }

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = node;
                q.push(next);
            }
        }
    }
// 5 5 
// 1 2
// 1 3
// 1 4 
// 2 3
// 5 4
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // Reconstruct path from n to 1
        vector<int> path;
        int v=n;
         while(v!=-1){
            path.push_back(v);
            v= parent[v];
        }
        reverse(path.begin(), path.end()); // Reverse to get path from 1 to n

        // Output path length and path
        cout << path.size() << endl;
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }
}