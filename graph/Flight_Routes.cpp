#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    // k shortest distances for each node, stored as max-heaps (to efficiently remove the largest)
    vector<priority_queue<ll>> dist(n + 1);

    // Min-heap for Dijkstra-style traversal
    priority_queue<pli, vector<pli>, greater<>> pq;
    pq.emplace(0, 1);
    dist[1].push(0);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        for (auto &[v, w] : adj[u]) {
            ll new_dist = d + w;

            if (dist[v].size() < k) {
                dist[v].push(new_dist);
                pq.emplace(new_dist, v);
            } else if (dist[v].top() > new_dist) {
                dist[v].pop();
                dist[v].push(new_dist);
                pq.emplace(new_dist, v);
            }
        }
    }

    // Extract k values from dist[n], which is a max-heap
    vector<ll> ans;
    while (!dist[n].empty()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    sort(ans.begin(), ans.end());
    for (ll x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
