#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

 ll count_steps(vector<int>&arr,int n){
    int prev= arr[0] , curr;
     ll steps=0;
    for(int i=1;i<n;i++){
        curr= arr[i];
        // maxi=max(maxi,curr);
       if(curr>=prev) {
        prev= curr;
        continue;
    
    }
      
       else{
        steps+=(ll)(prev-curr);
        arr[i]+=(prev-curr);
       }

      prev= arr[i];
    }

    return steps;
 }

int main(){
    int n;
    cin>>n;
    if(n==1) {
        cout << 0;
        return 0;  // 🔴 fix: stop further execution
    }
    vector<int>arr;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        arr.push_back(m);
    }

    ll count= count_steps(arr,n);
    cout<<count;
}
