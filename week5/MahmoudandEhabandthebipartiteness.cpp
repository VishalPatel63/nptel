

// bipartite graph problem
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

   unordered_map<long long,vector<long long>> adj;
    for (int i = 0; i < n - 1; i++) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> color(n + 1, -1); 
    int countA = 0, countB = 0;

  
    queue<long long> q;
    color[1] = 0; 
    countA++;

    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node]; 
                if (color[neighbor] == 0) {
                    countA++;
                } else {
                    countB++;
                }
                q.push(neighbor);
            }
        }
    }
     long long maxEdges = static_cast<long long>(countA) * countB;
    long long existingEdges = n - 1;
    long long newEdges = maxEdges - existingEdges;
    cout << newEdges << endl;

    return 0;
}



// https://codeforces.com/problemset/problem/862/B