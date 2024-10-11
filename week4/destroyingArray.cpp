#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> parent;
vector<int> ranks;
vector<int> setSize;
int numSets;
vector<long long> sumSet;
void Unionfind(int n)
{
    parent.resize(n);
    ranks.resize(n);
    setSize.resize(n);
    sumSet.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
        setSize[i] = 0;
        sumSet[i] = 0;

    }
    numSets = 0;
}

void makeSet(int x, int y){
    parent[x] = x;
    ranks[x] = 0;
    setSize[x] = 1;
    sumSet[x] = y;
    numSets += 1;
}
int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

int sizeOfSet(int x){
    return setSize[find(x)];
}
int numDisjointSets(){
    return numSets;
}
long long sumOfSet(int i){
   return sumSet[find(i)];
}
bool isSameSet(int x, int y)
{
    return find(x) == find(y);
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
        setSize[x_parent] += setSize[y_parent];
        sumSet[x_parent] += sumSet[y_parent];
    }
    else if (ranks[x_parent] < ranks[y_parent])
    {
        parent[x_parent] = y_parent;
        setSize[y_parent] += setSize[x_parent];
        sumSet[y_parent] += sumSet[x_parent];

      
    }
    else
    {
        parent[x_parent] = y_parent;
        ranks[y_parent]++;
        setSize[y_parent] += setSize[x_parent];
        sumSet[y_parent] += sumSet[x_parent];
    }
      numSets--;
}



int main()
{
    
    int n;
    cin>>n;
    vector<int> arr(n+1, 0);
    vector<int> state(n+1, 0);
    vector<int> seq(n);
    for(int i =1; i<=n; i++){
        cin>>arr[i];
    }
   
   for(int i = 0; i<n; i++){
      cin>>seq[i];
   }

   Unionfind(n+1);

   reverse(seq.begin(),seq.end());

    vector<long long > ans;
    ans.push_back(0);
    long long currAns = 0;
    for(auto x: seq){
        int idx = x;
       state[idx] = 1;

       makeSet(idx,arr[idx]);

       if(idx-1 > 0 && state[idx-1]){
        Union(idx-1,idx);
       }
       if(idx+1 <= n && state[idx+1]){
        Union(idx,idx +1);     
       }

       currAns = max(currAns,sumOfSet(idx));
       ans.push_back(currAns);

      
    }

    ans.pop_back();
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<endl;
    }
    
    return 0;
}

// 4
// 1 3 2 5
// 3 4 1 2
// 5
// 4
// 3
// 0

