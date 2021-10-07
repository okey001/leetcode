/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(n);
        for(auto &&i: f) i.resize(m);
        f[0][0] = 1;
        for(int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (i == 0 || j == 0)f[i][j] = 1;
                else{
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        return f[n-1][m-1];
        
    }
};
// @lc code=end

