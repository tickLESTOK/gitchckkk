#include <iostream>
#include <vector>
typedef long long ll;
using namespace std; 

void helper(vector<ll>&ans, ll n){
    ans.push_back(n);

    while(n!=1){
        if(n&1){
            n=n*3 +1;
            ans.push_back(n);
        }else{
            n/=2;
            ans.push_back(n);
        }

    }
}

int main(){
    int n;
    cin>>n;
    vector<ll>ans;
    helper(ans,(1ll)*n);

    for(auto it: ans){
        cout<<it<<" ";
    }
}