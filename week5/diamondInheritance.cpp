#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

// DFS to find paths from current node to all its ancestors
void dfs(int node, const vector<vector<int>>& graph, vector<int>& visited, unordered_map<int, int>& pathCount) {
    visited[node] = 1;

    for (int parent : graph[node]) {
        pathCount[parent]++; // Count the path to this ancestor
        if (!visited[parent]) {
            dfs(parent, graph, visited, pathCount);
        }
    }
}

bool hasDiamondInheritance(int N, const vector<vector<int>>& graph) {
    for (int i = 1; i <= N; ++i) {
        vector<int> visited(N + 1, 0);
        unordered_map<int, int> pathCount;

        // Perform DFS to count paths to ancestors
        dfs(i, graph, visited, pathCount);

        // Check if any ancestor has more than one path
        for (const auto& entry : pathCount) {
            if (entry.second > 1) {
                return true; // Found diamond inheritance
            }
        }
    }
    return false; // No diamond inheritance found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // Number of test cases
    cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int N; // Number of classes
        cin >> N;

        vector<vector<int>> graph(N + 1); // Inheritance graph (1-indexed)

        // Read the inheritance relationships
        for (int i = 1; i <= N; ++i) {
            int M; // Number of classes this class inherits from
            cin >> M;

            for (int j = 0; j < M; ++j) {
                int parentClass;
                cin >> parentClass;
                graph[i].push_back(parentClass); // Store the inheritance relationship
            }
        }

        // Check for diamond inheritance
        bool diamond = hasDiamondInheritance(N, graph);

        // Output the result
        cout << "Case #" << caseNum << ": " << (diamond ? "Yes" : "No") << '\n';
    }

    return 0;
}
