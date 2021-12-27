/*
 * @lc app=leetcode.cn id=5953 lang=cpp
 *
 * [5953] 子数组范围和
 */

// @lc code=start
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int max = 0x80000000;
        int min = 0x7fffffff;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
            
        }
    }
};
// @lc code=end

