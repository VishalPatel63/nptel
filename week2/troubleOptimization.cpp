#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool isSorted(vector<int> &arr){
    for(int i =0; i<arr.size()-1; i++){
        if(arr[i] > arr[i+1]){
            // cout<<i<<endl;
            return false;
        }
    }
    return true;
}
int main()
{
    // vector<int> arr = {5,6,6,4,3};
    vector<int> arr = {5,2,1,7,3,4,8,6};
    // vector<int> arr = {5,6,5,4,3};

    vector<int> even,odd;
    for(int i =0; i<arr.size(); i++){
        if(i%2 == 0){
            even.push_back(arr[i]);
        }
        else{
            odd.push_back(arr[i]);
        }
    }

    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());

    for(int i =0, evenIdx = 0, oddIdx = 0; i<arr.size(); i++){
      if(i%2 == 0){
        arr[i] = even[evenIdx++];
      }
      else{
        arr[i] = odd[oddIdx++];
      }

    }
   
//    for(int i =0; i<arr.size(); i++){
//     cout<<arr[i]<<" ";
//    }
   cout<<endl;
    if(isSorted(arr)){
        cout<<"sort ho gaya hai"<<endl;
    }
    else{
        // smae isame bhi loop laga ke index bata sakate hai
       cout<<"sort nahi hua "<<endl;
    }
    return 0;
}