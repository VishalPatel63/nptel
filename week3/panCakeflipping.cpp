
// // greddy approach,   sliding window similar

#include <iostream>
#include <string>
using namespace std;
string solve(string S, int K) {
    int flips = 0;
    int n = S.size();

    for (int i = 0; i <= n - K; i++) {
    
        if (S[i] == '-') {
           
            flips++;
            for (int j = 0; j < K; j++) {
            
                S[i + j] = (S[i + j] == '-') ? '+' : '-';
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (S[i] == '-') {
            return "IMPOSSIBLE";
        }
    }

    
    return to_string(flips);
}

int main() {
    int T;
    cin >> T;  
    for (int t = 1; t <= T; t++) {
        string S;
        int K;
        cin >> S >> K; 
        string result = solve(S, K);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
