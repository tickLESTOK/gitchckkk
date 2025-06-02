#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;

   if(n==1) cout<<1;
   if(n==2||n==3) cout<<"NO SOLUTION";
   if(n==4) {cout<<2<<" "<<4<<" "<<1<<" "<<3;}



 if(n>4){  vector<int>even,odd;

   for(int i=1;i<=n;i++){
    if(i%2) odd.push_back(i);
    else
        even.push_back(i);
   }
       
   sort(odd.rbegin(),odd.rend());
   sort(even.rbegin(),even.rend());

   for(auto it:even){
    cout<<it<<" ";
   }
   for(auto it:odd){
    cout<<it<<" ";
   }}

   

}