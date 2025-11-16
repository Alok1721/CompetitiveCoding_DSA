#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NEG = -1000000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        int H;
        cin >> H;

        vector<vector<char>> grid(H+1, vector<char>(5+1));
        // grid[1..H][1..5]
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= 5; j++){
                cin >> grid[i][j];
            }
        }

        // dp[row][col][k][used]
        // Initialize all to NEG
        static int dp[1002][6][2][6];
        // dimensions: row, col, used, k
        // But to simplify indexing, we will use dp[row][col][used][k]

        // Reset dp
        for(int r = 0; r <= H+1; r++)
            for(int c = 1; c <= 5; c++)
                for(int used = 0; used < 2; used++)
                    for(int k = 0; k <= 5; k++)
                        dp[r][used][k][c] = NEG;

        // Start at row H+1, col 3, no kadha used, k=0
        dp[H+1][0][0][3] = 0;

        // Process rows from H+1 down to 2 -> next row is r-1
        for(int r = H+1; r >= 2; r--){
            for(int used = 0; used < 2; used++){
                for(int k = 0; k <= 5; k++){
                    for(int c = 1; c <= 5; c++){
                        if(dp[r][used][k][c] < 0) continue;

                        int cur = dp[r][used][k][c];

                        // Possible next columns
                        for(int dc = -1; dc <= 1; dc++){
                            int nc = c + dc;
                            if(nc < 1 || nc > 5) continue;

                            char cell = grid[r-1][nc];

                            // Two choices: do not take Kadha OR take Kadha (if not used)
                            // 1. Do not take Kadha
                            {
                                int nk = max(0, k - 1);
                                int nused = used;
                                int nf = cur;

                                if(cell == 'S') nf++;
                                else if(cell == 'R'){
                                    if(nk == 0){
                                        if(nf == 0) goto skip1;
                                        nf--;
                                    }
                                }
                                dp[r-1][nused][nk][nc] = max(dp[r-1][nused][nk][nc], nf);
                            }
                            skip1:;

                            // 2. Take Kadha now (if not already used)
                            if(used == 0){
                                int nk = 5; // fresh effect
                                int nused = 1;
                                int nf = cur;

                                if(cell == 'S') nf++;
                                else if(cell == 'R'){
                                    // protected, no fruit needed
                                }
                                dp[r-1][nused][nk][nc] = max(dp[r-1][nused][nk][nc], nf);
                            }
                        }
                    }
                }
            }
        }

        // Find best result at row 1 for any col, any kadha state
        int ans = NEG;
        for(int used = 0; used < 2; used++){
            for(int k = 0; k <= 5; k++){
                for(int c = 1; c <= 5; c++){
                    ans = max(ans, dp[1][used][k][c]);
                }
            }
        }

        cout << "Case #" << tc << "\n";
        if(ans < 0) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}
