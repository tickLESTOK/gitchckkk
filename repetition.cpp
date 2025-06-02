#include <iostream>
#include <string>
#include<vector>
using namespace std;

 
int helper(string input){
    // vector<char>
    int n= input.size();
    int l=0,r=0,cnt=0,maxi=0;
    char curr;
   
    while( r<n &&l<=r ){
    if(l==r){
       curr=input[r];
       cnt++;
       r++;
    }
    if(input[l]==input[r]){
        cnt++;
        r++;
    }
    else{
       l=r;
       maxi= max(cnt,maxi);
       cnt=0;
    }}
    
    maxi= max(cnt,maxi);
     return maxi;

}

int main(){
    string input;
    cin>>input;
    int ans= helper(input);
    cout<<ans;
  

   

}