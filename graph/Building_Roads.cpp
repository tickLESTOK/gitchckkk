#include<iostream>
#include<vector>


using namespace std;
vector<int>parent;
int find(int node){
    if(node== parent[node]) return node;
    else return parent[node]= find(parent[node]);
}

void unite(int x,int y){
    int px= find(x);
    int py= find(y);

    if(px==py) return;
    else{
       parent[px]=py;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        unite(a,b);
    }

    int cnt=0;
    vector<pair<int,int>>path;

    for(int i=1;i<=n-1;i++){
        int a=i,b=i+1;
        int pa=find(a);
        int pb=find(b);

        if(pa==pb) continue;

        else{
            unite(a,b);
            path.push_back({a,b});
            cnt++;
        }
    }

    if(cnt==0) cout<<cnt;
    else{
        cout<<cnt<<endl;
        for(auto it:path){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}