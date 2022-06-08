/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = curMax;
        for(int  i = 1; i < n; i ++){
            int a, b;
            a = curMax * nums[i];
            b = curMin * nums[i];
            curMax = nums[i];
            if(a > curMax) curMax = a;
            if(b > curMax) curMax = b;
            if(curMax > ans) ans = curMax;

            curMin = nums[i];
            if(a < curMin) curMin = a;
            if(b < curMin) curMin = b;
        }
        return ans;
    }
};
// @lc code=end

