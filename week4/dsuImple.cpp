#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> parent;
vector<int> ranks;
void Unionfind(int n)
{
    parent.resize(n);
    ranks.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}
int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);
    if (x_parent == y_parent)
    {
        return;
    }
    if (ranks[x_parent] > ranks[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else if (ranks[x_parent] < ranks[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else
    {
        parent[x_parent] = y_parent;
        ranks[y_parent]++;
    }
}

bool isSameSet(int x, int y)
{
    return find(x) == find(y);
}
int main()
{
    int n, m;
    cin >> n >> m;
    Unionfind(n+1);
    while (m--)
    {
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;

        if (s == "union")
        {
            Union(x, y);
        }
        else
        {
            if (isSameSet(x, y))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}