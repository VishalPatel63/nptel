#include<bits/stdc++.h>
using namespace std;
vector<int> reverSortEngineering(int n,int c){

  vector<int> arr(n);
  for(int i =0; i<n; i++){
    arr[i] = i+1;
  }
  int minCost = n-1;
  int maxCost = (n*(n-1))/2 -1;
  if(c < minCost || c> maxCost){
    return {};
  }

  c = c-minCost;
  for(int i = n-2; i>= 0; i--){
    int j =  i + min(c,n-i-1);
    c -= j-i;
   reverse(arr.begin()+i, arr.begin()+j+1);
  }
  return arr;
}
int main()
{
    int n = 4;
    int c = 5;
    vector<int> res = reverSortEngineering(n,c);
    cout<<res.size()<<endl;

    if(res.empty()){
        cout<<"imposible"<<endl;
    }
    else{

    for(int i =0; i<n; i++){
        cout<<res[i]<<" ";
    }
    }
    return 0;
}