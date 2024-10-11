#include<bits/stdc++.h>
using namespace std;
void  troubleSort(vector<int>&arr){
    bool done = false;

    while(!done){
        done = true;
        for(int i =0; i<arr.size()-2; i++){
            if(arr[i] > arr[i+2]){
                swap(arr[i],arr[i+2]);
                done = false;
            }
        }
    }
}
int main()
{
    vector<int> arr = {5,6,6,4,3};
    // vector<int> arr = {5,6,5,4,3};
        troubleSort(arr);

        bool sorted = true;
        for(int i =0; i<arr.size()-1; i++){
            if(arr[i] > arr[i+1]){
                sorted = false;
                cout<<"index: "<<i<<endl;
                break;
            }
        }

        if(sorted){
            cout<<"sorted ho gaya hai"<<endl;
        }
        else{
            cout<<"sort nahi hua"<<endl;
        }
    return 0;
}


// complexcity = O(n^2);  this method complexcity is O(n^2) so solve another approach


// solving using drying board

















// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits>

// using namespace std;

// const int INF = numeric_limits<int>::max(); // Infinite distance

// // Modified Dijkstra's Algorithm (ignores negative weights)
// void dijkstra(int source, vector<vector<pair<int, int>>>& adjList, vector<int>& dist) {
//     int n = adjList.size();
//     dist.assign(n, INF);
//     dist[source] = 0;
    
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     pq.push({0, source});
    
//     while (!pq.empty()) {
//         int currentDist = pq.top().first;
//         int currentNode = pq.top().second;
//         pq.pop();
        
//         if (currentDist > dist[currentNode]) continue;
        
//         for (auto& neighbor : adjList[currentNode]) {
//             int nextNode = neighbor.first;
//             int weight = neighbor.second;

//             // Skip negative weights (Not ideal for a real-world solution)
//             if (weight < 0) {
//                 cout << "Negative edge detected: Ignoring edge " << currentNode << " -> " << nextNode << " with weight " << weight << endl;
//                 continue;
//             }
            
//             if (dist[currentNode] + weight < dist[nextNode]) {
//                 dist[nextNode] = dist[currentNode] + weight;
//                 pq.push({dist[nextNode], nextNode});
//             }
//         }
//     }
// }

// int main() {
//     int n = 5; // Number of vertices
//     vector<vector<pair<int, int>>> adjList(n);
    
//     // Input edges: {u, v, w}
//     vector<vector<int>> edges = {{0, 1, 1}, {0, 2, 10}, {1, 3, 2}, {2, 3, -10}, {3, 4, 3}};
    
//     // Construct adjacency list
//     for (const auto& edge : edges) {
//         int u = edge[0];
//         int v = edge[1];
//         int w = edge[2];
//         adjList[u].push_back({v, w});
//     }
    
//     int source = 0;
//     vector<int> dist;
//     dijkstra(source, adjList, dist);
    
//     // Output the shortest distances
//     cout << "Shortest distances from source node " << source << ":\n";
//     for (int i = 0; i < n; i++) {
//         if (dist[i] == INF) {
//             cout << "Node " << i << ": Unreachable\n";
//         } else {
//             cout << "Node " << i << ": " << dist[i] << "\n";
//         }
//     }

//     return 0;
// }

