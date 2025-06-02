#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;
int sr=-1,sc=-1, er=-1 , ec=-1;

 struct Cell {          // this is used for backtracking to find the path
    int ro, co;
    char move;
};

// input
// 5 4
// .#.M
// #MA.
// .MM.
// .M.#
// ....
 

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>> vis_time(n, vector<int>(m, INT_MAX));
    vector<vector<char>>mat(n,vector<char>(m));
    vector<vector<Cell>>parent(n,vector<Cell>(m,{-1,-1,0}));
    
     int delr[4]={0,-1,0,1};
     int delc[4]={1,0,-1,0};
     string path="RULD";
     queue<pair<int,pair<int,int>>>q1;
     queue<pair<int,pair<int,int>>>q2;
     bool found=false;

//     5 8
// ########
// #M..A..#
// #.#.M#.#
// #M#..#..
// #.######

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            mat[i][j]=c;
            if(c=='A'){
                sr=i;
                sc=j;
                q1.push({0,{i,j}});
            }
            else if(c=='M'){
                vis_time[i][j]=0;
                q2.push({0,{i,j}});
            }
            else
            vis_time[i][j]=INT_MAX;

        }
    }


    
     while(!q2.empty()){
        int t=q2.front().first;
        int r=q2.front().second.first;
        int c=q2.front().second.second;
        q2.pop();

         for(int j=0;j<4;j++){
            int nr= r+delr[j];
            int nc= c+delc[j];

                   if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]=='.' && !vis[nr][nc]){
                   vis[nr][nc]=1;
                   vis_time[nr][nc]=t+1;
                   q2.push({t+1,{nr,nc}});

                }
            }
        }

    vis = vector<vector<int>>(n, vector<int>(m, 0));
    vis[sr][sc]=1;

    while(!q1.empty()){
        int t=q1.front().first;
        int r=q1.front().second.first;
        int c=q1.front().second.second;
        q1.pop();
        
             if( r==n-1 || r==0 ||c==m-1 ||c==0){
             er=r;
             ec=c;
             found=true;
             break;
             }

             for(int i=0;i<4;i++){
                int nr= r+ delr[i];
                int nc= c+ delc[i];

                 if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]=='.' && !vis[nr][nc] && vis_time[nr][nc]>t+1){
                 parent[nr][nc]={r,c,path[i]};
                  vis[nr][nc]=1;
                  q1.push({t+1,{nr,nc}});
                 }


             }

    }
    
     if(!found){
        cout<<"NO";}
   
        else
   { 
        string ans;
        int r = er, c = ec;
        while (r != sr || c != sc) {
            ans += parent[r][c].move;
            int pr = parent[r][c].ro;
            int pc = parent[r][c].co;
            r = pr;
            c = pc;
        }

      reverse(ans.begin(),ans.end());
     cout<<"YES"<<endl;
     cout<<ans.size()<<endl;
      cout<<ans;
    
    
    }
    
}


