/*
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. You want to pick up the jewels after getting into the maze through the entrance and before getting out of it through the exit. You want to get as many jewels as possible, but you don’t want to take the same passage you used once.

When locations of a maze and jewels are given, find out the greatest number of jewels you can get without taking the same passage twice, and the path taken in this case.

Input
There can be more than one test case in the input file. The first line has T, the number of test cases. Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. The maze is N×N square-shaped. From the second line through N lines, information of the maze is given. “0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located on the upper-most left passage and the exit is located on the lower-most right passage. There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the greatest number of jewels that can be picked up. Each test case must be output separately as a empty.

MAX DIAMONDS COLLECTED AND ITS PATH IS THE OUTPUT.

*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int maxJewel;
vector<vector<int>> ans;
vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

bool isValid(vector<vector<int>>& mat, int x, int y, vector<vector<int>>& path) {
    return x>=0 && y>=0 && x<m && y<n && (mat[x][y]==0 || mat[x][y]==2) && path[x][y]==0;
}

void dfs(vector<vector<int>>& mat, vector<vector<int>>& path, int x, int y, int jewel) {
    if (x==m-1 && y==n-1) {
        if (jewel > maxJewel) {
            maxJewel = jewel;
            ans = path;
        }
        return;
    }

    for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (isValid(mat, nx, ny, path)) {
            path[nx][ny] = 3;
            dfs(mat, path, nx, ny, jewel + (mat[nx][ny]==2));
            path[nx][ny] = 0; // backtrack path
        }
    }
}

int main() {
    cin >> n;
    m = n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> path = mat;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            path[i][j] = 0;

    path[0][0] = 3;
    maxJewel = -1;
    dfs(mat, path, 0, 0, (mat[0][0]==2));

    cout << maxJewel << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ans[i][j]==3) cout << "3 ";
            else cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
