#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
int sr=-1,sc=-1, er=-1 , ec=-1;

 struct Cell {
    int ro, co;
    char move;
};

bool bfs(int i, int j, vector<vector<char>> &mat, vector<vector<int>> &vis, string &a,vector<vector<Cell>>& parent)
{
    int n = mat.size();
    int m = mat[0].size();
    int delr[4] = {0, -1, 0, 1};
    int delc[4] = {1, 0, -1, 0};
    string dir = "RULD";
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // if (mat[r][c] == 'B')
        //     return true;

        for (int k = 0; k < 4; k++)
        {
            int nr = r + delr[k];
            int nc = c + delc[k];
            // char c = dir[k];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&(mat[nr][nc] == '.' || mat[nr][nc] == 'B') && !vis[nr][nc])
            {
                parent[nr][nc] = {r, c, dir[k]};
                vis[nr][nc] = 1;
                q.push({nr, nc});
                 if (mat[nr][nc] == 'B') {
                    er = nr;
                    ec = nc;
                    return true;
                }
            }
        }
    }
    return false;
}

// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<Cell>> parent(n, vector<Cell>(m, {-1, -1, 0}));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char curr;
            cin >> curr;

            if(curr=='A') { sr=i;
             sc=j;}
            if(curr=='B') { er=i;
             ec=j;}

            mat[i][j] = curr;
        }
    }

    int cnt = 0;
    bool br = false;
    bool found = false;
    string a = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A' && !vis[i][j])
            {
                if (bfs(i, j, mat, vis, a,parent))
                {
                    found = true;
                    br = true;
                    // break;
                }
            }
           
        }
    }

    if (found)
    {
       
        int r=er,c=ec;
        while(r!=sr || c!=sc){
            int pr= parent[r][c].ro;
            int pc= parent[r][c].co;
            a+=parent[r][c].move;

            r=pr;
            c=pc;
        }

        reverse(a.begin(),a.end());
        cout << "YES" << endl;
        cout << a.size() << endl;
        cout << a << endl;
    }
    else
        cout << "NO" << endl;
}