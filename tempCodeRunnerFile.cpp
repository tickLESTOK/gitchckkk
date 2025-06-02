#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string s;
    cin>>s;
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
    cout<< maxlen;
}