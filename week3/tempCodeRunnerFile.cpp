#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> stops(n);
        unordered_map<int,pair<int,int>> stopIndices;
        for(int i =0; i<n; i++){
            cin>>stops[i];
           
        }

        for(int i =0; i<n; i++){
             if(stopIndices.find(stops[i]) == stopIndices.end()){
                stopIndices[stops[i]] = {i,i};                   //make_pair(i,i);
            }
            else{
                stopIndices[stops[i]].second = i;
            }
        }

        int validCount = 0;
        for(int i =0; i<q; i++){
            int si, sj;
            cin>>si>>sj;

            if(stopIndices.find(si) != stopIndices.end() &&  stopIndices.find(sj) != stopIndices.end()){
                 int lastIndexSi = stopIndices[si].second;

                 for(int index = lastIndexSi+1 ; index<n; i++){
                    if(stops[index] == sj){
                        validCount++;
                        break;
                    }
                 }
            }
        }

        cout<<validCount<<endl;
    }
    return 0;
}