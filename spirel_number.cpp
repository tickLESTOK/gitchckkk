#include <iostream>
#include <vector>
// #include <cmath>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

ll find_val(ll x,ll y){
    ll ans=0;
    if(x==1 && y==1) return 1;
    ll maxi= max(x,y);
    ll start= (maxi-1)*(maxi-1);
    bool clock_wise=false;
    if(maxi%2==0)
    clock_wise=true;

   if(clock_wise){
        ll val= abs(x-1)+abs(maxi-y)+1;
        ans= start+val;
    }
    else{
        ll val= abs(1-y)+abs(maxi-x)+1;
        ans= start+val;
   }

   return ans;

}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    for(int i=0;i<n;i++){
        int a,b;
        a=v[i].first;
        b=v[i].second;

        ll ans= find_val((ll)a,(ll)b);
        if(i==n-1){
            cout<<ans;
        }
        else{
            cout<<ans<<endl;
        }
    }

}