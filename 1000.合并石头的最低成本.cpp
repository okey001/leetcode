/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if(!n || k != 2 && n % (k - 1) != 1) return -1;
        vector<int> sum(n + 1);
        for(int i = 1; i <= n; i ++) sum[i] = sum [i - 1] + stones[i - 1];
        vector<vector<int>> dp(n);
        for(auto&& v: dp) { 
            v.resize(n);
        }
        for(int len = 1; len <= n; len ++){
            for(int i = 0; i < n - len + 1; i ++){
                int j = i + len - 1;
                if(len == 1){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = 0x7fffffff;
                for(int m = i; m < j; m += k - 1){
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                if ((len - 1) % (k - 1) == 0) dp[i][j] += sum[j + 1] - sum[i];
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

