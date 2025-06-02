#include<iostream>
#include <vector>
#include <string>
using namespace std;

int result=0;
vector<int>dig1(15,0);
vector<int>dig2(15,0);
vector<int>col(8,0);

void solve(int row,vector<string>&v){
     if(row==8){
        result++;
        return;
     }
     for(int c=0;c<8;c++){
        if(v[row][c]=='*'||col[c] || dig1[row-c+7]|| dig2[row+c]) continue;
      col[c] = dig1[row - c + 7] = dig2[row + c] = 1;
        solve(row+1,v);
        col[c] = dig1[row-c+7]= dig2[row+c]=0;
     }
}


int main(){
    vector<string>v(8);
    for(int i=0;i<8;i++){
        string curr;
        cin>>curr;
        v[i]=curr;
    }
 
      solve(0,v);

  cout<< result;
}