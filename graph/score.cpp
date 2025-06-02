#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m ;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
// 4 4
// 1 2 1
// 2 3 1
// 3 2 1
// 1 4 1
    vector<ll>dist(n+1,LLONG_MIN);
    dist[1]=0;
    priority_queue<pair<ll,int>>pq;
    pq.push({0,1});

    while(!pq.empty()){
        ll wt= pq.top().first;
        int node= pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int v=it.first;
            int p=it.second;

            if(dist[v]<wt+p){
                dist[v]=wt+p;
                pq.push({dist[v],v});
            }
        }
    }
     if(dist[n]==LLONG_MIN)
    cout<<-1;
    else 
    cout<<dist[n];

}