
#include<bits/stdc++.h>
#define ll long long;
using namespace std;
long long minimalDays(int x1, int y1, int x2, int y2, int n, string & s) {

    int dx = 0, dy = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') dy++;
        else if (s[i] == 'D') dy--;
        else if (s[i] == 'L') dx--;
        else if (s[i] == 'R') dx++;
    }
    long long left = 0, right = 1e18;
    while (left < right) {
        long long mid = (left + right) / 2;

     
        long long fullCycles = mid / n;
        long long remDays = mid % n;

        
        long long curX = x1 + fullCycles * dx;
        long long curY = y1 + fullCycles * dy;
        for (int i = 0; i < remDays; ++i) {
            if (s[i] == 'U') curY++;
            else if (s[i] == 'D') curY--;
            else if (s[i] == 'L') curX--;
            else if (s[i] == 'R') curX++;
        }

        
        long long dist = abs(x2 - curX) + abs(y2 - curY);

       
        if (dist <= mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    
    long long fullCycles = left / n;
    long long remDays = left % n;

    long long finalX = x1 + fullCycles * dx;
    long long finalY = y1 + fullCycles * dy;

    for (int i = 0; i < remDays; ++i) {
        if (s[i] == 'U') finalY++;
        else if (s[i] == 'D') finalY--;
        else if (s[i] == 'L') finalX--;
        else if (s[i] == 'R') finalX++;
    }

    long long finalDist = abs(x2 - finalX) + abs(y2 - finalY);

    if (finalDist <= left) {
        return left;
    } else {
        return -1;
    }
}

int main() {
    int x1, y1, x2, y2, n;
    cin >>x1>>y1>>x2>> y2;
    cin>>n;
    string s;
    cin>>s;

    cout << minimalDays(x1,y1,x2,y2,n,s) << endl;

    return 0;
}