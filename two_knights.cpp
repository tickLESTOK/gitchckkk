#include <iostream>
#include <numeric>
#include <vector>
typedef long long ll;
using namespace std;


//in each 2*3 matrix there are exactly 
ll helper(ll i){
    ll n=i*i;
    if(i==1) return 0;
    if(i==2) return 6;
    ll ans;
    ll total= (n*(n-1))/2;
    ll to_remove=4*(i-1)*(i-2);
    ans= total-to_remove;
    return ans;
}

int main(){
    int n;
    cin>>n;
    // int cnt=0;
    // if(n==0|| n==1) cout<<0;

    for(int i=1;i<=n;i++){
        ll cnt= helper((ll)i);
        cout<<cnt<<endl;
    }
}