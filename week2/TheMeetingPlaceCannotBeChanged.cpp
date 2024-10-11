
#include<bits/stdc++.h>
using namespace std;

bool canMeet(double t, const vector<int>& x, const vector<int>& v, int n) {
    double left = -1e18, right = 1e18;
    

    for (int i = 0; i < n; ++i) {
        double minPos = x[i] - v[i] * t;
        double maxPos = x[i] + v[i] * t;
        

        left = max(left, minPos);
        right = min(right, maxPos);
    }
    
    return left <= right;
}

int main() {
    int n;
    cin >> n;

    vector<int> x(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    } 
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    double low = 0, high = 1e9;
    while (high - low > 1e-7) {
        double mid = (low + high) / 2;
        if (canMeet(mid, x, v, n)) {
            high = mid;
        } else {
            low = mid;
        }
    }


    cout << fixed << setprecision(9) << low << endl;

    return 0;
}