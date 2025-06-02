#include <iostream>
#include <numeric>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    int m;
    for(int i=0;i<n-1;i++){
        int m;
         cin>>m;
         arr.push_back(m);
    }

    ll sum = accumulate(arr.begin(),arr.end(),0ll);
    ll ideal= n*(1ll)*(n+1)/2 ;

    cout << ideal - sum << endl;
    return 0;
}