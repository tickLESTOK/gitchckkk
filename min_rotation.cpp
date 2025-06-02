#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
       
    unordered_map<char,int>mp;
    for(auto it:s){
        mp[it]++;
    }

    bool check=true;

    for(auto it:t){
        if(mp.count(it)){
            mp[it]--;
            if(mp[it]==0) mp.erase(it);
        }
    }

    check= mp.size()==0? false:true;
    if(s.size()!=t.size() || check){
        cout<<"not possible ";
    }

    else{
        int rot=0;
    string concat= s+s;
    if(concat.find(t)!= string::npos){
      int idx= concat.find(t);
      rot= idx<s.size()-idx?idx: s.size()-idx;
    }
        cout<<"minimum rotation reqired is : "<<rot;
    }
    

}