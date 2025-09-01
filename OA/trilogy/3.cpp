#include <bits/stdc++.h>
using namespace std;

struct State {
    vector<string> grid;
    int moves;
};

bool isFilled(const vector<string>& g) {
    for (int i = 0; i < (int)g.size(); i++)
        if (g[i][0] != '#') return false;
    return true;
}

vector<string> drop(vector<string> g, int row) {
    int n = g.size(), m = g[0].size();
    
    // If the starting position is already occupied, this move is invalid
    if (g[row][0] == '#') return g;
    
    int r = row, c = 0;
    
    // First, place the block at the leftmost position
    g[r][c] = '#';
    
    // Then simulate the physics:
    // 1. Move right as far as possible
    while (c + 1 < m && g[r][c + 1] == '.') {
        g[r][c] = '.';  // Remove from current position
        c++;
        g[r][c] = '#';  // Place at new position
    }
    
    // 2. Fall down as far as possible
    while (r + 1 < n && g[r + 1][c] == '.') {
        g[r][c] = '.';  // Remove from current position
        r++;
        g[r][c] = '#';  // Place at new position
    }
    
    return g;
}

// BFS to find minimum moves
int minMoves(vector<string> start) {
    queue<State> q;
    set<vector<string>> seen;
    q.push({start, 0});
    seen.insert(start);
    
    while (!q.empty()) {
        auto [grid, moves] = q.front(); 
        q.pop();
        
        if (isFilled(grid)) return moves;
        
        int n = grid.size();
        for (int r = 0; r < n; r++) {
            // Only try to drop if the starting position is empty
            if (grid[r][0] == '.') {
                auto next = drop(grid, r);
                if (!seen.count(next)) {
                    seen.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }
    }
    return -1; // should never happen
}

// DFS to find maximum moves
int maxMoves(vector<string> start) {
    int best = 0;
    set<vector<string>> seen;
    
    function<void(vector<string>,int)> dfs = [&](vector<string> g, int moves) {
        if (isFilled(g)) {
            best = max(best, moves);
            return;
        }
        
        int n = g.size();
        for (int r = 0; r < n; r++) {
            // Only try to drop if the starting position is empty
            if (g[r][0] == '.') {
                auto next = drop(g, r);
                if (!seen.count(next)) {
                    seen.insert(next);
                    dfs(next, moves + 1);
                    seen.erase(next);
                }
            }
        }
    };
    
    dfs(start, 0);
    return best;
}

pair<int,int> solve(vector<string> board) {
    return {minMoves(board), maxMoves(board)};
}

int main() {
    vector<string> board1 = {
        "...#..#..."
    };
    
    auto [mn, mx] = solve(board1);
    cout << "Minimum moves: " << mn << "\n";
    cout << "Maximum moves: " << mx << "\n";
    
    return 0;
}