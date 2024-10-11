// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
 
//     int t;
//     cin>>t;
//     while(t--){
//         int n,q;
//         cin>>n>>q;
//         vector<int> stops(n);
//         unordered_map<int,pair<int,int>> stopIndices;
//         for(int i =0; i<n; i++){
//             cin>>stops[i];
           
//         }

//         for(int i =0; i<n; i++){
//              if(stopIndices.find(stops[i]) == stopIndices.end()){
//                 stopIndices[stops[i]] = {i,i};                   //make_pair(i,i);
//             }
//             else{
//                 stopIndices[stops[i]].second = i;
//             }
//         }

//         int validCount = 0;
//         for(int i =0; i<q; i++){
//             int si, sj;
//             cin>>si>>sj;

//             if(stopIndices.find(si) != stopIndices.end() &&  stopIndices.find(sj) != stopIndices.end()){
//                  int lastIndexSi = stopIndices[si].second;

//                  for(int index = lastIndexSi+1 ; index<n; i++){
//                     if(stops[index] == sj){
//                         validCount++;
//                         // break;
//                     }
//                  }
//             }
//             // cout<<"fgfdsjfhdsg";
//         }
//         cout<<validCount<<endl;

//     }
//     return 0;
// }






#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N, Q;
        cin >> N >> Q; // Number of stops and queries
        vector<int> stops(N);
        unordered_map<int, vector<int>> stopIndices; // {stop: indices}

        // Read the stops and populate the map with occurrences
        for (int i = 0; i < N; ++i) {
            cin >> stops[i];
            stopIndices[stops[i]].push_back(i); // Store all indices of each stop
        }

        int validCount = 0;

        // Process each query
        for (int i = 0; i < Q; ++i) {
            int si, sj;
            cin >> si >> sj;

            // Check if both stops exist
            if (stopIndices.find(si) != stopIndices.end() && stopIndices.find(sj) != stopIndices.end()) {
                // Get the last occurrence of si
                const auto& indicesSi = stopIndices[si];
                int lastIndexSi = indicesSi.back(); // Last index of si

                // Binary search for sj in the indices of sj that come after lastIndexSi
                const auto& indicesSj = stopIndices[sj];
                int lastIndexSj = indicesSj.back();
                // auto it = upper_bound(indicesSj.begin(), indicesSj.end(), lastIndexSi);
               
                if (lastIndexSj > lastIndexSi ) {
                    validCount++; // We found sj after si
                   
                }
            }
        }

        cout << validCount << "\n"; // Output the result for this test case
    }

    return 0;
}







