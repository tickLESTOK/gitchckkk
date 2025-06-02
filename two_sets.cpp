#include <iostream>
#include <vector>
#include <set>
#include <numeric> 
#include <unordered_set>
typedef long long ll;
using namespace std;


void helper(vector<int>& v, unordered_set<int>& st, int n, ll target) {
    // Greedily select largest numbers until target is reached
    for (int i = n; i >= 1 && target > 0; i--) {
        if (st.find(i) != st.end() && i <= target) {
            v.push_back(i);
            st.erase(i);
            target -= i;
        }
    }
}

int main(){
    int n;
    cin>>n;
    // vector<int>set1(n);
    vector<int>v;
    unordered_set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }

  ll sum= (1ll * n * (n + 1)) / 2;
  if(sum%2){
    cout<<"NO";
  }
  else{
      cout<<"YES"<<endl;
      helper(v,st,n , sum/2);
    int l=v.size(),m=st.size();
    cout<<l<<endl;
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<m<<endl;
    for(auto it: st){
        cout<<it<<" ";
    }
    cout << endl;


  }
}