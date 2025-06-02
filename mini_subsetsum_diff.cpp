#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>

using namespace std;

int main(){
int n;
cin>>n;
vector<long long> nums;
    long long sum = 0;

for(int i=0;i<n;i++){
    long long ele;
    cin>>ele;
    nums.push_back(ele);
}


for(auto it:nums){
    sum+=it;
}


long long mini=sum;

for(int i=0;i<(1<<n);i++){
    long long sum1=0;
    for(int j=0;j<n;j++){
      if(i & (1<<j)){
        sum1+= nums[j];
      }
    }

    // In a bitmask i (e.g., 00101 for n=5), bit 0 (LSB) corresponds to nums[0], bit 1 to nums[1], etc.
    long long sum2= sum-sum1;
    long long diff= abs(sum2-sum1);
    mini=min(mini,diff);
}


cout << mini << endl;


}