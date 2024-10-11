#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, X;
        cin >> N >> X;

        vector<int> heights(2 * N);
        for (int i = 0; i < 2 * N; ++i)
        {
            cin >> heights[i];
        }

        sort(heights.begin(), heights.end());

        bool possible = true;
        for (int i = 0; i < N; ++i)
        {
            if (heights[i + N] - heights[i] < X)
            {
                possible = false;
                break;
            }
        }

       
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
