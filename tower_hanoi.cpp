#include <iostream>
using namespace std;
typedef long long ll;


void helper(int n,int src,int auxi,int dest){
    if(n==1) {cout<<src<< " "<<dest<<endl;
      return;
    }
    helper(n-1, src,dest,auxi);
    cout<< src<<" "<<dest<<endl;
    helper(n-1, auxi,src,dest);

}

int main(){
    int n;
    cin>>n;
    ll ans= (1ll<<n)-1;
    cout<< ans<<endl;
    helper(n,1,2,3);
}