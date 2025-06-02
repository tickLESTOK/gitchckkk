#include <iostream>
#include<vector>
#include<queue>
//bipertite graph

using namespace std;

bool bfs(int i, vector<vector<int>>&adj,vector<int>&clr, vector<int>&vis){
    queue<pair<int,int>>q;
    q.push({i,-1});
    clr[i]=1;
    while(!q.empty()){
       int i= q.front().first;
       int par= q.front().second;
       q.pop();

       for(auto it:adj[i]){
        if(!vis[it]){
            vis[it]=1;
            clr[it]= clr[i]==1?2:1;
            q.push({it,i});
        }
        else if(clr[it]==clr[i]){
            return false;
        }
       }

    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>clr(n+1);
    vector<int>vis(n+1,0);

    bool check=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            check= bfs(i,adj,clr,vis);
            if(!check) break;
        }
    }

    if(!check){
        cout<<"IMPOSSIBLE";
    }else{
       for(int i=1;i<=n;i++){
        cout<<clr[i] <<" ";
       }
    }

}