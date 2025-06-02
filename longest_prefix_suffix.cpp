#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int n= s.size();
    vector<int>lps(n);
    
    lps[0]=0;
    int len=0,maxlen=0,i=1;

    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            maxlen= max(len,maxlen);
            i++;
        }else{
            if(len!=0)
            len= lps[len-1];
            else{
                len=0;
                lps[i]=0;
                i++;
            }
        }

    }

    int j=0;
    i=0;
    int m=t.size();
     vector<int>occour;
    while(i<m){
        if(s[j]==t[i]){
             i++;
             j++;
        }
        if(j==n){
            occour.push_back(i-n);
            j= lps[j-1];

        }
        else if((i < m && s[j] != t[i])) {
              if(j!=0){
                j=lps[j-1];
              }
              else{
                i++;
              }
        }
    }



    cout<< maxlen<<endl;
    for(auto it: occour){
        cout<<it<<endl;
    }
}