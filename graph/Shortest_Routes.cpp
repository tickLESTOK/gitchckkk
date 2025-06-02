#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<long long,int> p;
int main(){
    int n,m;
    cin>>n>>m;
   vector<vector<pair<int, long long>>> adj(n + 1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    
    vector<long long>dis(n+1,LLONG_MAX);
    priority_queue<p,vector<p>,greater<p>>pq;
    dis[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        long long wt= pq.top().first;
        int u= pq.top().second;
        pq.pop();
        if (wt > dis[u]) continue;
        for(auto it:adj[u]){
            int v=it.first;
            long long d=it.second;

            if(dis[v]>d+wt){
                dis[v]=d+wt;
                pq.push({dis[v],v});
            }
        }
    }

//    3 4
// 1 2 6
// 1 3 2
// 3 2 3
// 1 3 4

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}


//tc= ElogV
// o(V)+o(E)