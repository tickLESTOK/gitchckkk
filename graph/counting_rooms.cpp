#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

void bfs(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&vis){
    int n= mat.size();
    int m= mat[0].size();
    int delr[4]= {0,-1,0,1};
    int delc[4]= {1,0,-1,0};
   queue<pair<int,int>>q;
   q.push({i,j});
   vis[i][j]=1;

   while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();

    for(int k=0;k<4;k++){
        int nr= r+delr[k];
        int nc= c+delc[k];

        if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]=='.' && !vis[nr][nc]){
            vis[nr][nc]=1;
            q.push({nr,nc});
        }
    }

   }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char curr;
            cin>>curr;
            mat[i][j]=curr;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(mat[i][j]=='.' && !vis[i][j]){
              cnt++;
              bfs(i,j,mat,vis);
          }
        }
    }

    cout<<cnt;

    
}