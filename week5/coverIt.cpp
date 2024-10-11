#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
void bfs(int s,vector<vector<int>> & g,int n,vector<int> &d) {
	
	d[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (auto v : g[u]) {
			if (d[v] == INF) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {

	
	int t;
	cin >> t;
	
	  while(t--){
        int n,m;
		cin >> n >> m;
		vector<vector<int>> g(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	   vector<int> d(n, INF);
		bfs(0 ,g,n,d);
		vector<int> even, odd;
		for (int i = 0; i < n; ++i) {
			if (d[i] & 1) odd.push_back(i);
			else even.push_back(i);
		}
	
		if (even.size() < odd.size()) {
			cout << even.size() << endl;
			for (auto v : even) cout << v + 1 << " ";
		} else {
			cout << odd.size() << endl;
			for (auto v : odd) cout << v + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}

