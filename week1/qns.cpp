#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long maxScore(int n){
    if(n == 1){
        return 0;
    }
    priority_queue<int> pq;
    pq.push(n);
    ll totalScore = 0;
    while(!pq.empty()){
        int curr = pq.top();
        pq.pop();

        if(curr == 1){
            break;
        }

        ll a = curr/2;
        ll b = curr - a;
        totalScore += a*b;
        pq.push(a);
        pq.push(b);
    }

return totalScore;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        cout<<maxScore(n)<<endl;
    }
    return 0;
}


