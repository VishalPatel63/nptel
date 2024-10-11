#include<bits/stdc++.h>
using namespace std;

double findMean(vector<int> &pSum, vector<int> &v, int guess,int k,int n){
    if(k == 0){
        return v[guess];
    }
    double sum;
    sum += (pSum[guess+1] - pSum[guess - k]) + (pSum[n] - pSum[n-k]);
    return sum/(2*k+1);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
        int val;
    for(int i =0; i<n; i++){
        cin>>val;
        v.push_back(val);
    }

    // step 1 : sort the array
    sort(v.begin(),v.end());
    
    // to maximize skewness, we want to maximize mean - median

//    compute partial sums:

    vector<int> partialSum;
    partialSum.push_back(0);
    for(int i =0; i<n; i++){
        partialSum.push_back(partialSum.back()+v[i]);
    }
     
    //  for(int i =0; i<n; i++){
    //     cout<<v[i]<<" ";
    //  }
    //  cout<<endl;
    //  for(int i =0; i<n; i++){
    //     cout<<partialSum[i]<<" ";
    //  }
    //  cout<<endl;

  double ans = -1;
  double mean = 0, currMean = 0;
  int optGuess , optK;
  for(int guess = 0; guess<n; guess++){
    // we want to pick k element to the left of guess
    // and k elements from the end.
    // what's the largest possible value of k?
    int range = min(guess, n-guess-1);

    int L = 0, R = range, mid = (L+R)/2;

    while(R-L > 0){
        // mid is the current k
        currMean = findMean(partialSum,v,guess, mid, n);

        // should we increase k
        int k = mid+1;
        int a = v[n-k];
        int b = v[guess-k];

        if(double(a+b)/2 <= currMean)  {
            R = max(mid, L);
        }
        else{
            L = min(mid+1,R);
        }

        mid = (L+R)/2;
    }

//    when L = R we have found k
    mean = findMean(partialSum,v,guess, L,n);

        //  we have find better then update answer;
        if(mean - v[guess] > ans){
            ans = mean - v[guess];
            optGuess = guess;
            optK = L;
        }

  }

//  print answer
cout<<optK*2 + 1<<endl;

for(int i =0; i<optK; i++){
    cout<<v[n-i-1]<<" ";
} 
// for(int i =0; i<optK+1; i++){
//     cout<<v[optGuess-i]<<" ";
// }




    return 0;
}