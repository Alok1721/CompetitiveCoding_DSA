#include <bits/stdc++.h>
using namespace std;

struct Card {
    int value;
    int symbol;
    
    bool operator>(const Card& other) const {
        return value > other.value;
    }
};

long long calculatePoints(vector<Card>& cards, vector<int>& selected) {
    long long sumValues = 0;
    vector<int> symbolCount(4, 0);
    
    for (int idx : selected) {
        sumValues += cards[idx].value;
        symbolCount[cards[idx].symbol]++;
    }
    
    long long symbolBonus = 0;
    for (int count : symbolCount) {
        symbolBonus += (long long)count * count;
    }
    
    return sumValues + symbolBonus;
}

long long solveGreedy(vector<Card>& cards, int K) {
    int N = cards.size();
    
    // Strategy 1: Pure greedy - take top K cards by value
    vector<int> selected;
    for (int i = 0; i < K; i++) {
        selected.push_back(i);
    }
    long long maxPoints = calculatePoints(cards, selected);
    
    // Strategy 2: Symbol-focused approach
    // Group cards by symbol and try concentrated selections
    vector<vector<int>> symbolGroups(4);
    for (int i = 0; i < N; i++) {
        symbolGroups[cards[i].symbol].push_back(i);
    }
    
    // Try taking all cards from top symbols first
    for (int focusSymbols = 1; focusSymbols <= min(4, K); focusSymbols++) {
        // Create a priority queue of symbols by their top cards
        vector<pair<long long, int>> symbolValues;
        for (int s = 0; s < 4; s++) {
            if (!symbolGroups[s].empty()) {
                long long topSum = 0;
                int count = min(K, (int)symbolGroups[s].size());
                for (int i = 0; i < min(count, (int)symbolGroups[s].size()); i++) {
                    topSum += cards[symbolGroups[s][i]].value;
                }
                symbolValues.push_back({topSum, s});
            }
        }
        sort(symbolValues.rbegin(), symbolValues.rend());
        
        selected.clear();
        int remaining = K;
        
        // Take cards from top 'focusSymbols' symbols
        for (int i = 0; i < min(focusSymbols, (int)symbolValues.size()) && remaining > 0; i++) {
            int sym = symbolValues[i].second;
            int take = min(remaining, (int)symbolGroups[sym].size());
            for (int j = 0; j < take; j++) {
                selected.push_back(symbolGroups[sym][j]);
            }
            remaining -= take;
        }
        
        // If we still need more cards, take best remaining
        if (remaining > 0) {
            set<int> usedSymbols;
            for (int i = 0; i < focusSymbols && i < symbolValues.size(); i++) {
                usedSymbols.insert(symbolValues[i].second);
            }
            
            vector<int> remainingCards;
            for (int i = 0; i < N; i++) {
                if (usedSymbols.find(cards[i].symbol) == usedSymbols.end()) {
                    remainingCards.push_back(i);
                }
            }
            
            for (int i = 0; i < min(remaining, (int)remainingCards.size()); i++) {
                selected.push_back(remainingCards[i]);
            }
        }
        
        if (selected.size() == K) {
            maxPoints = max(maxPoints, calculatePoints(cards, selected));
        }
    }
    
    // Strategy 3: Mixed approach - balance value and concentration
    // For each symbol, calculate value per card including bonus
    for (int mainSymbol = 0; mainSymbol < 4; mainSymbol++) {
        if (symbolGroups[mainSymbol].empty()) continue;
        
        selected.clear();
        int taken = min(K, (int)symbolGroups[mainSymbol].size());
        
        // Take top cards from main symbol
        for (int i = 0; i < taken; i++) {
            selected.push_back(symbolGroups[mainSymbol][i]);
        }
        
        // Fill remaining with best cards from other symbols
        if (taken < K) {
            vector<int> others;
            for (int i = 0; i < N; i++) {
                if (cards[i].symbol != mainSymbol) {
                    others.push_back(i);
                }
            }
            
            for (int i = 0; i < min(K - taken, (int)others.size()); i++) {
                selected.push_back(others[i]);
            }
        }
        
        if (selected.size() == K) {
            maxPoints = max(maxPoints, calculatePoints(cards, selected));
        }
    }
    
    return maxPoints;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<Card> cards(N);
    
    for (int i = 0; i < N; i++) {
        cin >> cards[i].symbol;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> cards[i].value;
    }
    
    // Sort by value descending
    sort(cards.begin(), cards.end(), greater<Card>());
    
    long long result = solveGreedy(cards, K);
    
    cout << result << endl;
    
    return 0;
}