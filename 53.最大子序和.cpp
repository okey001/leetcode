/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size(), 0);
        f[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        }
        int ans = 0x80000000;
        for (int i = 0; i < nums.size(); i++) {
            if (f[i] > ans) ans = f[i];
        }
        return ans;
    }
};
// @lc code=end

