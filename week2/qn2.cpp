#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i =0; i<n; i++){
            cin>>v[i];
        }
      sort(v.rbegin() , v.rend());

      vector<long long> prefix(n);
      prefix[0] = v[0];
      for(int i =1; i<n; i++){
        prefix[i] = prefix[i-1] + v[i];  
      }


      for(int i =0; i<q; i++){
        long long x;
        cin>>x;
         int left = 0;
         int right = n-1;
         int ans = -1;
         while(left <= right){
            int mid = left  + (right - left)/2;
            if(prefix[mid] >= x){
                ans = mid-1;
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
         }
      cout<<ans<<endl;
      }

    }
    return 0;
}