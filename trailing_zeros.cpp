#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long x;
    cin>>x;
    
    long long ans=0;

    //  for(int i=5;i<=x;i*=5){
    //      ans+=x/i;
    //  }
    for (long long i = 5; i <= x; i *= 5) {
        ans += x / i;
    }

    cout<< ans;
}




