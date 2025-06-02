#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate_anti(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n/2;i++){
            swap(mat[i][j],mat[n-1-i][j]);
        }
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            mat[i][j]=a;
        }
    }
    cout<<endl<<"matrix b4 rotation: "<<endl;
    for(int i=0;i<n;i++){

          for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
          }
         cout<<endl;
        }
    

    rotate_anti(mat);
      cout<<endl<<"matrix after rotation: "<<endl;
        for(int i=0;i<n;i++){

          for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
          }
         cout<<endl;
        }


}
