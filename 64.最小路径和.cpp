/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> f(n);
        for (auto&& i : f) i.resize(m);
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (i + j == 0) f[i][j] =grid[i][j];
                else {
                    f[i][j] = 0x7fffffff;
                    if (i > 0 && f[i - 1][j] + grid[i][j] < f[i][j])
                        f[i][j] = f[i - 1][j] + grid[i][j];
                    if (j > 0 && f[i][j - 1] + grid[i][j] < f[i][j])
                        f[i][j] = f[i][j - 1] + grid[i][j];
                }
            }
            
        }
        return f[n-1][m-1];
    }
};
// @lc code=end

