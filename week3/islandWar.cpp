#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> request;
    for(int i =0; i< m; i++){
        int a, b;
        cin>>a>>b;
        request.push_back(make_pair(a,b));
    }

    // sort the request on the bais of right end point(last element);
      sort(request.begin(),request.end(), comp);
    cout<<"print"<<endl;
      for(int i =0; i<m; i++){
        cout<<request[i].first <<" "<<request[i].second<<endl;
      }

    //   then compare first last point to another bridge first point 
    // if lastPoint > first point of another request then continue
    //  else lastpoint equal = another reuest ke second point koi point karega 
    //  ans++ kr denge
     int ans = 0;
     int lastBridge = -1;
      for(auto req: request){
        if(lastBridge  > req.first){
            continue;
        }
        else{
            lastBridge = req.second;
            cout<<"lastBridge - >"<<lastBridge<<endl;
            ans++;
        }
      }
  
  cout<<ans<<endl;
    return 0;
}