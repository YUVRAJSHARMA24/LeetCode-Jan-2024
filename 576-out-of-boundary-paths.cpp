class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> direction{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int solve(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return 1;

        if(maxMove <= 0) return 0;

        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];

        int res = 0;
        for(auto &dir : direction)
        {
            int new_row = i + dir[0];
            int new_col = j + dir[1];

            res = (res + solve(m, n, maxMove-1, new_row, new_col, dp)) % mod;
        }

        return dp[i][j][maxMove] = res;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};
