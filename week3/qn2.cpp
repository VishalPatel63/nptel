#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to determine the winner based on who starts first
string determine_winner(vector<int>& a, vector<int>& b, bool ankita_first) {
    int last_card = -1; // The last card played
    while (true) {
        vector<int>& current_cards = ankita_first ? a : b;
        vector<int>& opponent_cards = ankita_first ? b : a;

        // Find the first valid card that can be played
        bool can_play = false;
        for (int card : current_cards) {
            if (card > last_card) {
                last_card = card; // Play this card
                can_play = true;  // Current player can play
                break;
            }
        }

        if (!can_play) {
            // Current player cannot play, opponent wins
            return ankita_first ? "Biswas" : "Ankita"; // Return the winner
        }

        // Switch turns
        ankita_first = !ankita_first;
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, m;
        cin >> n; // Number of cards Ankita has
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Ankita's cards
        }
        cin >> m; // Number of cards Biswas has
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i]; // Biswas's cards
        }

        // Sort both players' cards
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Determine winners based on who starts first
        string winner_if_ankita_first = determine_winner(a, b, true);
        string winner_if_biswas_first = determine_winner(a, b, false);

        cout << winner_if_ankita_first << "\n" << winner_if_biswas_first << "\n";
    }
    return 0;
}
