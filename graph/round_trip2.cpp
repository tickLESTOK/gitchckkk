#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> path_vis;
vector<int> parent;
vector<int> cycle_path;


int start_node = -1, end_node = -1;

bool dfs(int u, int par) {
    vis[u] = 1;
    path_vis[u] = 1;
    for (int v : adj[u]) {
        // if (v == par) continue; // ignore the edge to the parent

        if(!vis[v]){
             parent[v] = u;
             if (dfs(v, u))
                return true;
        }
         else if (path_vis[v]) {
			start_node = v;
            end_node = u;
            return true;
			}
        
    }
    path_vis[u]=0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    path_vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
    } else {

        cycle_path.push_back(start_node);
        for (int v = end_node; v != start_node; v = parent[v]) {
            cycle_path.push_back(v);
        }
        cycle_path.push_back(start_node);
        reverse(cycle_path.begin(), cycle_path.end());

        cout << cycle_path.size() << "\n";
        for (int v : cycle_path) {
            cout << v << " ";
        }
        cout << "\n";
    }

}
